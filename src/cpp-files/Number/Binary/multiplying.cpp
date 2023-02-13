//
// Created by xaprier on 2/13/23.
//
#include "header-files/Number/Binary.h"

Binary Binary::operator*(const Binary& b) {
	// convert all values to decimal for multiply
	Decimal first(*this), second(b);

	// calculate the multiplying of decimal values
	first.num = this->mul(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	// then convert the multiplying of values to binary and return
	return first.toBin();
}

Binary Binary::operator*(const Octal& o) {
	// convert all values to decimal for multiply
	Decimal first(*this), second(o);

	// calculate the multiplying of decimal values
	first.num = this->mul(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary Binary::operator*(const Decimal& second) {
	// convert all values to decimal for multiply
	Decimal first(*this);

	// calculate the multiplying of decimal values
	first.num = this->mul(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary Binary::operator*(const Hexadecimal& h) {
	// convert all values to decimal for multiply
	Decimal first(*this), second(h);

	// calculate the multiplying of decimal values
	first.num = this->mul(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary &Binary::operator*=(const Binary &b) {
	*this = *this * b;
	return *this;
}

Binary &Binary::operator*=(const Octal &o) {
	*this = *this * o;
	return *this;
}

Binary &Binary::operator*=(const Decimal &d) {
	*this = *this * d;
	return *this;
}

Binary &Binary::operator*=(const Hexadecimal &h) {
	*this = *this * h;
	return *this;
}