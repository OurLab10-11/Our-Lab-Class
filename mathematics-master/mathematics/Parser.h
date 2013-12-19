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
    void probeli(string s);
};

bool checkUp(string temp);