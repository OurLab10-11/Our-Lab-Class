#pragma once
#include <iostream>
#include <string>
#include "Polynom.h"
#include "Parser.h"
#include "Solver.h"
#include "Number.h"
#include "Operation.h"
#include "Map.h"
#include "Rational.h"

using namespace std;

class Parser 
{      
public:
    Parser()
    {};
    bool isOperation(char a)
    {
        if (a == '-' || a == '+' || a == '=' || a == '*' || a == '/' || a == '^' || a == '#' ||  a == '%')
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
    vector<Result> command(string temp)
    {
        vector<Result> result;
        temp = deleteSpace(temp);
        int length = temp.length();
        int amountOfSeparator = 0;
        for (unsigned int i = 0; i < temp.length(); ++i)
            if (isSeparator(temp[i])) 
                ++amountOfSeparator;
        result.resize(++amountOfSeparator);
        temp += " ";
        
        string input = "";
        if (temp[0] == '-')
        {
            input += '-';
            temp.erase(0,1);
        }
        int j = 0;
        for (int  i = 0; i < length; ++i)
        {
            while(!isSeparator(temp[i]))
            {
                if (temp[i] == ' ')
                    break;
                if (temp[i] == '-'&& i > 0 && temp[i-1] != '%' && ((isOperation(temp[i - 1]) || (temp[i - 1]) == '(' || temp[i - 1] == '[')))
                { 
                    input += temp[i];
                    ++i;
                    continue;
                }
                if (isOperation(temp[i]) && temp[i + 1] == 'i')
                {
                    input += temp[i];
                    Operation* C = new Operation(input);
                    result[j].addToken(C);
                    input = "1";
                    Polynom<Complex<Rational>>* A = new Polynom<Complex<Rational>>(input);
                    result[j].addToken(A);
                    input = "*";
                    Operation* B = new Operation(input);
                    result[j].addToken(B);
                    ++i;
                    input = "";
                    input += temp[i];
                    Polynom<Complex<Rational>>* O = new Polynom<Complex<Rational>>(input);
                    result[j].addToken(O);
                    input = "";
                    ++i;
                    continue;
                }

                if (temp[i] == '.')
                {
                    input +=temp[i];
                    ++i;
                    continue;
                }
                if (temp[i] == '(' || temp[i] == ')')
                {
                    if (input != "")
                    {
                        Polynom<Complex<Rational>>*A = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(A);
                    }
                    input = temp[i];
                    Operation* O = new Operation(input);
                    result[j].addToken(O);
                    input = "";
                    ++i;
                    continue;
                }

                if (temp[i] == '[')
                {
                    if (input != "")
                    {
                        Polynom<Complex<Rational>>*A = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(A);
                    }
                    input = "(";
                    Operation* O = new Operation(input);
                    result[j].addToken(O);
                    result[j].addToken(O);
                    input = "";
                    ++i;
                    continue;
                }

                if (temp[i] == ']')
                {
                    if (input != "")
                    {
                        Polynom<Complex<Rational>>*A = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(A);
                    }
                    input = ")";
                    Operation* O = new Operation(input);
                    result[j].addToken(O);
                    input = "$";
                    Operation* A = new Operation(input);
                    result[j].addToken(A);
                    input = ")";
                    Operation* B = new Operation(input);
                    result[j].addToken(B);
                    input = "";
                    ++i;
                    continue;
                }

                if (isOperation(temp[i]))
                {
                    if (input != "")
                    {
                        Polynom<Complex<Rational>>* A = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(A);
                    }
                    input = temp[i];
                    Operation* O = new Operation(input);
                    result[j].addToken(O);
                    input = "";
                    ++i;
                    continue;
                }

                if (isdigit(temp[i]))
                {
                    input += temp[i];
                    if (!isdigit(temp[i + 1]) && temp[i + 1] != '.')
                    {
                        Polynom<Complex<Rational>>* O = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(O);
                        input = "";
                        ++i;
                        continue;
                    }
                    else
                    {
                        ++i;
                        continue;
                    }
                }   
                if (isalpha(temp[i]))
                {
                    input += temp[i];
                    ++i;
                    if (!isalpha(temp[i]))
                    {
                        Polynom<Complex<Rational>>* O = new Polynom<Complex<Rational>>(input);
                        result[j].addToken(O);
                        if (input !="x" && input != "i")
                            result[j].result.back()->a = input;
                        input = "";
                        continue;
                    }
                }
            }
            if (input != "")
            {
                if (isOperation(input[0]) && (1u == input.length()))
                {
                    Operation* O = new Operation(input);
                    result[j].addToken(O);
                }
                else
                {
                    Polynom<Complex<Rational>>* O = new Polynom<Complex<Rational>>(input);
                    result[j].addToken(O);
                }
            }
            ++j;
        }
        return result;

    }
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
        for (int position = 0; position < length - 1; ++position)
        {
            if (temp[position] == ')' && temp[position + 1] == '[')
            {
                temp.insert(position + 1, "*");
                length++;
                ++position;
                
            }
        }

        for (int position = 0; position < length - 1; ++position)
        {
            if (isalpha(temp[position + 1]) && isdigit(temp[position]))
            {
                temp.insert(position + 1,"*");
                ++length;
                ++position;
                continue;
            }
            if (isalpha(temp[position]) && isdigit(temp[position + 1]))
            {
                temp.insert(position + 1,"*");
                ++length;
                ++position;
                continue;
            }
        }
        for (int position = 0; position < length - 1; ++position)
        {
            if (temp[position + 1] == '(')
            {
                if (temp[position] != '+' && temp[position] != '-' && temp[position] != '^' && temp[position] != '*' && temp[position] != '/')
                {
                    temp.insert(position + 1,"#");
                    ++length;
                    ++position;
                }
            }
        }
        for (int position = 0; position < length - 1; ++position)
        {
            if (temp[position] == '-')
            {
                if (isalnum(temp[position + 1]))
                {
                    temp.insert(position + 1,"1*");
                    length += 2;
                    position += 2;
                }
            }
        }
        return temp;
    }
};

class IOHandler
{
private:
    Solver solver;
    Parser parser;
public:
    Map<string, Polynom<Complex<Rational>>> polynoms; //  variables
    vector<Polynom<Complex<Rational>>> previousResults; // to support previous polynoms calls.
    int counter;
    IOHandler()
    {
        counter = 0;
    }
    int getCurrentStep()
    {
        return counter;
    }
    vector<Polynom<Complex<Rational>>> executeCommand(string command)
    {
        vector<Result> response = parser.command(command);
        vector<Polynom<Complex<Rational>>> Poly;
        for (unsigned int size = 0; size < response.size(); ++size)
        {
            Poly.push_back(solver.execute(response[size]));
            previousResults.push_back(Poly[size]);
        }
        
        return Poly;
    }
    Polynom<Complex<Rational>> getVariable(string variableName)
    {
        return polynoms.getVariable(variableName);
        //extracting from the map value of variableName
        //must throws exception if variable with this name does not exist.
        //return map.get(variableName);

    }
    Polynom<Complex<Rational>> getPreviousResult(int Number)
    {
        //to do
        //must throws exception if number out of bounds
        return previousResults[Number];
    }
};
