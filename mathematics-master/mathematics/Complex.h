#pragma once
#include "Number.h"
#include <iostream>

using namespace std;

template <class T>
class Complex
{
public:
    double re;
    double im;

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
        this->re = temp;
        this->im = 0;
    }
    Complex(int temp)
    {
        re = double(temp);
        im = double(0);
    }
    ~Complex()
    {}
    double getRe() const 
    {
        return this->re;
    }

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
    Complex operator / (const Complex& temp)
    {
        Complex<T> temp1;
        temp1.re = this->re / temp.re;
        temp1.im = this->im / temp.re;
        return temp1;
    }

    Complex operator += (const Complex& temp)
    {
        this->re = this->re + temp.re;
        this->im = this->im + temp.im;
        return *this;
    };
    Complex operator -= (const Complex& temp)
    {
        this->re = this->re - temp.re;
        this->im = this->im - temp.im;
        return *this;
    };
    Complex operator *= (const Complex& temp)
    {
        this->re = this->re * temp.re - this->im * temp.im;
        this->im = this->im * temp.re + this->re * temp.im;
        return *this;
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

    Complex operator + (int& temp)
    {
        Complex<T> temp1;
        temp1.re = this->re + temp;
        temp1.im = this->im;
        return temp1;
    };
    Complex operator - (int& temp)
    {
        Complex<T> temp1;
        temp1.re = this->re - temp;
        temp1.im = this->im;
        return temp1;;
    };
    Complex operator * (int& temp)
    {
        Complex<T> temp1;
        temp1.re = this->re * temp;
        temp1.im = this->im * temp;
        return temp1;
    };

    bool operator != (int& temp)
    {
        if (!this->re == temp && !this->im == 0)
            return true;
        else
            return false;
    };
    bool operator != (const Complex& temp)
    {
        if ((!(this->re == temp.re)) || (!(this->im == temp.im)))
            return true;
        else
            return false;
    };
    bool operator == (const Complex& temp)
    {
        if (*this != temp)
            return false;
        else
            return true;
    };
    bool operator == (int& temp)
    {
        if (this->re == temp || temp->im == 0)
            return true;
        else
            return false;
    };

    template <class T1> friend Complex<T1> operator+(double temp1, Complex<T1>& temp2)
    {
        return temp2 + temp1;
    }
    template <class T1> friend Complex<T1> operator-(double temp1, Complex<T1>& temp2)
    {
        return temp2 - temp1;
    }
    template <class T1> friend Complex<T1> operator*(double temp1, Complex<T1>& temp2)
    {
        return temp2*temp1;
    }
    template <class T1> friend Complex<T1> operator+(int temp1, Complex<T1>& temp2)
    {
        return temp2 + temp1;
    }
    template <class T1> friend Complex<T1> operator-(int temp1, Complex<T1>& temp2)
    {
        return temp2 - temp1;
    }
    template <class T1> friend Complex<T1> operator*(int temp1, Complex<T1>& temp2)
    {
        return temp2*temp1;
    }
    template <class T1> friend ostream& operator << (ostream& os, const Complex<T1>& temp)
    {
        double re = temp.re;
        double im = temp.im;
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

