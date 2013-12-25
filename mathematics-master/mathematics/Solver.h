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
    Result opz;
    Result initial;
    vector<string> keys;
    vector<Polynom<int>> values;
    Map<string, Polynom<int>> newNames;
    Polynom<int> makeOPZ(Result& temp)
    {
        //to add 
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
            temp.result = vect;
        }
        int i = 0;
        vector <Polynom<int>*> operands;
        while (i < temp.result.size())
        {
            if (temp.result[i]->isPolynom())
                operands.push_back(temp.result[i]);
            else
            {
                if (operands.size() < 2)
                {
                    //Error: number of operations is more than number of operands.
                }
                Polynom <int> m = operands.back()->a;
                operands.pop_back();
                Polynom <int> n = operands.back()->a;
                operands.pop_back();
                switch (temp.result[i]->isOperation())
                {
                case 1:
                    {    m += n;
                    Polynom <int> * k = new Polynom <int> (m);
                    operands.push_back(k);
                    delete [] k;
                    break;
                    }
                case 2:
                    {
                        m -= n;
                        Polynom <int> * k = new Polynom <int> (m);
                        operands.push_back(k);
                        delete [] k;
                        break;
                    }
                case 3:
                    {
                        m *= n;
                        Polynom <int> * k = new Polynom <int> (m);
                        operands.push_back(k);
                        delete [] k;
                        break;
                    }
                case 4:
                    {
                        m = m ^ n;
                        Polynom <int> * k = new Polynom <int> (m);
                        operands.push_back(k);
                        delete [] k;
                        break;
                    }
                case 5:
                    {
                        m = m(n);
                        Polynom <int> * k = new Polynom <int> (m);
                        operands.push_back(k);
                        delete [] k;
                        break;
                    }
                    //default:
                    //Error: incorrect operation expression.
                }
            }
            i++;
        }
        if (operands.size() != 1)
        {
            //Error.
        }

        //to do OPZ from tokens.
        //initial is the field already partitioned.
        //just make opz from it and write to opz field.
        Polynom <int>* m = new Polynom<int>;
        m = operands.back();
        return m;
    }
    Result makeEquals(Result& r)
    {
        int EQ = 0;
        for (int i = 0; i < r.result.size(); ++i)
            if (r.result[i]->a == "=")
                EQ++;
        if (EQ == 0)
        {
            return r;
        }
        Result R;
        unsigned int step = 2;
        keys.push_back(r.result[0]->a);
        Polynom<int> A;
        for (step; step < r.result.size(); ++step)
            R.result.push_back(r.result[step]);
        //to do
        //add to newNames all equals
        //received from current command    
        return R;
    }
    Polynom<int> Solver::init(Result& r)
    { 
        initial = r;
        makeOPZ(initial); 
        return makeOPZ(initial);
    }
    bool higherPriority (Token *op1, Token *op2) //priority comparison
    {
        const string operations[] = {"_", "+", "-", "*", "#", "^"};
        int priority[] = {1, 1, 1, 2, 3, 4};
        int pr1, pr2;
        for(int i = 0; i < 6; i++)
        {
            if(op1->a == operations[i])
                pr1=priority[i];
            if(op2->a == operations[i])
                pr2=priority[i];
        }
        return (pr1>pr2);
    }
public:
    Map<string, Polynom<int>> getEquals();
    Polynom<int> execute(Result& r)
    {
        Polynom<int> A = makeOPZ(makeEquals(r));
        return A;
    }
};