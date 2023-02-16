//
// Created by xaprier on 2/13/23.
//
#include "header-files/Number/Binary.h"

Binary Binary::operator/(const Binary& b) {
	// creating return object/converting other object
	Decimal first(*this), second(b);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the multiplying of decimal values
	first.num = this->div(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary Binary::operator/(const Octal& o) {
	// creating return object/converting other object
	Decimal first(*this), second(o);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the multiplying of decimal values
	first.num = this->div(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary Binary::operator/(const Decimal& second) {
	// creating return object/converting other object
	Decimal first(*this);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the multiplying of decimal values
	first.num = this->div(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary Binary::operator/(const Hexadecimal& h) {
	// creating return object/converting other object
	Decimal first(*this), second(h);

	try {
		if (second.num == "0.0")
			throw "Divide by 0 exception. Exiting...";
	} catch(const char* er) {
		std::cerr << er << std::endl;
		exit(1);
	}

	// calculate the multiplying of decimal values
	first.num = this->div(first.num, second.num);

	// remove the last indexes if it is 0
	while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
		first.num = first.num.substr(0, first.num.length() - 1);

	return first.toBin();
}

Binary &Binary::operator/=(const Binary &b) {
	*this = *this / b;
	return *this;
}

Binary &Binary::operator/=(const Octal &o) {
	*this = *this / o;
	return *this;
}

Binary &Binary::operator/=(const Decimal &d) {
	*this = *this / d;
	return *this;
}

Binary &Binary::operator/=(const Hexadecimal &h) {
	*this = *this / h;
	return *this;
}