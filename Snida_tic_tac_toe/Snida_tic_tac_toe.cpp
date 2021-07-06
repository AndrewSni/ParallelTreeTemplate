#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{   
    setlocale(LC_ALL, "russian");
    int M = 0, N = 0, row = 0, col = 0;
    short int padding = 6;
    int f = 0;
    int** matrix = buildMatrix("input.txt", padding, M, N);
    MoveController(matrix, padding, M, N, 2, row, col);
    cout << "Ход: x-" << col << " y-" << row << endl;
     
}
