#include <iostream>
#include "Header.h"
#include <fstream>
#include <vector>
using namespace std;


// вектор векторов в котором храниятся координаты x y и крестик - 1 или нолик - 0
// данные берутся из из файлов
vector<vector<int>> read_matrix(string filename)
{
    ifstream fin("input.txt");
    if (!fin.is_open()) { cout << "Error!" << endl; }
    else
    {

        vector<vector<int>>  output;
        vector<int> temp{ 0,0,0 };
        int i = 0;
        while (!fin.eof())
        {   
            fin >> temp[0];
            fin >> temp[1];
            fin >> temp[2];
            output.push_back(temp);
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            for (int y = 0; y < 3; y++)
                cout << output[j][y];
            cout << endl;
        }
        return output;
    }
}

// создается матрица весов нужного размера весов исходя из величин вектора
container* create_mass_matrix(vector<vector<int>> input)
{
    int min_x = input[0][0], min_y = input[0][1], max_x = input[0][0], max_y = input[0][1];
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i][0] < min_x) min_x = input[i][0];
        if (input[i][1] < min_y) min_x = input[i][1];
        if (input[i][0] > max_x) max_x = input[i][0];
        if (input[i][1] > max_x) max_x = input[i][1];
    }
    int** matrix = new int* [(max_x - min_x+6) * (max_y - min_y+6)];// 6 это диаметр возможных вариантов хода каждого эллемента
    container* content = new container(matrix, min_x, min_y);
    return content;
}


// На вход идет текущая фигура: крестик/нолик
// создается матрица весов: чем больще пересечений по прямой и диагональной линии в радиусе 3х клеток от фигуры
// тем приоритетнее ход +1 в вес за пересечение
// при этом учитываются те случаи когда противоположные фигуры могут закончить раунд быстро то есть есть хоты бы 3 в ряд
// на выход будет вектор координат оптимальных позиций
vector<vector<int>> fill_mass_matrix(bool figure, container content)
{
    //рассмотрение вариантов 3 и 4 в ряд у противника и у себя
    // матрица весов и выбор оптимального
}
