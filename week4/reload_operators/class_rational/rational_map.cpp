//
// Created by Virgil Legros on 01/10/2019.
//

#include <iostream>
#include <sstream>
#include <set>
#include <map>

bool operator==(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator();
}

bool operator<(const Rational& rhs, const Rational& lhs) {
	if (rhs.Denominator() == lhs.Denominator()) {
		return rhs.Numerator() < lhs.Numerator();
	}
	return rhs.Numerator() * lhs.Denominator() < lhs.Numerator() * rhs.Denominator();
}
