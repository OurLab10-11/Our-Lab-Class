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
    bool isOpenBracket(Token)
    {
        if (this->operatoring == "[" || this->operatoring == "(")
            return true;
        else
            return false;
    }
    bool isCloseBracket(Token)
    {
        if (this->operatoring == "]" || this->operatoring == ")")
            return true;
        else
            return false;
    }
};




