#pragma once
#include <iostream>
#include <vector>
#include "Token.h"

using std::vector;

class Result
{
public:
    vector<Token*> result;
    void addToken(Token *t)
    {
        result.push_back(t);
    }
    //add some methods (probably iterators or just get for vector) 
    //to access result.
};