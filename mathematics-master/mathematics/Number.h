#pragma once
#include <string>
#include <iostream>

using std::string;
using std::iostream;

class Number
{
public:
    Number(const Number&);
    Number(string s);
    virtual ~Number();

    virtual Number operator+(Number a);
    virtual Number operator-(Number a);
    virtual Number operator*(Number a);
    virtual Number operator/(Number a);
    virtual Number operator^(Number a);
};