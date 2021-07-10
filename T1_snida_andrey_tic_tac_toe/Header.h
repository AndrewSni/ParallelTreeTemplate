#pragma once
#include <iostream>

using namespace std;

//построение матрицы
int** buildMatrix(std::string filename, int padding, int& M, int& N);
// функция вызовов
void MoveController(int** matrix, int padding, int M, int N, int tac_toe, int& row, int& col);
// пять в ряд
bool fiveInRow(int** matrix, int padding, int tac_toe, int row, int col, int& fourCounter, int& rowN, int& colN);
// победа в два хода
bool isSecondMove(int** matrix, int padding, int M, int N, int row, int col);
// проверка на закрытые паттерны
bool isClosedRow(int** matrix, int row, int col, int shift_row, int shift_col);