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

template <class T> class Polynom : public Token
{
private:
    static const int N = 10000;
    T coeff[N];
    int deg;
    Polynom<T> multByPowOfX(int);
public:
    Polynom();
    Polynom(const Polynom<T>&);
    Polynom(T);
    Polynom(string b)
    {
        Polynom a;
        a.deg = 1;
        coeff[0] = 1;
        coeff[1] = 2;
    };
    int& getDeg();
    T& getValue(const T& x);
    
    Polynom<T> operator=(const Polynom<T>&);
    T& operator[](const int);
    
    template<typename T1>
    friend std::ostream& operator<<(std::ostream&, Polynom<T1>);
    
    template<typename T1>
    friend std::istream& operator>>(std::istream&, Polynom<T1>&);
    
    Polynom<T> operator+(const Polynom<T>&);
    Polynom<T> operator-(const Polynom<T>&);
    Polynom<T> operator*(const Polynom<T>&);
    Polynom<T> operator/(const Polynom<T>&);
    Polynom<T> operator%(const Polynom<T>&);
    
    Polynom<T> operator+=(const Polynom<T>&);
    Polynom<T> operator-=(const Polynom<T>&);
    Polynom<T> operator*=(const Polynom<T>&);
    Polynom<T> operator/=(const Polynom<T>&);
    Polynom<T> operator%=(const Polynom<T>&);
    
};
template <class T> std::ostream& operator<<(std::ostream& os, Polynom<T> a)
{
    for (int i = 0; i <= a.deg; i++)
        os << a.coeff[i] << "   ";
    
    return os;
}
template <class T> std::istream& operator>>(std::istream& is, Polynom<T>& a)
{
    int n;
    is >> n;
    
    a.deg = n;
    for (int i = 0; i <= n; i++)
    {
        T value;
        is >> value;
        a[i] = value;
    }
    
    return is;
}
template <class T> Polynom<T>::Polynom()
{
    for (int i = 0; i < N; i++)
        coeff[i] = 0;
    
    deg = 0;
}
template <class T> Polynom<T>::Polynom(const Polynom<T>& b)
{
    deg = b.deg;
    for (int i = 0; i < N; i++)
        coeff[i] = b.coeff[i];
}
template <class T> Polynom<T>::Polynom(T b)
{
    coeff[0] = b;
    
    for (int i = 1; i < N; i++)
    {
        coeff[i] = 0;
    }
    
    deg = 0;
}
template <class T> int& Polynom<T>::getDeg()
{
    return deg;
}
template <class T> T& Polynom<T>::getValue(const T& x)
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
template <class T> Polynom<T> Polynom<T>::multByPowOfX(int powOfX)
{
    for (int i = deg; i >= 0; i--)
        coeff[i + powOfX] = coeff[i];
    for (int i = powOfX-1; i >= 0; i--)
        coeff[i] = 0;
    
    deg = deg + powOfX;
    
    return *this;
}
template <class T> T& Polynom<T>::operator[](int i)
{
    if ((i < 0) || (i >= N))
    {
        std::cout << "Polynom::operator[] out of range\n";
    }
    
    return coeff[i];
}
template <class T> Polynom<T> Polynom<T>::operator=(const Polynom<T>& b)
{
    for (int i = 0; i<=deg; i++)
        coeff[i] = 0;
    deg = b.deg;
    for (int i = 0; i <= deg; i++)
        coeff[i] = b.coeff[i];
    
    return *this;
}
template <class T> Polynom<T> Polynom<T>::operator+(const Polynom<T>& b)
{
    Polynom<T> c;
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
template <class T> Polynom<T> Polynom<T>::operator-(const Polynom<T>& b)
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
template <class T> Polynom<T> Polynom<T>::operator*(const Polynom<T>& b)
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
    
    return c;
}
template <class T> Polynom<T> Polynom<T>::operator/(const Polynom<T>& b)     //   RETYPE!!!
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
template <class T> Polynom<T> Polynom<T>::operator%(const Polynom<T>& b)   // RETYPE!!!
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
template <class T> Polynom<T> Polynom<T>::operator+=(const Polynom<T>& b)
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
template <class T> Polynom<T> Polynom<T>::operator-=(const Polynom<T>& b)
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
template <class T> Polynom<T> Polynom<T>::operator*=(const Polynom<T>& b)
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
template <class T> Polynom<T> Polynom<T>::operator/=(const Polynom<T>& b)    //RETYPE!!!
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
template <class T> Polynom<T> Polynom<T>::operator%=(const Polynom<T>& b)    //RETYPE!!!
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