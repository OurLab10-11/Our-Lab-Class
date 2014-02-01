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
#include "Complex.h"
#include "Rational.h"


using namespace std;


class Solver
{
private:
    bool isExist(string a)
    {
        for (unsigned int  i = 0; i < newNames.keys.size(); ++i)
            if (a == newNames.keys[i])
                return true;
        return false;
    }
    Result opz;
    Result initial;
    vector<string> keys;
    vector<Polynom<Complex<Rational>>> values;
    Map<string, Polynom<Complex<Rational>>> newNames;
    bool higherPriority (Token *op1, Token *op2) //priority comparison
    {
        const string operations[] = {"_", "+", "-", "*", "/", "#", "^"};
        int priority[] = {1, 1, 1, 2, 2, 3, 4};
        int pr1, pr2;
        for(int i = 0; i < 7; i++)
        {
            if(op1->a == operations[i])
                pr1=priority[i];
            if(op2->a == operations[i])
                pr2=priority[i];
        }
        return (pr1>=pr2);
    }
    Polynom<Complex<Rational>> makeOPZ(Result& temp)
    {
        vector <Token*> openingBrakets;
        vector <Token*> closingBrakets;
        vector <Token*> vect;
        stack <Token*> stak;
        for (unsigned int i = 0; i < temp.result.size(); i++)
        {
            if (temp.result[i]->isPolynom() || temp.result[i]->a == "%")
            {
                if ((temp.result[i]->a != "") && (temp.result[i]->a != "x"))
                {
                    Polynom<Complex<Rational>>* A = new Polynom <Complex<Rational>>;
                    if (temp.result[i]->a == "%")
                    {
                        if (values.size() == 0)
                        {
                            Polynom<Complex<Rational>> *B = new Polynom<Complex<Rational>>; 
                            B->exception.error = "Can not take last Output";
                            return *B;
                        }
                        else
                            A = new Polynom<Complex<Rational>>(values.back());
                    }
                    else
                        A = new Polynom<Complex<Rational>>(newNames.getVariable(temp.result[i]->a));
                    if (A->getFirstGree() == 10e8)
                    {
                        Polynom <Complex<Rational>>* m = new Polynom<Complex<Rational>>;
                        string error(temp.result[i]->a);
                        m->exception.error = error;
                        m->exception.error += " is undefined";
                        return *m;
                    }
                    vect.push_back(A);
                    continue;
                }
                vect.push_back(temp.result[i]);
                continue;
            }
            if (temp.result[i]->isOpenBracket())
            {
                openingBrakets.push_back(temp.result[i]);
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
                closingBrakets.push_back(temp.result[i]);
                while (!stak.empty() && !stak.top()->isOpenBracket())
                {
                    vect.push_back(stak.top());
                    stak.pop();
                }
                if (stak.empty())
                {
                    Polynom<Complex<Rational>> *A = new Polynom<Complex<Rational>>;
                    A->exception.error = "Does not have opening breckets";
                    return *A;
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
            if (stak.top()->isOpenBracket())
            {
                Polynom <Complex<Rational>> *d = new Polynom<Complex<Rational>>;
                d->exception.error = "Does not have close brakets";
                return *d;
            }
            vect.push_back(stak.top());
            stak.pop();
        }
        temp.result = vect;
        unsigned int i = 0;
        vector <Polynom<Complex<Rational>>*> operands;
        while (i < vect.size())
        {
            if (vect[i]->isPolynom())
                operands.push_back(dynamic_cast<Polynom<Complex<Rational>>*>(vect[i]));
            else
            {
                if (operands.size() < 2)
                {
                    //Error: number of operations is more than number of operands.
                }
                if (vect[i]->a != "%")
                {
                    Polynom <Complex<Rational>> *m = new Polynom<Complex<Rational>>;
                    if (vect[i]->a != "$")
                    {
                        if (operands.size() == 0)
                        {
                            Polynom <Complex<Rational>> *d = new Polynom<Complex<Rational>>;
                            d->exception.error = "Does not have digits";
                            return *d;
                        }
                        m = operands.back();
                        operands.pop_back();
                    }

                    Polynom <Complex<Rational>> *n = new Polynom<Complex<Rational>>;
                    if (operands.size() == 0)
                    {
                        Polynom <Complex<Rational>> *d = new Polynom<Complex<Rational>>;
                        d->exception.error = "Does not have digits";
                        return *d;
                    }
                    n = operands.back();
                    operands.pop_back();

                    switch (vect[i]->isOperation())
                    {
                    case 1:
                        {
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (*n + *m);
                            operands.push_back(k);
                            break;
                        }
                    case 2:
                        {
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (*n - *m);
                            operands.push_back(k);
                            break;
                        }
                    case 3:
                        {
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (*n* *m);
                            operands.push_back(k);
                            break;
                        }
                    case 4:
                        {
                            Polynom<Complex<Rational>> * k = new Polynom<Complex<Rational>> (*n/(*m));
                            operands.push_back(k);
                            break;
                        }
                    case 5:
                        {
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> ((*n)(*m));
                            operands.push_back(k);
                            break;
                        }
                    case 6:
                        {
                            int a = m->getFirstGree();
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (*n^a);
                            operands.push_back(k);
                            break;
                        }
                    case 7:
                        {     
                            if (n->getFirstGree() >= values.size())
                            {
                                Polynom <Complex<Rational>> * d = new Polynom <Complex<Rational>>;
                                d->exception.error = "Can not take [";
                                d->exception.error += to_string(n->getFirstGree());
                                d->exception.error += "]";
                                return *d;
                            }
                            Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (values[n->getFirstGree()]);
                            operands.push_back(k);
                            break;
                        }
                    }
                }
                else
                {
                    Polynom <Complex<Rational>> * k = new Polynom <Complex<Rational>> (values.back());
                    operands.push_back(k);
                }
                //default:
                //Error: incorrect operation expression.
            }
            ++i;
        }
        if (operands.size() == 0)
        {
            Polynom <Complex<Rational>>* m = new Polynom<Complex<Rational>>;
            string error("Please, enter expression");
            m->exception.error = error;
            return *m;
        }
        else
        {
            if (operands.size() > 1)
            {
                Polynom <Complex<Rational>>* m = new Polynom<Complex<Rational>>;
                string error("Not correct expression");
                m->exception.error = error;
                return *m;
            }
            else
            {
                Polynom <Complex<Rational>>* m = new Polynom<Complex<Rational>>;
                m = operands.back();
                return *m;
            }
        }
    }
    Result makeEquals(Result& r)
    {
        int EQ = 0;
        for (unsigned int i = 0; i < r.result.size(); ++i)
            if (r.result[i]->a == "=")
                EQ++;
        if (EQ == 0)
        {
            return r;
        }
        Result R;
        unsigned int step = 2;
        if (isExist(r.result[0]->a))
        {
            for (unsigned int i = 0; i < newNames.keys.size(); ++i)
                if (r.result[0]->a == newNames.keys[i])
                    newNames.keys[i] = "";
        }
        keys.push_back(r.result[0]->a);
        Polynom<Complex<Rational>> A;
        for (step; step < r.result.size(); ++step)
            R.result.push_back(r.result[step]);
        //to do
        //add to newNames all equals
        //received from current command    
        return R;
    }
public:
    Map<string, Polynom<Complex<Rational>>> getEquals();
    Polynom<Complex<Rational>> execute(Result& r)
    {
        Polynom<Complex<Rational>> A = makeOPZ(makeEquals(r));
        if (A.exception.error == "No error")
        {
            values.push_back(A);
            if (keys.size() < values.size())
                keys.push_back("");
            newNames.setVariable(keys.back(), values.back());
            return A;
        }
        else
        {
            A.coeff[0].re.numerator = 10e8;
            values.push_back(A);
            if (keys.size() < values.size())
                keys.push_back("");
        }
        return A;
    }
};