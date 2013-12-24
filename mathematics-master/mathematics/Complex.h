#pragma once
#include "Number.h"
#include <iostream>

using std::istream;
using std::ostream;

template <class T>
class Complex : public Number
{
private:
    double re;
    double im;

public:
    Complex(void)
    {      
    re = 0;
    im = 0;
    }
    Complex(double temp1, double temp2)
{
    this->re = re;
    this->im = im;
}
    Complex(double temp)
{
    this->re = re;
}
    ~Complex(void)
{}

    Complex operator + (const Complex& temp)
{
    Complex<T> temp1;
    temp1.re = this->re + temp.re;
    temp1.im = this->im + temp.im;
    return temp1;
};
    Complex operator - (const Complex& temp)
{
    Complex<T> temp1;
    temp1.re = this->re - temp.re;
    temp1.im = this->im - temp.im;
    return temp1;
};
    Complex operator * (const Complex& temp)
{
    Complex<T> temp1;
    temp1.re = this->re * temp.re - this->im * temp.im;
    temp1.im = this->im * temp.re + this->re * temp.im;
    return temp1;

};
    Complex operator + (double& temp)
{
    Complex<T> temp1;
    temp1.re = this->re + temp;
    temp1.im = this->im;
    return temp1;
};
    Complex operator - (double& temp)
{
    Complex<T> temp1;
    temp1.re = this->re - temp;
    temp1.im = this->im;
    return temp1;;
};
    Complex operator * (double& temp)
{
    Complex<T> temp1;
    temp1.re = this->re * temp;
    temp1.im = this->im * temp;
    return temp1;
};
    template <class T1> friend ostream& operator << (ostream& os, const Complex<T1>& temp)
{
    int re = temp.re;
    int im = temp.im;
	if (!im)
	{
		cout << re;
		return os;
	}
	if (re)
		cout << re << " ";
	if (im < 0)
    {
        cout << "- " << -im << "i";
    }
	else
	{
		cout << "+ " << im << "i";;
	}
    return os;
};
    template <class T1> friend istream& operator >> (istream& is, Complex<T1>& temp);
};

