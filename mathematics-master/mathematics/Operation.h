#pragma once;
#include <string>
#include "Token.h"

using std::string;

class Operation: public Token
{
public:
    static const string ADD;
    static const string SUB;
    static const string MUL;
    static const string EQ;
};