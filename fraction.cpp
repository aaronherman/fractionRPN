#include "fraction.h"

int gcd(int x, int y) {
  if (y==0)
    return x;

  return gcd(y, x%y);
}


Fraction::Fraction(){
	top = 0;
	bottom = 1;
}

Fraction::Fraction(int numerator) { //setting
	top = numerator;
	bottom = 1;
}

Fraction::Fraction(int numerator, int denominator) {

	int divisor = gcd(numerator, denominator);

	top = numerator/divisor;
	bottom = denominator/divisor;
}

int Fraction::numerator() const{
	return top;
}

int Fraction::denominator() const{
	return bottom;
}

double Fraction::asDouble() const{
	return (double) top / (double) bottom;
}

Fraction Fraction::add(const Fraction& other) const{
	int num,den;

	num = other.numerator() * denominator() + numerator() * other.denominator();
	den = other.denominator() * denominator();

	Fraction f(num,den);
	return f;
}

Fraction Fraction::subtract(const Fraction& other) const{
	int num,den;

	num = other.numerator() * denominator() - numerator() * other.denominator();
	den = other.denominator() * denominator();

	Fraction f(num,den);
	return f;
}

Fraction Fraction::divide(const Fraction& other) const{
	int num,den;

	num = other.denominator() * numerator();
	den = other.numerator() * denominator();

	Fraction f(num,den);
	return f;
}

Fraction Fraction::multiply(const Fraction& other) const{
	int num,den;

	num = other.numerator() * numerator();
	den = other.denominator() * denominator();

	Fraction f(num,den);
	return f;
}



Fraction operator+(const Fraction& a, const Fraction& b) {
	return a.add(b);
}
Fraction operator-(const Fraction& a, const Fraction& b) {
	return a.subtract(b);
}
Fraction operator/(const Fraction& a, const Fraction& b) {
	return a.divide(b);
}
Fraction operator*(const Fraction& a, const Fraction& b) {
	return a.multiply(b);
}

ostream& operator<<(ostream& sout, const Fraction& frac) {
	sout << frac.numerator();

	if (frac.denominator() != 1)
	sout << "/" << frac.denominator();
	return sout;

}
