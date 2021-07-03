#include <iostream>
#include "Header.h"
#include <fstream>
#include <vector>
using namespace std;


// ������ �������� � ������� ��������� ���������� x y � ������� - 1 ��� ����� - 0
// ������ ������� �� �� ������
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

// ��������� ������� ����� ������� ������� ����� ������ �� ������� �������
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
    int** matrix = new int* [(max_x - min_x+6) * (max_y - min_y+6)];// 6 ��� ������� ��������� ��������� ���� ������� ���������
    container* content = new container(matrix, min_x, min_y);
    return content;
}


// �� ���� ���� ������� ������: �������/�����
// ��������� ������� �����: ��� ������ ����������� �� ������ � ������������ ����� � ������� 3� ������ �� ������
// ��� ������������ ��� +1 � ��� �� �����������
// ��� ���� ����������� �� ������ ����� ��������������� ������ ����� ��������� ����� ������ �� ���� ���� ���� �� 3 � ���
// �� ����� ����� ������ ��������� ����������� �������
vector<vector<int>> fill_mass_matrix(bool figure, container content)
{
    //������������ ��������� 3 � 4 � ��� � ���������� � � ����
    // ������� ����� � ����� ������������
}
