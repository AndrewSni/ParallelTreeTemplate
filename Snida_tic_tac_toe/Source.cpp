#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

using namespace std;

int** buildMatrix(string filename, int padding, int& M, int& N)
{
    ifstream fin("input.txt");
    if (!fin.is_open()) { exit(0); }
    cin.rdbuf(fin.rdbuf());


    cin >> M >> N;
    int** matrix;
    matrix = new int* [N + padding * 2];
    for (int i = 0; i < (N + padding * 2); i++) {
        matrix[i] = new int[M + padding * 2];
        for (int j = 0; j < M + padding * 2; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = padding; i < M + padding; i++) {
        for (int j = padding; j < N + padding; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
        
void MoveController(int** matrix, int padding, int M, int N, int tac_toe, int &row, int &col) {
    for (int i = padding / 2; i < M + padding * 2 - padding / 2; i++)
    {
        for (int j = padding / 2; j < N + padding * 2 - padding / 2; j++)
        {
            if (matrix[i][j] == 0)
            {
                row = i - padding / 2;
                col = j - padding / 2;
                matrix[i][j] = tac_toe;
                if (fiveInRow(matrix, padding, 2, i, j))
                {
                    matrix[i][j] = 9;
                    for (int s = padding / 2; s < N + padding * 2 - padding / 2; s++) {
                        for (int ss = padding / 2; ss < M + padding * 2 - padding / 2; ss++) {
                            cout << matrix[s][ss] << " ";
                        }
                        cout << endl;
                    }                   
                    return;
                }
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = padding/2; i < M + padding * 2 - padding / 2; i++)
    {
        for (int j = padding/2; j < N + padding * 2 - padding / 2; j++)
        {
            if (matrix[i][j] == 0) 
            {
                row = i - padding/2;
                col = j - padding/2;
                matrix[i][j] = tac_toe;
                
                if (fiveInRow(matrix, padding, 1, i, j))
                {
                    return;
                }
                if (isSecondMove(matrix, padding, M, N, i, j))
                {   
                    matrix[i][j] = 9;
                    for (int s = padding / 2; s < N + padding * 2- padding / 2; s++) {
                        for (int ss = padding / 2; ss < M + padding * 2- padding / 2; ss++) {
                           cout<< matrix[s][ss]<<" ";
                        }
                        cout << endl;
                    }
                    matrix[i][j] = 0;
                    return;
                }
                matrix[i][j] = 0;             
            }
        }
    }

    return;
}
bool canIWin(int** matrix, int tac_toe, int row, int col,int shift_row, int shift_col)
{
    int counter_of_figures = 1;
    int d_col = col + shift_col, d_row = row + shift_row;
    while (matrix[d_row][d_col] == tac_toe)
    {
        counter_of_figures++;
        if (counter_of_figures == 5)
            return true;
        d_col += shift_col;
        d_row += shift_row;
    }
    d_col =col - shift_col;
    d_row =row - shift_row;
    while (matrix[d_row][d_col] == tac_toe)
    {
        counter_of_figures++;
        if (counter_of_figures == 5)
            return true;
        d_col -= shift_col;
        d_row -= shift_row;
    }
    return false;
}
bool fiveInRow(int** matrix, int padding, int tac_toe,int row,int col) {
    //Block Горизонталь
    if(canIWin(matrix, tac_toe, row, col ,0 ,1))
    {
        return true;
    }

    //Block Вертикаль
    if (canIWin(matrix, tac_toe, row, col, 1, 0))
    {
        return true;
    }

    //Block Главная диагональ
    if (canIWin(matrix, tac_toe, row, col, 1, 1))
    {
        return true;
    }

    //Block Побочная диагональ
    if (canIWin(matrix, tac_toe, row, col, 1, -1))
    {
        return true;
    }
    return false;
}

bool isClosedRow(int** matrix, int row, int col,int shift_row, int shift_col) {

    int d_col = col + shift_col;
    int d_row = row + shift_row;
    while (matrix[d_row + shift_row][d_col+ shift_col] == 2)
    {
        d_col += shift_col;
        d_row += shift_row;
    }
    if (matrix[d_row][d_col] == 0) {
        d_col += shift_col;
        d_row += shift_row;
        while (matrix[d_row][d_col] == 2)
        {
            d_col += shift_col;
            d_row += shift_row;
        }
    } 
    d_col += shift_col;
    d_row += shift_row;
    if (matrix[d_row][d_col] == 1) {
        return true;
    }

    d_col = col - shift_col;
    d_row = row - shift_row;
    while (matrix[d_row - shift_row][d_col - shift_col] == 2)
    {
        d_col -= shift_col;
        d_row -= shift_row;
    }
    if (matrix[d_row][d_col] == 0) {
        d_col -= shift_col;
        d_row -= shift_row;
        while (matrix[d_row][d_col] == 2)
        {
            d_col -= shift_col;
            d_row -= shift_row;
        }
    }
    d_col -= shift_col;
    d_row -= shift_row;
    if (matrix[d_row ][d_col] == 1) {
        return true;
    }

    return false;
}

bool checkQuad(int** matrix, int row, int col, int shift_row, int shift_col, int &fourCounter)
{
    int counter_of_figures = 1;
    int counterRightF = 0, counterLeftF = 0;
    int d_col = col + shift_col, d_row = row+ shift_row;
    while (matrix[d_row][d_col] == 2)
    {
        counter_of_figures++;
        if (counter_of_figures == 4) {
            if (!isClosedRow(matrix, row, col, shift_row, shift_col)) {
                return true;
            }
        }
        d_col += shift_col;
        d_row += shift_row;
    }

    if (matrix[d_row][d_col] == 0) {
        d_col += shift_col;
        d_row += shift_row;
        while (matrix[d_row][d_col] == 2)
        {
            counterRightF++;
            d_col += shift_col;
            d_row += shift_row;
        }
    }
    d_col = col - shift_col;
    d_row = row - shift_row;
    while (matrix[d_row][d_col] == 2)
    {
        counter_of_figures++;
        if (counter_of_figures == 4) {
            if (!isClosedRow(matrix, row, col, shift_row, shift_col)) {
                return true;
            }
        }
        d_col -= shift_col;
        d_row -= shift_row;
    }

    if (matrix[d_row][d_col] == 0) {
        d_col -= shift_col;
        d_row -= shift_row;
        while (matrix[d_row][d_col] == 2)
        {
            counterLeftF++;
            d_col -= shift_col;
            d_row -= shift_row;
        }
    }

    if (!isClosedRow(matrix, row, col, shift_row, shift_col))
    {
        if (counter_of_figures + counterLeftF > 4)
        {
            return true;
        }
        if (counter_of_figures + counterRightF > 4)
        {
            return true;
        }
    }
    else {
        if (counter_of_figures + counterLeftF >= 4 and counter_of_figures < 4)
        {
            fourCounter++;
            if (fourCounter > 1)
            {
                return true;
            }
        }
        if (counter_of_figures + counterRightF >= 4 and counter_of_figures < 4)
        {
            fourCounter++;
            if (fourCounter > 1)
            {
                return true;
            }
        }
    }

    return false;
}

bool isSecondMove(int** matrix, int padding, int M, int N, int row, int col) {
    int fourCounter = 0;
    int counter_of_figures = 1;
    int counterRightF = 0, counterLeftF = 0;
    int d_col = col, d_row = row;
    //cout << "Block Горизонталь------------------------------------------------- " << endl;
    if (checkQuad(matrix, row, col, 0, 1, fourCounter))
    {
        return true;
    }
    
    //cout << "Block Вертикаль---------------------------------------------------- " << endl;
    if (checkQuad(matrix, row, col, 1, 0, fourCounter))
    {
        return true;
    }

    //cout << "Block Главная диагональ---------------------------------------------" << endl;
    if (checkQuad(matrix, row, col, 1, 1, fourCounter))
    {
        return true;
    }

    //cout << "Block Побочная диагональ---------------------------------------------" << endl;
    if (checkQuad(matrix, row, col, -1, 1, fourCounter))
    {
        return true;
    }
    return false;
}