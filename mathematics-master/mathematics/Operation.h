#pragma once
#include <string>
#include "Token.h"
#include <iostream>

using namespace std;

class Operation : public Token
{
private:
    string operatoring;
public:
    Operation();
    Operation(const string b)
    {
        a = b;
    }
};




