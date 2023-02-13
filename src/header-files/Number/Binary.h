#ifndef BINARY_H
#define BINARY_H

#include "Decimal.h"
#include "Octal.h"
#include "Hexadecimal.h"
#include <iostream>

class Binary : public BaseClass {
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

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Binary &b);

	// operator overloadings of summing
	Binary operator+(const Binary& b);
    Binary operator+(const Octal& o);
    Binary operator+(const Decimal& second);
    Binary operator+(const Hexadecimal& h);
	// operator overloadings of substraction
	Binary operator-(const Binary& b);
	Binary operator-(const Octal& o);
	Binary operator-(const Decimal& second);
	Binary operator-(const Hexadecimal& h);
	// operator overloadings of multiply
	Binary operator*(const Binary& b);
	Binary operator*(const Octal& o);
	Binary operator*(const Decimal& second);
	Binary operator*(const Hexadecimal& h);
	// operator overloadings of divide
	Binary operator/(const Binary& b);
	Binary operator/(const Octal& o);
	Binary operator/(const Decimal& second);
	Binary operator/(const Hexadecimal& h);
	// operator overloadings of remainder
	Binary operator%(const Binary& b);
	Binary operator%(const Octal& o);
	Binary operator%(const Decimal& second);
	Binary operator%(const Hexadecimal& h);
	// assignment operator overloadings
	Binary &operator=(const Binary &b);

	Binary &operator+=(const Binary &b);
	Binary &operator+=(const Octal &o);
	Binary &operator+=(const Decimal &second);
	Binary &operator+=(const Hexadecimal &h);

	Binary &operator-=(const Binary &b);
	Binary &operator-=(const Octal &o);
	Binary &operator-=(const Decimal &d);
	Binary &operator-=(const Hexadecimal &h);

	Binary &operator*=(const Binary &b);
	Binary &operator*=(const Octal &o);
	Binary &operator*=(const Decimal &d);
	Binary &operator*=(const Hexadecimal &h);

	Binary &operator/=(const Binary &b);
	Binary &operator/=(const Octal &o);
	Binary &operator/=(const Decimal &d);
	Binary &operator/=(const Hexadecimal &h);

	Binary &operator%=(const Binary &b);
	Binary &operator%=(const Octal &o);
	Binary &operator%=(const Decimal &d);
	Binary &operator%=(const Hexadecimal &h);
};

#endif  // BINARY_H
