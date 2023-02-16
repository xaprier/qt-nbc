//
// Created by xaprier on 2/13/23.
//
#include "header-files/Number/Decimal.h"

Decimal Decimal::operator/(const Decimal& second) {
	// creating return object/converting other object
	Decimal result(*this);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the multiplying of decimal values
	result.num = this->div(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator/(const Binary& b) {
	// creating return object/converting other object
	Decimal result(*this), second(b);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the divide of decimal values
	result.num = this->div(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator/(const Octal& o) {
	// creating return object/converting other object
	Decimal result(*this), second(o);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the divide of decimal values
	result.num = this->div(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal Decimal::operator/(const Hexadecimal& h) {
	// creating return object/converting other object
	Decimal result(*this), second(h);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the divide of decimal values
	result.num = this->div(result.num, second.num);

	// remove the last indexes if it is 0
	while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
		result.num = result.num.substr(0, result.num.length() - 1);

	return result;
}

Decimal &Decimal::operator/=(const Decimal &d) {
	*this = *this / d;
	return *this;
}

Decimal &Decimal::operator/=(const Binary &b) {
	*this = *this / b;
	return *this;
}

Decimal &Decimal::operator/=(const Octal &o) {
	*this = *this / o;
	return *this;
}

Decimal &Decimal::operator/=(const Hexadecimal &h) {
	*this = *this / h;
	return *this;
}