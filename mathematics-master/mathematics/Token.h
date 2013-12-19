#pragma once;
#include "Operation.h"
using namespace std;

class Token
{
public:
    string a;
    ~Token();
    
    bool Token::isOperation()
    {
        if (a == "+" || a == "-" || a == "*" || a == "/")
            return true;
        else
            return false;
    }
    bool Token::isVariable()
    {
        if (a.size() == 1 && a[0] == 'x')
            return true;
        else
            return false;
    }
    bool Token::isValue()
    {
        if (a[0] >= '0' && a[0] <= '9')
            return true;
        else
            return false;
    }
    bool Token::isSeparator()
    {
        if (a == ";" || a == ",")
            return true;
        else
            return false;
    }
};