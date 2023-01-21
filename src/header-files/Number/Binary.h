#ifndef BINARY_H
#define BINARY_H

#include "Decimal.h"
#include "Octal.h"
#include "Hexadecimal.h"
#include <iostream>

class Binary : public Number {
  public:
	explicit Binary(std::string num = "0.0");
	explicit Binary(const Octal &o);
	explicit Binary(const Decimal &d);
	explicit Binary(const Hexadecimal &h);
	Binary(const Binary &b);

	Octal toOct() override;
	Decimal toDec() override;
	Binary toBin() override;
	Hexadecimal toHex() override;

	friend std::ostream &operator<<(std::ostream &output, const Binary &b);

	// operator overloadings of summing
	Binary operator+(Binary b);
    Binary operator+(Octal o);
    Binary operator+(Decimal second);
    Binary operator+(Hexadecimal h);
	// operator overloadings of substraction
	Binary operator-(Binary b);
	Binary operator-(Octal o);
	Binary operator-(Decimal second);
	Binary operator-(Hexadecimal h);
	// operator overloadings of multiply
	Binary operator*(Binary b);
	Binary operator*(Octal o);
	Binary operator*(Decimal second);
	Binary operator*(Hexadecimal h);
	// operator overloadings of divide
	Binary operator/(Binary b);
	Binary operator/(Octal o);
	Binary operator/(Decimal second);
	Binary operator/(Hexadecimal h);
	// operator overloadings of remainder
	Binary operator%(Binary b);
	Binary operator%(Octal o);
	Binary operator%(Decimal second);
	Binary operator%(Hexadecimal h);
};

#endif  // BINARY_H
