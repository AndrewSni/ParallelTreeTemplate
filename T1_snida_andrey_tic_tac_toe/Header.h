#pragma once
#include <iostream>
#include "Header.h"
#include <fstream>
#include <vector>
using namespace std;
/*
���������� ������������ ���� � ���� ���������-������ 5 � ��� �� ����������� �����.
�������� ���������, ������� �������� �� ���� ������� ������� � ���� ���������-������ 5 � ��� �� ����������� �����
� ������������ ����������� ��� � ������ �������.
*/


struct container
{
    int** matrix;
    int shift_x;
    int shift_y;
    container()
    {
        matrix = nullptr;
        shift_x = 0;
        shift_y = 0;
    }
    container(int** a, int s_x, int s_y)
    {
        matrix = a;
        shift_x = s_x;
        shift_y = s_y;
    }
};


vector<vector<int>> read_matrix(string filename);
container* create_mass_matrix(vector<vector<int>> input);
vector<vector<int>> fill_mass_matrix(bool figure, container content);