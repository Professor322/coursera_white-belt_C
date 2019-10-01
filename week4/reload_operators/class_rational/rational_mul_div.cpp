//
// Created by Virgil Legros on 01/10/2019.
//

#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

class Rational {
public:
	//default constructor creates fraction with numerator 0 and denominator 1
	Rational() {
		this->numerator = 0;
		this->denominator = 1;
	}
	Rational(int numerator, int denominator);
	int Numerator() const { return numerator; }
	int Denominator() const { return denominator; }
	void SetNumerator(int numerator) {this->numerator = numerator; }
	void SetDenominator(int denominator) {this->denominator = denominator; }
private:
	int numerator;
	int denominator;
};

//parameterized constructor reduces fraction
//if fraction is negative than only numerator is negative
//if numerator is zero than parameterized constructor calls for default constructor
Rational::Rational(int numerator, int denominator) : Rational(){
	int abs_num = abs(numerator), abs_denom = abs(denominator);

	if (numerator == 0) {
		return ;
	}
	while (abs_num > 0 && abs_denom > 0) {
		if (abs_num > abs_denom) {
			abs_num %= abs_denom;
		} else {
			abs_denom %= abs_num;
		}
	}
	int divider = abs_num + abs_denom;
	this->numerator = numerator / divider;
	this->denominator = denominator / divider;
	if ((numerator < 0 && denominator < 0) || denominator < 0) {
		this->numerator = -this->numerator;
		this->denominator = -this->denominator;
	}
}

Rational	operator*(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Numerator(),
					rhs.Denominator()  * lhs.Denominator());
}

Rational	operator/(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator(),
					rhs.Denominator() * lhs.Numerator());
}

Rational	operator+(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator() + lhs.Numerator() * rhs.Denominator(),
					rhs.Denominator() * lhs.Denominator());
}

Rational	operator-(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator() - lhs.Numerator() * rhs.Denominator(),
					rhs.Denominator() * lhs.Denominator());
}

bool operator==(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}
