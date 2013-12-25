#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Number.h"

using std::string;
using std::iostream;
using std::vector;

template<class KEY, class VALUE>
class Map
{
private:
    vector<KEY> map[2];
public:
    void setVariable(KEY T1, VALUE T2)
    {
        map[0].push_back(T1);
        map[1].push_back(T2);
    };
    VALUE getVariable(KEY A)
    {
        int i = 0;
        while (i != map[0].size())
        {
            if (map[0][i] == A) return map[1][i];
            else ++i;
        }

    }
};

/*
struct BinaryTree
{
double key; // ������ ���������
BinaryTree*left;
BinaryTree*right;
BinaryTree*parent;
int output; // ��������� ���������

};
struct Variables
{
string variable; // ����������, ������������ ����������
Variables*left;
Variables*right;
Variables*parent;
int value; // �������� ����������
};

BinaryTree *root;
Variables *var_root;
*/
/*
};
public:
Map();
void setVariable(string variable, int value);    ������� ��� ��������� ���������� � �� �������� � ������
int getVariable(string variable);                �������, ������� �� ����� ���������� ���������� �� ��������
void setOutput(int key, int output);             ������� ��� ��������� ���������� � ������ ���������
int getOutput(int key);                          �������, ������� �� ������� ��������� ���������� ����� - ��������� ����������
implement template of Map<K, V>
probably the best variant for your purposes is implement map, 
based on hashes 
or even simply - on arrays.
do not implement Map based on trees, because 
Keys can't be compared in some cases(for example, complex numbers)
you have to implement at least following:
some constructors
Key[] getKeys
Value[] getValues
put(Key, Value)
get(Key)
whatever you think is important (or probably I forgot smth)
};
*/