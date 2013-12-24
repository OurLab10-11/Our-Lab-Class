#pragma once
#include <iostream>
#include <string>
#include "Polynom.h"
#include "Parser.h"
#include "Solver.h"
#include "Number.h"
#include "Operation.h"

using std::string;
using std::iostream;
using std::stack;

class Parser
{
private://IOHandler parent;     // to extract some variables from parent.
    // use getVariables or getPreviousResult in makeOPZ methods
    // change [i] to getPreviousResult and <varName> to getVariable(varName)    
public://Parser();
    //Parser(IOHandler& h);
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
    bool checkUp(string temp)
    {
        stack <int> a;
        return "";
    }
    Result command(string temp)
    {
        Result result;
        temp = deleteSpace(temp);
        int length = temp.length();
        temp += " ";
        string input = "";
        if (temp[0] == '-')
        {
            input +=temp[0];
        }
        for (int  i = 0; i < length; ++i)
        {
            if (temp[i] == ' ')
                break;
            if (temp[i] == '-'&& i > 0 && (isOperation(temp[i - 1]) || isBraket(temp[i - 1])))
            { 
                input += "-";
                continue;
            }
            if (isOperation(temp[i]) && temp[i + 1] == 'i')
            {
                input = temp[i];
                Operation A(input);
                result.addToken(A);
                input = "1";
                Polynom<int> B(input);
                result.addToken(B);
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
                if (isOperation(input[0]) && (1u == input.length()))
                {
                    Operation A(input);
                    result.addToken(A);
                }
                else
                {
                    Polynom<int> A(input);
                    result.addToken(A);
                }
                input = "";
                continue;
            }

            if (isOperation(temp[i]))
            {
                input = temp[i];
                Operation A(input);
                result.addToken(A);
                input = "";
                continue;
            }

            if (isdigit(temp[i]))
            {
                input += temp[i];
                if (!isdigit(temp[i + 1]) && temp[i + 1] != '.')
                {
                    Polynom<int> A(input);
                    result.addToken(A);
                    input = "";
                    continue;
                }
                else
                {
                    input +=temp[i + 1];
                    i = i + 1;
                    continue;
                }
            }   
            if (isalpha(temp[i]))
            {
                input += temp[i];
                if (!isalpha(temp[i + 1]))
                {
                    Polynom<int> A(input);
                    result.addToken(A);
                    input = "";
                    continue;
                }
            }
        }
        if (input != "")
        {
            if (isOperation(input[0]) && (1u == input.length()))
            {
                Operation A(input);
                result.addToken(A);
            }
            else
            {
                Polynom<int> A(input);
                result.addToken(A);
            }

        }
        
        return result;
    };
    string deleteSpace(string temp)
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
        for (int position = 0; position < length; ++position)
        {
            if ((isalpha(temp[position + 1]) && isdigit(temp[position])) || (isalpha(temp[position]) && isdigit(temp[position + 1])))
            {
                temp.insert(position + 1,"*");
                ++length;
            }

        }
        return temp;
    }
};

class IOHandler
{
private:
    Parser parser;
    Solver solver;
    //Map<string, Polynom<int>> polynoms; //  variables
    vector<Polynom<int>> previousResults; // to support previous polynoms calls.
public:
    //IOHandler();
    int counter;
    int getCurrentStep()
    {
        return counter;
    }
    string executeCommand(string command)
    {
        ++counter;
        Result response = parser.command(command);
        string result = solver.execute(response);
        //to do
        //adding newNames if non-empty.
        //
        return result;
    }

    //2 methods for solver.
    Polynom<int> getVariable(string variableName)
    {
        //extracting from the map value of variableName
        //must throws exception if variable with this name does not exist.
        //return map.get(variableName);
        return NULL;
    }
    Polynom<int> getPreviousResult(int number)
    {
        //to do
        //must throws exception if number out of bounds
        return previousResults[number];
    }
};






