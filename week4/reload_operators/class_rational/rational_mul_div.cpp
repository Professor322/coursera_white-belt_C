//
// Created by Virgil Legros on 01/10/2019.
//

#include <iostream>
#include <sstream>
#include <set>
#include <map>

Rational	operator*(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Numerator(),
					rhs.Denominator()  * lhs.Denominator());
}

Rational	operator/(const Rational& rhs, const Rational& lhs) {
	return Rational(rhs.Numerator() * lhs.Denominator(),
					rhs.Denominator() * lhs.Numerator());
}
