#pragma once
#include <iostream>
#include <string>

using namespace std;

class Token
{
public:
    string a;
    virtual bool isOperation(Token)
    {
        if (a == "+" || a == "-" || a == "*" || a == "/")
            return true;
        else
            return false;
    }
    virtual bool isPolynom(Token)
    {
        if (!isOperation(*this) && !isSeparator(*this))
            return true;
        else
            return false;
    }
    virtual bool isSeparator(Token)
    {
        if (a == ";" || a == ",")
            return true;
        else
            return false;
    }
};