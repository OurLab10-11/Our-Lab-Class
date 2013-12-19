#pragma once;
#include <string>
using std::string;

class Number
{
public:
    Number(const Number&);
    Number(string s);
    virtual ~Number();

    virtual Number operator+(Number a);
    virtual Number operator-(Number a);
    virtual Number operator*(Number a);
    virtual Number operator^(int a);
};