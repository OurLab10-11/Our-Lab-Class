#pragma once;
template<class Key, class Value>
#include <vector>
#include <string>

using namespace std;


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

class Map
{
public:
    Map();
    void setVariable(string variable, int value); // ������� ��� ��������� ���������� � �� �������� � ������
    int getVariable(string variable); // �������, ������� �� ����� ���������� ���������� �� ��������
    void setOutput(int key, int output); // ������� ��� ��������� ���������� � ������ ���������
    int getOutput(int key); // �������, ������� �� ������� ��������� ���������� ����� - ��������� ����������

private:	

    //implement template of Map<K, V>
    //probably the best variant for your purposes is implement map, 
    //based on hashes 
    //or even simply - on arrays.

    //do not implement Map based on trees, because 
    //Keys can't be compared in some cases(for example, complex numbers)


    //you have to implement at least following:
    //some constructors
    //Key[] getKeys
    //Value[] getValues
    //put(Key, Value)
    //get(Key)

    //whatever you think is important (or probably I forgot smth)
};
