//
// Created by xaprier on 8/23/22.
//
#include <cmath>
#include <iostream>
#include <algorithm>
#include "../header-files/nbc.h"

std::string nbc::binToDec( const std::string &number ) {
	std::string result;
	// split the decimal number as it supposed to be
	long int intPoint = 0;
	if (number.length() != 0) {
		intPoint = std::stoi(number.substr(0, number.find('.')));
	}
	long int decPoint = 0;
	if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
		decPoint = std::stoi(
				number.substr(number.find('.') + 1, number.length())
		);
	}

	// calculate the decimal number from binary
	long int integer = 0;
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
		// adding our result to end of result string
		result += std::to_string(
				static_cast<long int>(decimal * pow(10, number.substr(number.find('.') + 1, number.length()).length
						()))
		);
	} else {
		// if there isn't entered a decimal point enter .0
		result.push_back('0');
	}

	return result;
}

std::string nbc::binToOct( const std::string &number ) {
	// convert the binary number to decimal
	std::string decimalNumber = nbc::binToDec(number);
	std::string result = decimalNumber;

	return result;
}

std::string nbc::decToOct( const std::string &number ) {
	std::string result;
	// split the decimal number as it supposed to be
	long int intPoint = 0;
	if (number.length() != 0) {
		intPoint = std::stoi(number.substr(0, number.find('.')));
	}
	double decPoint = 0;
	if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
		decPoint = std::stod(
				number.substr(0, number.length())
		);
		decPoint -= static_cast<long int>(decPoint);
	}

	// calculate the octal number from decimal
	while (intPoint > 0) {
		result += (static_cast<char>(intPoint % 8) + '0');
		intPoint /= 8;
	}
	std::reverse(result.begin(), result.end());

	// add a '.' to the end
	result.push_back('.');
	// if there is an entered decimal point or not
	if (decPoint != 0) {
		while (true) {
			decPoint *= 8;
			if (fmodl(decPoint, 1.0) == 0) {
				result.push_back(static_cast<char>(decPoint) + '0');
				break;
			} else {
				result.push_back(static_cast<char>((( int ) decPoint) + '0'));
				decPoint -= ( int ) decPoint;
			}
		}
	} else {
		result.push_back('0');
	}
	return result;
}
