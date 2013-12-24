#pragma once
#include <string>
#include "Map.h"
#include "Number.h"
#include "Result.h"
#include <vector>
#include "Polynom.h"
#include "Operation.h"
#include <stack>

using namespace std;

class Solver
{
private:
    //Map<string, Polynom<int>> newNames;
    Result opz;
    Result initial;
    void makeOPZ(const Result& temp)
    {
        
        vector <Token> vect;
        stack <Token> stak;
        for (int i = 0; i < temp.result.size(); ++i)
        {
            if (isPolynom(temp.result[i]))
            {
                vect.push_back(temp.result[i]);
                continue;
            }
            if (isOpenBracket(temp.result[i]))
            {
                stak.push(temp.result[i]);
                continue;
            }
            if (isCloseBracket(temp.result[i]))
            {
                while (!isOpenBracket(stak.top()))
                {
                    vect.push_back(stak.top());
                }
                stak.pop();
            }
            {

            }
        }
        //to do OPZ from tokens.
        //initial is the field already partitioned.
        //just make opz from it and write to opz field.
    }
    void makeEquals()
    {
        return;
        //to do
        //add to newNames all equals
        //received from current command    
    };
    void Solver::init(const Result& r)
    {
        initial = r;
        makeOPZ(initial);
        makeEquals();
    };
public:
    //Map<string, Polynom<int>> getEquals();
    string execute(const Result& r)
    {
        makeOPZ(r);
        init(r);
        //executing opz
        //must return polynom
        return "";
    }
};