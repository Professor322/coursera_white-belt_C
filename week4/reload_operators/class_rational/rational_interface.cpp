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

Rational	operator+(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator() + lhs.Numerator() * rhs.Denominator(),
			rhs.Denominator() * lhs.Denominator());
}

Rational	operator-(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator() - lhs.Numerator() * rhs.Denominator(),
					rhs.Denominator() * lhs.Denominator());
}

Rational	operator*(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Numerator(),
			rhs.Denominator()  * lhs.Denominator());
}

Rational	operator/(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator(),
			rhs.Denominator() * lhs.Numerator());
}

bool operator==(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}

bool operator<(const Rational& rhs, const Rational& lhs) {
	if (rhs.Denominator() == lhs.Denominator()) {
		return rhs.Numerator() < lhs.Numerator();
	}
	return rhs.Numerator() * lhs.Denominator() < lhs.Numerator() * rhs.Denominator();
}

ostream&	operator<<(ostream& stream, const Rational& elem) {
	stream << elem.Numerator() << "/" << elem.Denominator();
	return stream;
}

istream&		operator>>(istream& stream, Rational& elem) {
	int numerator = 0;
	int denominator = 1;
	if (stream.tellg() != -1) {
		stream >> numerator;
		stream.ignore(1);
		stream >> denominator;
		elem = Rational(numerator, denominator);
	}
	return stream;
}
int main() {
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		cout << r1 << " " << r2 << endl;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}