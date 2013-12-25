#pragma once
#include <string>
#include <iostream>

using std::string;
using std::iostream;

class Number
{
public:
    Number(const Number&){};
    Number(string s);
    Number(int s){};
    virtual ~Number();

    virtual Number operator+(Number a);
    virtual Number operator-(Number a);
    virtual Number operator*(Number a);
    virtual Number operator/(Number a);
    virtual Number operator^(Number a);
};