#pragma once
#include "Token.h"
#include <string>
#include <iostream>

#ifndef __Test__Polinomials__
#define __Test__Polinomials__

using namespace std;

template<class Numb>
class Polynom : public Token
{
private:
    static const int N = 1000;
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
            if (D == "i")
            {
                coeff[0].re = 0;
                coeff[0].im = 1;
                deg = 0;
            }
            else
            {
                unsigned int i;
                for (i = 0; i < D.length(); ++i)
                    if (isalpha(D[i]))
                        break;
                if (i == D.length())
                {
                    coeff[0] = stod(D);
                    deg = 0;
                }
                else
                {
                    for(unsigned int j = 0; j < D.length(); ++j)
                        coeff[i] = int(D[j]);
                    deg = D.length() - 1;
                }
            }
        }
    }
    int& getDeg();

    Numb& getValue(const Numb& x);
    int getFirstGree()
    {
        return coeff[0].getRe();
    }
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
    Polynom<Numb> operator^(int&);
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
        if (a.coeff[1].re == 1 && a.coeff[1].im == 0)
            os << "x";
        else
        {
            if (a.coeff[1].re == - 1 && a.coeff[1].im == 0)
                os << "-x";
            else
                os << a.coeff[1] << "x";
        }
        if (a.coeff[0] != 0)
        {
            if (a.coeff[0].getRe() > 0)
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
                if (a.coeff[i].getRe() > 0)
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
                if (a.coeff[1].re > 0)
                    os << "+"<< a.coeff[1] << "x";
                else
                    if (a.coeff[1].re != 0)
                    os << a.coeff[1] << "x";
        }
        if (a.coeff[0] != 0)
        {
            if (a.coeff[0].re > 0)
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
        if (c.coeff[i].getRe() != 0)
            c.deg = i;
    }

    return c;
}
template<class Numb> Polynom<Numb> Polynom<Numb>::operator*(const Polynom<Numb>& b)
{
    Polynom<Numb> c;
   
    if (!(((coeff[0].re == 0) && deg == 0 && coeff[0].im == 0) || ((b.coeff[0].re == 0) && (b.deg == 0) && b.coeff[0].im == 0)))
    {
        for (int i = 0; i <= deg; i++)
        {
            for (int j = 0; j <= b.deg; j++)
            {
                c.coeff[i+j] += coeff[i] * b.coeff[j];
            }

        }

        for (int i = deg + b.deg; i >= 0; i--)
            if (c.coeff[i].re != 0 || c.coeff[0].im != 0)
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

    while (rem.deg >= b.deg && !(rem[0].re == 0 && rem[0].im == 0 && rem.deg == 0))
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
template<class Numb> Polynom<Numb> Polynom<Numb>::operator^(int& b)
{
    Polynom<Numb> temp(*this);
    Polynom<Numb> res(1);
    int n = b;
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
    if (!(((coeff[0].getRe() == 0) && deg == 0 && coeff[0].im == 0) || ((b.coeff[0].getRe() == 0) && (b.deg == 0) && b.coeff[0].im == 0)))
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