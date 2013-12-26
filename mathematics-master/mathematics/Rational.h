#ifndef Test_Rational_h
#define Test_Rational_h
#include <iostream>
class Rational
{
private:
	int numerator;
	int denominator;
    
    void makeGood();
public:
	Rational();
	Rational(int);
    
    double getDouble();
    
	Rational operator=(const Rational&);
	Rational operator+(const Rational&);
	Rational operator-(const Rational&);
	Rational operator/(const Rational&);
	Rational operator*(const Rational&);
	Rational operator%(const Rational&);
	Rational operator^(int n);
	
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    
    bool operator==(const Rational&);
    bool operator!=(const Rational&);
    
    friend Rational operator+(int, const Rational&);
    friend Rational operator-(int, const Rational&);
    friend Rational operator*(int, const Rational&);
    friend Rational operator/(int, const Rational&);
    
};
#endif
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}
Rational::Rational(int a)
{
	numerator = a;
	denominator = 1;
}
void Rational::makeGood()
{
	if (this->denominator < 0)
	{
		this -> numerator *= -1;
		this -> denominator *= -1;
	}
	Rational temp;
    temp.numerator = this->numerator;
	temp.denominator = this->denominator;
	while((temp.numerator!=0) && (temp.denominator!=0))
		if (temp.numerator > temp.denominator)
            temp.numerator %= temp.denominator;
		else
            temp.denominator %= temp.numerator;
	int divider = temp.numerator + temp.denominator;
    
	this->numerator /= divider;
	this->denominator /= divider;
}
double Rational::getDouble()
{
    return 1.*numerator/denominator;
}
Rational Rational::operator=(const Rational& a)
{
	this->numerator = a.numerator;
	this->denominator = a.denominator;
	return * this;
}
Rational Rational::operator+(const Rational& a)
{
	Rational temp;
	temp.numerator = (this->numerator * a.denominator) + (this->denominator * a.numerator);
	temp.denominator = this->denominator * a.denominator;
	temp.makeGood();
	return temp;
}
Rational Rational::operator-(const Rational& a)
{
	Rational temp;
	temp.numerator = (this->numerator * a.denominator) - (this->denominator * a.numerator);
	temp.denominator = this->denominator * a.denominator;
	temp.makeGood();
	return temp;
}
Rational Rational::operator*(const Rational& a)
{
	Rational temp;
	temp.numerator = this->numerator * a.numerator;
	temp.denominator = this->denominator * a.denominator;
	temp.makeGood();
	return temp;
}
Rational Rational::operator/(const Rational& a)
{
	Rational temp;
	temp.numerator = this->numerator * a.denominator;
	temp.denominator = this->denominator * a.numerator;
	temp.makeGood();
	return temp;
}
Rational Rational::operator%(const Rational& a)
{
	Rational temp;
	return temp;
}
Rational Rational::operator^(int n)
{
	Rational res(1);
	Rational temp(*this);
	while (n)
	{
		if (n & 1)
			res = res * temp;
		temp = temp * temp;
		n >>= 2;
	}
    
	return res;
}
bool Rational::operator==(const Rational& b)
{
    if ((this->numerator == b.numerator) && (this->denominator == b.denominator))
        return true;
    return false;
}
bool Rational::operator!=(const Rational& b)
{
    if ((this->numerator == b.numerator) && (this->denominator == b.denominator))
        return false;
    return true;
}
Rational operator+(int a, const Rational& b)
{
    Rational c;
    Rational b1(b);
    c = b1 + a;
    return c;
}
Rational operator-(int a, const Rational& b)
{
    Rational c;
    Rational b1(b);
    c = b1 - a;
    return c;
}
Rational operator*(int a, const Rational& b)
{
    Rational c;
    Rational b1(b);
    c = b1 * a;
    return c;
}
Rational operator/(int a, const Rational& b)
{
    Rational c;
    Rational b1(b);
    c = b1 / a;
    return c;
}
std::ostream& operator<<(std::ostream& os, const Rational& a)
{
    os << a.numerator;
    if (a.denominator != 1)
        os << "/" << a.denominator;
    
    return os;
}
