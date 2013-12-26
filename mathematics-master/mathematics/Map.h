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
    vector<KEY> keys;
    vector<VALUE> values;
public:
    void setVariable(KEY T1, VALUE T2)
    {
        keys.push_back(T1);
        values.push_back(T2);
    };
    VALUE getVariable(KEY A)
    {
        int i = 0;
        while (i != keys.size())
        {
            if (keys[i] == A) 
                return values[i];
            else
                ++i;
        }
        return "0";
    }
};

/*
struct BinaryTree
{
double key; // индекс выражения
BinaryTree*left;
BinaryTree*right;
BinaryTree*parent;
int output; // результат выражения

};
struct Variables
{
string variable; // переменная, используемая программой
Variables*left;
Variables*right;
Variables*parent;
int value; // значение переменной
};

BinaryTree *root;
Variables *var_root;
*/
/*
};
public:
Map();
void setVariable(string variable, int value);    функция для занесения переменной и ее значения в память
int getVariable(string variable);                функция, которая по имени переменной возвращает ее значение
void setOutput(int key, int output);             функция для занесения результата в память программы
int getOutput(int key);                          функция, которая по индексу выражения возвращает число - результат вычисления
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