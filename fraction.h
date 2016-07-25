#ifndef fraction_h
#define fraction_h

#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator,int demominator);
	int numerator() const;
	int denominator() const;
	double asDouble() const;
	Fraction add(const Fraction&) const;
	Fraction subtract(const Fraction&) const;
	Fraction divide(const Fraction&) const;
	Fraction multiply(const Fraction&) const;


private:
	int top;
	int bottom;
};

Fraction operator+(const Fraction& a, const Fraction& b);
Fraction operator-(const Fraction& a, const Fraction& b);
Fraction operator*(const Fraction& a, const Fraction& b);
Fraction operator/(const Fraction& a, const Fraction& b);
ostream& operator<<(ostream&, const Fraction& f);

#endif
