#pragma once
#include "Token.h"
#include <string>
#include <iostream>

/*//implement templated class Polynom.
//you can use following operations: T + T, T - T, T * T, T / T, T ^ int

//you have to overload following operators: 
//Polynom + Polynom, Polynom * Polynom, Polynom - Polynom, Polynom ^ int

//also you have to implement Polynom(string), Polynom(), 
//and of course Polynom(const Polynom&). The last one is IMPORTANT.





//important remark 1: there's two different ways of implementing Polynom.


//FIRST
//store coeficients of Polynom using map<int, T>
//the first parameter of map is the degree, and the second is the coefficient.

//for example, if you have 3x^5 - 10x^2 + 7x - 30, your map is something like:
//{ 5 -> 3; 2 -> -10; 1 -> 7; 0 - > -30 }

//storing your coefficients in this way (NOT using array/list/vector) can save memory in the best way.
//(because if you store your coefficients in the array, take a look at the next Polynom: x^10000 + 1

//SECOND
//storing coefficients of Polynom, using vector<T>
//more convinient way, but if the degree of polynom is high, you can eat too much memory

//(using map you can avoid it)


//important remark 2: don't worry about ": public Token", it's for my needs (for parsing input string)*/

#ifndef __Test__Polinomials__
#define __Test__Polinomials__

using namespace std;

template<class Numb>
class Polynom : public Token
{
private:
    static const int N = 10000;
    Numb coeff[N];
    int deg;
    Polynom<Numb> multByPowOfX(int);

public:
    Polynom();
    Polynom(const Polynom<Numb>&);
    Polynom(Numb);
    Polynom(std::string D)
    {
        for (int i = 0; i < N; ++i)
        {
            coeff[i] = 0;
        }
        if(D =="x")
        {
            coeff[1] = 1;
            deg = 1;
        }
        else
        {
            coeff[0] = stod(D);
            deg = 0;
        }
           
    }
    int& getDeg();
    Numb& getValue(const Numb& x);

    Polynom<Numb> operator=(const Polynom<Numb>&);
    Numb& operator[](const int);

    Polynom<Numb> operator()(const Polynom<Numb>&);

    template<typename T>
    friend std::ostream& operator<<(std::ostream&, Polynom<T>);

    template<typename T>
    friend std::istream& operator>>(std::istream&, Polynom<T>&);

    Polynom<Numb> operator+(const Polynom<Numb>&);
    Polynom<Numb> operator-(const Polynom<Numb>&);
    Polynom<Numb> operator*(const Polynom<Numb>&);
    Polynom<Numb> operator/(const Polynom<Numb>&);
    Polynom<Numb> operator%(const Polynom<Numb>&);
    Polynom<Numb> operator^(const Polynom<Numb>&);
    Polynom<Numb> operator/(Numb a);

    Polynom<Numb> operator+=(const Polynom<Numb>&);
    Polynom<Numb> operator-=(const Polynom<Numb>&);
    Polynom<Numb> operator*=(const Polynom<Numb>&);
    Polynom<Numb> operator/=(const Polynom<Numb>&);
    Polynom<Numb> operator%=(const Polynom<Numb>&);
    Polynom<Numb> operator^=(int);
    Polynom<Numb> operator/=(Numb a);

