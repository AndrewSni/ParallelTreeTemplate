#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

//������ ������� �� �����. ������� ��������� � ������������ ���� �������
//������� �������� ����������� �������
//����� ��������� ������� � ��������� � ����������� ���������� �� �����
//input: filename - ��� �����, padding - ������� �������, M � N - ������ ���������� ��� ����������� �������
//output: matrix - ������� � ���������, M � N - ���������� ��� ����������� �������
int** buildMatrix(string filename, int padding, int& M, int& N)
{
    ifstream fin(filename);
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


//��������� ����� ������� ���������� � ��� �����:
// 1� ������ ����������� ������ ������ � 1 ��� ��� �
// 2� ������ ����������� ������ ������ � 1 ��� ��� �
// 3� ������ ����������� ������ ������ � 2 ���� ��� �
// input: matrix - ������� � ��������, padding - ������� �������, M � N - ���������� ��� ����������� �������
// tac_toe - �������� ������� ������, row  � col - ������� � ������� �������� ���� 
// output: row  � col - ������� ��������� ���� ��� ������ ������ ���� ������� ���� ������ ���� ���
void MoveController(int** matrix, int padding, int M, int N, int tac_toe, int& row, int& col) {
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
                    matrix[i][j] = 2;
                    for (int s = padding / 2; s < M + padding * 2 - padding / 2; s++)
                    {
                        for (int ss = padding / 2; ss < N + padding * 2 - padding / 2; ss++)
                        {
                            cout << matrix[s][ss];
                        }
                        cout << endl;
                    }
                    matrix[i][j] = 2;
                    return;
                }
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = padding / 2; i < M + padding * 2 - padding / 2; i++)
    {
        for (int j = padding / 2; j < N + padding * 2 - padding / 2; j++)
        {
            if (matrix[i][j] == 0)
            {
                row = i - padding / 2;
                col = j - padding / 2;
                matrix[i][j] = tac_toe;
                if (fiveInRow(matrix, padding, 1, i, j))
                {
                    return;
                }
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = padding / 2; i < M + padding * 2 - padding / 2; i++)
    {
        for (int j = padding / 2; j < N + padding * 2 - padding / 2; j++)
        {
            if (matrix[i][j] == 0)
            {
                row = i - padding / 2;
                col = j - padding / 2;
                matrix[i][j] = tac_toe;

                if (isSecondMove(matrix, padding, M, N, i, j))
                {
                    matrix[i][j] = 9;
                    for (int s = padding / 2; s < M + padding * 2 - padding / 2; s++)
                    {
                        for (int ss = padding / 2; ss < N + padding * 2 - padding / 2; ss++)
                        {
                            cout << matrix[s][ss]<<" ";
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

// ������� ��� �������� � ���� ��� ��� ����� ������
// ����������� ���� �� 4 ������ � ���
// input: matrix - ������� � ��������, shift_row � shift_col - ������������ �������� �� ������� �������
// tac_toe - �������� ������� ������, row  � col - ������� � ������� �������� ���� 
// output: bool ����� �� ��������
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

// �������� 4 � ��� �� ����������� � ��������� � �� ���� ����������
// input: matrix - ������� � ��������, padding - ������� �������
// tac_toe - �������� ������� ������, row  � col - ������� � ������� �������� ���� 
// output: bool ����� �� �������� � ���� ���
bool fiveInRow(int** matrix, int padding, int tac_toe,int row,int col) {
    //Block �����������
    if(canIWin(matrix, tac_toe, row, col ,0 ,1))
    {
        return true;
    }

    //Block ���������
    if (canIWin(matrix, tac_toe, row, col, 1, 0))
    {
        return true;
    }

    //Block ������� ���������
    if (canIWin(matrix, tac_toe, row, col, 1, 1))
    {
        return true;
    }

    //Block �������� ���������
    if (canIWin(matrix, tac_toe, row, col, 1, -1))
    {
        return true;
    }
    return false;
}


// �������� ��������� �� ����� � ����� ���� ������� ����� � ��������
// input: matrix - ������� � ��������, , shift_row � shift_col - ������������ �������� �� ������� �������
// tac_toe - �������� ������� ������, row  � col - ������� � ������� �������� ���� 
// output: bool ����� �� �������� � ���� ���
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

// �������� ���� �� �������� ������ � ��� 2 �������� ������ �� ����� ������ � ������ �������� (����������� ������ 1)
// input: matrix - ������� � ��������, , shift_row � shift_col - ������������ �������� �� ������� �������
// fourCounter - ����������� ��������(2 �������� ��� 1 �������� ����� 1 �� ����), row  � col - ������� � ������� �������� ���� 
// output: bool ���� �� �������� ��������������� ��������
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

    if (isClosedRow(matrix, row, col, shift_row, shift_col) and counterLeftF==0 and counterRightF==0)
    {
        if (counter_of_figures > 4)
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

// �������� ���� �� �������� ������ � ��� 2 �������� ������ �� ����� ������ � ������ �������� (����������� ������ 1)
// input: matrix - ������� � ��������, , shift_row � shift_col - ������������ �������� �� ������� �������
// padding - ������� �������, M � N - ���������� ��� ����������� �������, row  � col - ������� � ������� �������� ���� 
// output: bool ���� �� �������� ��������������� ��������
bool isSecondMove(int** matrix, int padding, int M, int N, int row, int col) {
    int fourCounter = 0;
    int counter_of_figures = 1;
    int counterRightF = 0, counterLeftF = 0;
    int d_col = col, d_row = row;
    //cout << "Block �����������------------------------------------------------- " << endl;
    if (checkQuad(matrix, row, col, 0, 1, fourCounter))
    {
        return true;
    }
    
    //cout << "Block ���������---------------------------------------------------- " << endl;
    if (checkQuad(matrix, row, col, 1, 0, fourCounter))
    {
        return true;
    }

    //cout << "Block ������� ���������---------------------------------------------" << endl;
    if (checkQuad(matrix, row, col, 1, 1, fourCounter))
    {
        return true;
    }

    //cout << "Block �������� ���������---------------------------------------------" << endl;
    if (checkQuad(matrix, row, col, -1, 1, fourCounter))
    {
        return true;
    }
    return false;
}