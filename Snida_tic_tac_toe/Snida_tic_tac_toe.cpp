#include <iostream>
#include "Header.h"

int main()
{   
    setlocale(LC_ALL, "russian");
    // требуемые переменные
    int M = 0, N = 0, row = 0, col = 0;
    short int padding = 6;
    int f = 0;
    unsigned int start_time = clock(); // начальное время
    // вызовы функций
    int** matrix = buildMatrix("3_hard_in_row.txt", padding, M, N);// потсроение матрицы
    MoveController(matrix, padding, M, N, 2, row, col);// сама функция
    // вывод и фиксирование времени
    unsigned int end_time = clock(); // конечное время
    cout << "Ход: x-" << col << " y-" << row << endl;// координаты хода
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "search_time: " << search_time/1000. << endl;
}
