//
// Created by Virgil Legros on 01/10/2019.
//

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