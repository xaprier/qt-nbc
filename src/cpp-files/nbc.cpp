//
// Created by xaprier on 8/23/22.
//

#include "../header-files/nbc.h"

std::string nbc::binToOct( const std::basic_string<char> &number ) {
	return number.length() == 0 ? "0.0" : nbc::decToOct(binToDec(number));
}

std::string nbc::binToDec( std::basic_string<char> number ) {
	if (number.length() == 0 || number == "0.0")
		return "0.0";

	std::string result;

	if (number.at(0) == '-') {
		number = number.substr(1, number.length());
		result += "-";
	}

	// split the decimal number as it supposed to be
	unsigned long long intPoint = 0;

	if (number.length() != 0) {
		intPoint = std::stoull(number.substr(0, (number.find('.') != -1) ? number.length() : number.find('.')));
	}
	unsigned long long decPoint = 0;
	if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
		decPoint = std::stoull(
				number.substr(number.find('.') + 1, number.length()));
	}

	// calculate the decimal number from binary
	unsigned long long integer = 0;
	for (int i = 0; intPoint > 0; i++) {
		integer += intPoint % 10 * pow(2, i);
		intPoint /= 10;
	}

	// add calculated integer value of decimal to result string
	result += std::to_string(integer);
	// add a '.' to the end
	result.push_back('.');
	// if there is an entered decimal point or not
	if (decPoint != 0) {
		// calculate the decimal point of binary to decimal
		double decimal = 0;
		for (int i = -1 * number.substr(number.find('.') + 1, number.length()).length(); decPoint > 0; i++) {
			decimal += decPoint % 10 * pow(2, i);
			decPoint /= 10;
		}

		// check the decimal point and add to end of string the char of number if decimal not fully 0
		while (true) {
			decimal *= 10;
			if (fmodl(decimal, 1.0) == 0) {
				result.push_back(static_cast<char>(decimal) + '0');
				break;
			} else {
				result.push_back(static_cast<char>((( unsigned long long ) decimal) + '0'));
				decimal -= ( unsigned long long ) decimal;
			}
		}
	} else {
		// if there isn't entered a decimal point enter .0
		result.push_back('0');
	}

	return result;
}

std::string nbc::binToHex( const std::basic_string<char> &number ) {
	return number.length() == 0 ? "0.0" : nbc::decToHex(binToDec(number));
}
