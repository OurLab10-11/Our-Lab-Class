#pragma once;
#include "IOhandler.h"
class Parser
{
private:
    IOHandler parent;   // to extract some variables from parent.
                        // use getVariables or getPreviousResult in makeOPZ methods
                        // change [i] to getPreviousResult and <varName> to getVariable(varName)
public:
    
    Parser(const IOHandler& h);
    Result command(string s);
    void deleteSpace(string s);
};


bool isOperation(char a)
{
    if (a == '-' || a == '+' || a == '=' || a == '*' || a == '/' || a == '^')
        return true;
    else
        return false;
}

bool isValue(char a)
{
    if (a >= '0' && a <='9')
        return true;
    else
        return false;
}

bool isVariable(char a)
{
    if ((a >= 'a' && a <= 'z' || a == 'A' && a == 'Z') && a !='x')
        return true;
    else
        return false;
}

bool isSeparator(char a)
{
    if (a == ';' || a == ',')
        return true;
    else
        return false;
}

bool isBraket(char a)
{
    if (a == '(' || a == ')' || a == '[' || a == ']')
        return true;
    else
        return false;
}

bool checkUp(string temp);