    bool operator==(const Polynom<Numb>&);
    bool operator!=(const Polynom<Numb>&);
};
#endif
template<class Numb> std::ostream& operator<<(std::ostream& os, Polynom<Numb> a)
{
    if (a.deg == 0)
    {
        os <<  a.coeff[0];
        return os;
    }
    if (a.deg == 1)
    {
        if (a.coeff[1] == 1)
            os << "x";
        else
        {
            if (a.coeff[1] == - 1)
                os << "-x";
            else
                os << a.coeff[1] << "x";
        }
        if (a.coeff[0] != 0)
        {
            if (a.coeff[0] > 0)
                os << "+" << a.coeff[0];
            else
                os << a.coeff[0];
        }
        return os;
    }
    if (a.deg > 1)
    {
        if (a.coeff[a.deg] == 1)
            os << "x^" << a.deg;
        else
        {
            if (a.coeff[a.deg] == - 1)
                os << "-x^"<< a.deg;
            else
                os << a.coeff[a.deg] << "x^" << a.deg;
        }
        for (int i = a.deg - 1; i >= 2; --i)
        {
            if (a.coeff[i] != 0)
            {
                if (a.coeff[i] > 0)
                    os << "+" << a.coeff[i] << "x^" << i;
                else
                    os << a.coeff[i] << "x^" << i;
            }
        }
        if (a.coeff[1] == 1)
            os << "+x";
        else
        {
            if (a.coeff[1] == -1)
                os << "-x";
            else
                if (a.coeff[1] > 0)
                    os << "+"<<a.coeff[1] << "x";
                else
                    if (a.coeff[1] < 0)
                        os << a.coeff[1] << "x";
        }
        if (a.coeff[0] != 0)
        {
            if (a.coeff[0] > 0)
                os << "+" << a.coeff[0];
            else
                os << a.coeff[0];
        }
    }



    /*if(a.deg == 0)
    {
        os << a[0];
        return os;
    }

    os << "(" << a[a.deg] << ")" << "x";
    if(a.deg > 1)
        os << "^" << a.deg;

    for (int i = a.deg - 1; i > 1; i--)
        if (a[i] != 0)
            os << "+" << "(" << a[i] << ")" << "x^" << i;
    if (a.deg > 1 && a[1] != 0)
        os << "+" << "(" << a[1] << ")" << "x";
    if (a.deg > 0 && a[0] != 0)
        os << "+" << "(" << a[0] << ")";

        */
    return os;
}
template<class Numb> std::istream& operator>>(std::istream& is, Polynom<Numb>& a)
{
    int n;
    is >> n;

    a.deg = n;
    for (int i = 0; i <= n; i++)
    {
        Numb value;
        is >> value;
        a[i] = value;
    }

    return is;
}
template<class Numb> Polynom<Numb>::Polynom()
{
    for (int i = 0; i < N; i++)
        coeff[i] = 0;

    deg = 0;
}
template<class Numb> Polynom<Numb>::Polynom(const Polynom<Numb>& b)
{
    deg = b.deg;
    for (int i = 0; i < N; i++)
        coeff[i] = b.coeff[i];
}
template<class Numb> Polynom<Numb>::Polynom(Numb b)
{
    coeff[0] = b;

    for (int i = 1; i < N; i++)
    {
        coeff[i] = 0;
    }

    deg = 0;
}   ////template<class Numb>  //Polynom<Numb>::Polynom(std::string b)
template<class Numb> Numb& Polynom<Numb>::operator[](int i)
{
    if ((i < 0) || (i >= N))
    {
        std::cout << "Polynom::operator[] out of range\n";
    }

    return coeff[i];
}
template<class Numb> int& Polynom<Numb>::getDeg()
{
    return deg;
}
template<class Numb> Numb& Polynom<Numb>::getValue(const Numb& x)
{
    Numb value = 0;
    int powerOfX = 1;

    for (int i = 0; i <= deg; i++)
    {
        value += coeff[i]*powerOfX;
        powerOfX *= x;
    }

    return value;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::multByPowOfX(int powOfX)
{
    for (int i = deg; i >= 0; i--)
        coeff[i + powOfX] = coeff[i];
    for (int i = powOfX-1; i >= 0; i--)
        coeff[i] = 0;

    deg = deg + powOfX;

    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator=(const Polynom<Numb>& b)
{
    for (int i = 0; i<=deg; i++)
        coeff[i] = 0;
    deg = b.deg;
    for (int i = 0; i <= deg; i++)
        coeff[i] = b.coeff[i];

    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator+(const Polynom<Numb>& b)
{
    Polynom<Numb> c;
    c.deg = 0;
    int degB = b.deg;
    int maxDeg = 0;
    maxDeg = degB > deg ? degB : deg;
    for (int i = 0; i <= maxDeg; i++)
    {
        c.coeff[i] = coeff[i] + b.coeff[i];
        if (!(c.coeff[i] == 0))
            c.deg = i;
    }

    return c;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator-(const Polynom<Numb>& b)
{
    Polynom c;
    c.deg = 0;
    int degB = b.deg;
    int maxDeg = 0;
    maxDeg = degB > deg ? degB : deg;
    for (int i = 0; i <= maxDeg; i++)
    {
        c.coeff[i] = coeff[i] - b.coeff[i];
        if (c.coeff[i] != 0)
            c.deg = i;
    }

    return c;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator*(const Polynom<Numb>& b)
{
    Polynom<Numb> c;
    if (!(((coeff[0] == 0) && deg == 0) || ((b.coeff[0] == 0) && (b.deg == 0))))
    {
        for (int i = 0; i <= deg; i++)
        {
            for (int j = 0; j <= b.deg; j++)
            {
                c.coeff[i+j] += coeff[i] * b.coeff[j];
            }

        }

        for (int i = deg + b.deg; i >= 0; i--)
            if (c.coeff[i] != 0)
            {
                c.deg = i;
                break;
            }
    }

    return c;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator/(const Polynom<Numb>& b)
{
    Polynom c;
    Polynom temp;
    temp = b;
    Polynom rem;
    rem = *this;
    c.deg = rem.deg - b.deg;

    while (rem.deg >= b.deg)
    {
        c.coeff[rem.deg - b.deg] = rem.coeff[rem.deg]/b.coeff[b.deg];
        temp.multByPowOfX(rem.deg - b.deg);
        Polynom temp2;
        temp2.coeff[0] = rem.coeff[rem.deg] / b.coeff[b.deg];
        temp = temp * temp2;;
        rem = rem - temp;
        temp = b;
    }

    return c;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator%(const Polynom<Numb>& b)
{
    Polynom c;
    Polynom temp;
    temp = b;
    Polynom rem;
    rem = *this;
    c.deg = rem.deg - b.deg;

    while (rem.deg >= b.deg)
    {
        c.coeff[rem.deg - b.deg] = rem.coeff[rem.deg]/b.coeff[b.deg];
        temp.multByPowOfX(rem.deg - b.deg);
        Polynom temp2;
        temp2.coeff[0] = rem.coeff[rem.deg] / b.coeff[b.deg];
        temp = temp * temp2;;
        rem = rem - temp;
        temp = b;
    }

    return rem;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator^(const Polynom<Numb>& b)
{
    Polynom<Numb> temp(*this);
    Polynom<Numb> res(1);
    int n = b.coeff[0];
    while (n)
    {
        if(n & 1)
            res *= temp;
        temp *= temp;
        n >>= 1;
    }

    return res;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator+=(const Polynom<Numb>& b)
{
    int degB = b.deg;
    int maxDeg = 0;
    maxDeg = degB > deg ? degB : deg;
    for (int i = 0; i <= maxDeg; i++)
    {
        coeff[i] = coeff[i] + b.coeff[i];
        if (coeff[i] != 0)
            deg = i;
    }

    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator-=(const Polynom<Numb>& b)
{
    int degB = b.deg;
    int maxDeg = 0;
    maxDeg = degB > deg ? degB : deg;
    for (int i = 0; i <= maxDeg; i++)
    {
        coeff[i] = coeff[i] - b.coeff[i];
        if (coeff[i] != 0)
            deg = i;
    }

    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator*=(const Polynom<Numb>& b)
{
    Polynom c;
    if (!(((coeff[0] == 0) && deg == 0) || ((b.coeff[0] == 0) && (b.deg == 0))))
    {
        for (int i = 0; i <= deg; i++)
        {
            for (int j = 0; j <= b.deg; j++)
            {
                c.coeff[i+j] += coeff[i] * b.coeff[j];
            }

        }

        for (int i = deg + b.deg; i >= 0; i--)
            if (c.coeff[i] != 0)
            {
                c.deg = i;
                break;
            }
    }

    *this = c;
    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator/=(const Polynom<Numb>& b)
{
    Polynom c;
    Polynom temp;
    temp = b;
    Polynom rem;
    rem = *this;
    c.deg = rem.deg - b.deg;

    while (rem.deg >= b.deg)
    {
        c.coeff[rem.deg - b.deg] = rem.coeff[rem.deg]/b.coeff[b.deg];
        temp.multByPowOfX(rem.deg - b.deg);
        Polynom temp2;
        temp2.coeff[0] = rem.coeff[rem.deg] / b.coeff[b.deg];
        temp = temp * temp2;;
        rem = rem - temp;
        temp = b;
    }

    *this = c;
    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator%=(const Polynom<Numb>& b)
{
    Polynom c;
    Polynom temp;
    temp = b;
    Polynom rem;
    rem = *this;
    c.deg = rem.deg - b.deg;

    while (rem.deg >= b.deg)
    {
        c.coeff[rem.deg - b.deg] = rem.coeff[rem.deg]/b.coeff[b.deg];
        temp.multByPowOfX(rem.deg - b.deg);
        Polynom temp2;
        temp2.coeff[0] = rem.coeff[rem.deg] / b.coeff[b.deg];
        temp = temp * temp2;;
        rem = rem - temp;
        temp = b;
    }

    *this = rem;
    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator^=(int deg)
{
    Polynom<Numb> temp(*this);
    Polynom<Numb> res(1);
    while (deg)
    {
        if(deg & 1)
            res *= temp;
        temp *= temp;
        deg >>= 1;
    }
    *this = res;
    return *this;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator()(const Polynom<Numb>& b)
{
    Polynom<Numb> temp;
    Polynom<Numb> b1 = b;
    for (int i = 0; i <= this->deg; i++)
        temp += (b1^i) * (this->coeff[i]);
    return temp;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator/(Numb a)
{
    Polynom<Numb> ans(*this);
    ans.deg = 0;
    for (int i = 0; i <= this -> deg; i++)
    {
        ans[i] /= a;
        ans.deg = ans[i] != 0? i : ans.deg;
    }

    return ans;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator/=(Numb a)
{
    Polynom<Numb> ans(*this);
    ans.deg = 0;
    for (int i = 0; i <= this -> deg; i++)
    {
        ans[i] /= a;
        ans.deg = ans[i] != 0? i : ans.deg;
    }

    *this = ans;
    return *this;
}
template<class Numb> bool Polynom<Numb>::operator==(const Polynom<Numb>& b)
{
    if (deg != b.deg)
        return false;

    for (int i = 0; i <= deg; i++)
        if (*this[i] != b[i])
            return false;

    return true;
}
template<class Numb> bool Polynom<Numb>::operator!=(const Polynom<Numb>& b)
{
    if (deg != b.deg)
        return true;

    for (int i = 0; i <= deg; i++)
        if (*this[i] != b[i])
            return true;

    return false;
}