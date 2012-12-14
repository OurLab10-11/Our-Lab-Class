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
        return "ERROR";
    }
};
