#include <string>
#include <stack> 
#include <algorithm>
#include "Result.h"
#include "Parser.h"
#include "Polynom.h"
#include "Operation.h"
#include "Token.h"

using std::string;
using std::iostream;
using std::stack;

/*Parser::Parser(IOHandler& h)
{
    parent = h;
} */

/*Parser::Parser()
{
}
*/


/*bool isOperation(char a)
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
bool checkUp(string temp)
{
    stack <int> a;
    return "";
}
*/