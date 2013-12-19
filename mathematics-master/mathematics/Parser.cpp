#include "Parser.h"
#include "Result.h"
#include <string>
#include <stack>

using std::string;

Parser::Parser(const IOHandler& h)
{
    parent = h;
} 

bool checkUp(string temp)
{
    stack <char> brackets;
    
}

void Parser::probeli(string temp)
{
    Result result;
    int length = temp.length();
    for (int position = 0; position < length; ++position)
    {
        if (temp[position] == ' ')
        {
            if (position > 0 && position < (length - 1) && isalpha(temp[position - 1]) && isalpha(temp[position + 1])) //if space between two variables
                temp[position] = '*';
            else
            {
                temp.erase(position, 1);
                position--;
                length--;
            }
        }
    }
}

Result Parser::command(string temp)
{
    Result result;
    probeli(temp);
    int length = temp.length();
    temp += ' ';
    string input = "";
    for (int  i = 0; i < length; ++i)
    {
        if (temp[i] == ' ')
            break;
        
        if (isOperation(temp[i]) && temp[i + 1] == 'i')
        {
            input = temp[i];
            Token T;
            T.a = input;
            input = "1";
            result.addToken(T);
            T.a = input;
            result.addToken(T);
            input = "";
            continue;
        }

        if (temp[i] == '.')
        {
            input +=temp[i];
            continue;
        }
        if (temp[i] == '[' || temp[i] == ']' || temp[i] == '(' || temp[i] == ')')
        {
            input = temp[i];
            Token T;
            T.a = input;
            input = "";
            result.addToken(T);
            continue;
        }
 
        if (isOperation(temp[i]))
        {
            input = temp[i];
            Token T;
            T.a = input;
            input = "";
            result.addToken(T);
            continue;
        }

        if (isdigit(temp[i]))
        {
            input += temp[i];
            if (!isdigit(temp[i + 1]) && temp[i + 1] != '.')
            {
                Token T;
                T.a = input;
                result.addToken(T);
                input = "";
            }
        }

        if (isalpha(temp[i]))
        {
            input += temp[i];
            if (!isalpha(temp[i + 1]))
            {
                Token T;
                T.a = input;
                result.addToken(T);
                input = "";
            }
        }
    }
    return result;
}

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