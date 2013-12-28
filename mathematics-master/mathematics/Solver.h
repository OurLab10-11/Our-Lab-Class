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
        return (pr1>=pr2);
    }
    Polynom<int> makeOPZ(Result& temp)
    {
        //to add 
        vector <Token*> vect;
        stack <Token*> stak;
        for (unsigned int i = 0; i < temp.result.size(); i++)
        {
            if (temp.result[i]->isPolynom())
            {
                if ((temp.result[i]->a != "") && (temp.result[i]->a != "x"))
                {
                    Polynom<int>* A = new Polynom<int>(newNames.getVariable(temp.result[i]->a));
                    vect.push_back(A);
                    continue;
                }
                vect.push_back(temp.result[i]);
                continue;
            }
            if (temp.result[i]->isOpenBracket())
            {
                if (temp.result[i]->a == "[")
                {
                    temp.result[i]->a = "$";
                    vect.push_back(temp.result[i]);
                    vect.push_back(temp.result[++i]);
                    ++i;
                    continue;
                }
                stak.push(temp.result[i]);
                continue;
            }
            if (temp.result[i]->isCloseBracket())
            {
                while (!stak.empty() && !stak.top()->isOpenBracket())
                {
                    vect.push_back(stak.top());
                    stak.pop();
                }
                if (stak.empty())
                {
                    return 0;//Error: not enough of opening brackets.
                }
                //if (stak.top().isOpenBracket != temp.result[i].isCloseBracket()) //bracket's mismatch checking. If needed.
                //error handler here
                stak.pop();
                continue;
            }
            if (temp.result[i]->isOperation())
            {
                while (!stak.empty() && !stak.top()->isOpenBracket() && higherPriority(stak.top(), temp.result[i]))
                {
                    vect.push_back(stak.top());
                    stak.pop();
                }
                stak.push(temp.result[i]);
            }
        }
        while (!stak.empty())
        {
            vect.push_back(stak.top());
            stak.pop();
        }
        temp.result = vect;
        int i = 0;
        vector <Polynom<int>*> operands;
        while (i < vect.size())
        {
            if (vect[i]->isPolynom())
                operands.push_back(dynamic_cast<Polynom<int>*>(vect[i]));
            else
            {
                if (operands.size() < 2)
                {
                    //Error: number of operations is more than number of operands.
                }
                Polynom <int> *m = new Polynom<int>;
                if (vect[i]->a != "$")
                {
                    m = operands.back();
                    operands.pop_back();
                }
                Polynom <int> *n = new Polynom<int>;
                n = operands.back();
                operands.pop_back();
                switch (vect[i]->isOperation())
                {
                case 1:
                    {    *n += *m;
                    Polynom <int> * k = new Polynom <int> (*n);
                    operands.push_back(k);
                    break;
                    }
                case 2:
                    {
                        *n -= *m;
                        Polynom <int> * k = new Polynom <int> (*n);
                        operands.push_back(k);
                        
                        break;
                    }
                case 3:
                    {
                        *n *= *m;
                        Polynom <int> * k = new Polynom <int> (*n);
                        operands.push_back(k);
                        break;
                    }
                case 4:
                    {
                        *n = (*n)(*m);
                        Polynom <int> * k = new Polynom <int> (*n);
                        operands.push_back(k);
                        break;
                    }
                case 5:
                    {
                        *n = *n^*m;
                        Polynom <int> * k = new Polynom <int> (*n);
                        operands.push_back(k);
                        break;
                    }
                case 6:
                    {                       
                        *n = values[n->getFirstGree()];
                        Polynom <int> * k = new Polynom <int> (*n);
                        operands.push_back(k);
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
        return *m;
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
public:
    Map<string, Polynom<int>> getEquals();
    Polynom<int> execute(Result& r)
    {
        Polynom<int> A = makeOPZ(makeEquals(r));
        values.push_back(A);
        if (keys.size() < values.size())
            keys.push_back("");
        newNames.setVariable(keys.back(), values.back());
        return A;
    }
};