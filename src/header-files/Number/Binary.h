#ifndef BINARY_H
#define BINARY_H

#include "Decimal.h"
#include "Octal.h"
#include "Hexadecimal.h"
#include <iostream>

class Binary : public BaseClass {
  public:
	// expression must be in binary format("0b...")
	explicit Binary(std::string num = "0b0.0");
	// expression must be in decimal format(0)
	explicit Binary(const int &num);
	// expression must be in decimal format(0.0)
	explicit Binary(const double &num);
	// expression must be an octal object
	explicit Binary(const Octal &o);
	// expression must be an decimal object
	explicit Binary(const Decimal &d);
	// expression must be a hexadecimal object
	explicit Binary(const Hexadecimal &h);
	// expression must be a binary object
	Binary(const Binary &b);

	[[nodiscard]] Octal toOct() const override;
	[[nodiscard]] Decimal toDec() const override;
	[[nodiscard]] Binary toBin() const override;
	[[nodiscard]] Hexadecimal toHex() const override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Binary &b);

	// operator overloadings of summing
	Binary operator+(const Binary& b);
    Binary operator+(const Octal& o);
    Binary operator+(const Decimal& second);
    Binary operator+(const Hexadecimal& h);
	// operator overloadings of subtraction
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
	Binary &operator=(const Octal &o);
	Binary &operator=(const Decimal &d);
	Binary &operator=(const Hexadecimal &h);

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
