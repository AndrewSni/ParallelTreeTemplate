#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

using namespace std;

int** buildMatrix(string filename, int padding, int &M, int &N);
void MoveController(int** matrix, int padding, int M, int N, int tac_toe, int &row, int &col);
bool fiveInRow(int** matrix, int padding, int tac_toe, int row, int col);
bool isSecondMove(int** matrix, int padding, int M, int N, int row, int col);
bool isClosedRow(int** matrix, int row, int col, int shift_row, int shift_col);

//bool read_matrix(string filename);