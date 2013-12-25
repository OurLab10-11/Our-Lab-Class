#pragma once
#include <string>
#include <vector>
#include <stack>
#include "Number.h"
#include "Result.h"
#include "Polynom.h"
#include "Operation.h"
#include "Map.h"
#include "Token.h"

using namespace std;


class Solver
{
private:
    Map<string, Polynom<int>> newNames;
    Result opz;
    Result initial;
    bool higherPriority (Token *op1, Token *op2) //priority comparison
    {
        string operations[] = {"_", "+", "-", "*", "^"};
        int priority[] = {1, 1, 1, 2, 3};
        int pr1, pr2;
        for(int i = 0; i < 5; i++)
        {
            if(op1->a == operations[i])
                pr1=priority[i];
            if(op2->a == operations[i])
                pr2=priority[i];
        }
        return (pr1>pr2);
    }
    void makeOPZ(Result& temp)
    {
        vector <Token*> vect;
        stack <Token*> stak;
        for (unsigned int i = 0; i < temp.result.size(); i++)
        {
            if (temp.result[i]->isPolynom())
            {
                vect.push_back(temp.result[i]);
                continue;
            }
            if (temp.result[i]->isOpenBracket())
            {
                stak.push(temp.result[i]);
                continue;
            }
            if (temp.result[i]->isCloseBracket())
            {
                while (!stak.empty() && !stak.top()->isOpenBracket())
                {
                    vect.push_back(stak.top());
                }
                if (stak.empty())
                {
                    //Error: not enough of opening brackets.
                }
                //if (stak.top().isOpenBracket != temp.result[i].isCloseBracket()) //bracket's mismatch checking. If needed.
                //error handler here
                stak.pop();
                continue;
            }
            if (temp.result[i]->isOperation())
            {

                if ((temp.result[i]->a == "-" && !i) || (temp.result[i]->a == "-" && temp.result[i]->isOpenBracket())) //unary minus
                {
                    temp.result[i]->a = "_";
                    //ATTENTION! Changing temp here!
                    // And using "_" to designate the unary minus.
                }
                while (!stak.empty() && !stak.top()->isOpenBracket() && higherPriority(stak.top(), temp.result[i]))
                {
                    vect.push_back(stak.top());
                    stak.pop();
                }
                stak.push(temp.result[i]);
            }
            opz.result = vect;
        }
        //to do OPZ from tokens.
        //initial is the field already partitioned.
        //just make opz from it and write to opz field.
    }
    void makeEquals(Result& r){};/*
    {
        int EQ = 0;
        for (int i = 0; i < r.result.size(); ++i)
            if (r.result[i].a == "=")
                EQ++;
        if (EQ == 0)
            return;
        Result R;
        unsigned int step = 0;
        for (step; step < r.result.size(); ++step)
        {
            string NewName;
            NewName = r.result[step++].a;
            step++;
            while (step < r.result.size() && (!(r.result[step].isSeparator())))
            {
                R.result.push_back(r.result[step]);
                ++step;
            }
            
            //Polynom<int> A;
            // handler.polynoms.setVariable(NewName, A);
        }
        //to do
        //add to newNames all equals
        //received from current command    
    };*/
    void Solver::init(Result& r)
    {
        initial = r;
        makeOPZ(initial);
        makeEquals(r);
    };
public:
    Map<string, Polynom<int>> getEquals();
    Polynom<int> execute(Result& r)
    {
        Polynom<int> A;
        makeOPZ(r);
        init(r);
        //executing opz , must return polynom
        return A;
    }
};