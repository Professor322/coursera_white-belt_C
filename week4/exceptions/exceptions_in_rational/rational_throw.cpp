//
// Created by professor on 02.10.19.
//

#include <iostream>

using namespace std;

class Rational {
public:
	Rational() { this->numerator = 0; this->denominator = 1;}
	Rational(int numerator, int denominator);
	int Numerator() const { return numerator; }
	int Denominator() const { return denominator; }

private:
	int numerator;
	int denominator;
};

Rational::Rational(int numerator, int denominator) : Rational(){
	int abs_num = abs(numerator), abs_denom = abs(denominator);

	if (numerator == 0) {
		return ;
	}
	if (denominator == 0) {
		throw invalid_argument("Invalid argument");
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
	if (denominator < 0) {
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

Rational operator / (const Rational& lhs, const Rational& rhs) {
	if (lhs.Denominator() * rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return (Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator()));
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

	stream >> numerator;
	if (stream && stream.peek() == '/') {
		stream.ignore(1);
		stream >> denominator;
		elem = Rational(numerator, denominator);
	}
	return stream;
}



int main() {

	Rational first, second;
	char operation;

	try {
		cin >> first;
		cin.ignore(1);
		cin >> operation;
		cin.ignore(1);
		cin >> second;
	} catch (const invalid_argument& i_err) {
		cout << i_err.what() << endl;
		return 1;
	}
	try {
		Rational result;
		switch (operation) {
			case '+': result = first + second; break;
			case '-': result = first - second; break;
			case '/': result = first / second; break;
			case '*': result = first * second; break;
		}
		cout << result << endl;
	} catch (const domain_error& d_err) {
		cout << d_err.what() << endl;
		return 2;
	}
	return 0;
}
