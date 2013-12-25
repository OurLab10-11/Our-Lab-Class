#pragma once
#include <iostream>
#include <string>
#include "Polynom.h"

using namespace std;

class Token
{
public:
    string a; 
    virtual bool isOperation()
    {
        if (a == "+" || a == "-" || a == "*" || a == "^") // "/" cannot be mentioned here. It is used only in Rational, and there's Parser to think about it :)
            return true;
        else
            return false;
    }
    virtual bool isPolynom()
    {
        if (!this->isOperation() && !this->isSeparator())
            return true;
        else
            return false;
    }
    virtual bool isSeparator()
    {
        if (a == ";" || a == ",")
            return true;
        else
            return false;
    }
    virtual int isOpenBracket() //return 1 if "[", 2 if "("
    {
        if (a == "[")
            return 1;
        else
            if (a == "(")
                return 2;
            else
                return 0;
    }
    virtual int isCloseBracket() //return 1 if "]", 2 if ")"
    {
        if (a == "]")
            return 1;
        else
            if (a == ")")
                return 2;
            else
                return 0;
    }
};