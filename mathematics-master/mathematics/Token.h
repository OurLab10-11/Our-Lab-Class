#pragma once
#include <iostream>
#include <string>

using std::iostream;
using std::string;

class Token
{
public:
    string a;
    virtual bool isOperation1()
    {
        if (a == "+" || a == "-" || a == "*" || a == "/")
            return true;
        else
            return false;
    }
    virtual bool isVariable1()
    {
        if (a.size() == 1 && a[0] == 'x')
            return true;
        else
            return false;
    }
    virtual bool isValue1()
    {
        if (a[0] >= '0' && a[0] <= '9')
            return true;
        else
            return false;
    }
    virtual bool isSeparator1()
    {
        if (a == ";" || a == ",")
            return true;
        else
            return false;
    }
};