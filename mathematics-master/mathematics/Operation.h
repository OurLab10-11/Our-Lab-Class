#pragma once
#include <string>
#include "Token.h"
#include <iostream>

using std::iostream;
using std::string;

class Operation : public Token
{
private:
    string operatoring;
public:
    Operation();
    Operation(const string &b)
    {
        if (b == "+")
            operatoring = "+";
        if (b == "-")
            operatoring = "-";
        if (b == "*")
            operatoring = "*";
        if (b == "/")
            operatoring = "/";
        if (b == "^")
            operatoring = "^";
        if (b == "=")
            operatoring = "=";
    }
};




