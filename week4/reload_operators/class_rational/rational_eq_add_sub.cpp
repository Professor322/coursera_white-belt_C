//
// Created by Virgil Legros on 01/10/2019.
//

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
