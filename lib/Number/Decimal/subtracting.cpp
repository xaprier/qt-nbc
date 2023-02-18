//
// Created by xaprier on 2/13/23.
//
#include "../Decimal.h"

Decimal Decimal::operator-(const Decimal& second) {
	// Converting values to Decimal/Create result object
	Decimal result(*this);

	// calculate the subtracting of decimal values
	result.num = this->sub(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator-(const Binary& b) {
	// Converting values to Decimal/Create result object
	Decimal result(*this), second(b);

	// calculate the subtracting of decimal values
	result.num = this->sub(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator-(const Octal& o) {
	// Converting values to Decimal/Create result object
	Decimal result(*this), second(o);

	// calculate the subtracting of decimal values
	result.num = this->sub(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator-(const Hexadecimal& h) {
	// Converting values to Decimal/Create result object
	Decimal result(*this), second(h);

	// calculate the subtracting of decimal values
	result.num = this->sub(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal &Decimal::operator-=(const Decimal &d) {
	*this = *this - d;
	return *this;
}

Decimal &Decimal::operator-=(const Binary &b) {
	*this = *this - b;
	return *this;
}

Decimal &Decimal::operator-=(const Octal &o) {
	*this = *this - o;
	return *this;
}

Decimal &Decimal::operator-=(const Hexadecimal &h) {
	*this = *this - h;
	return *this;
}