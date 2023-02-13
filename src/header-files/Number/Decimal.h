#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>

#include "Binary.h"
#include "Hexadecimal.h"
#include "Octal.h"

class Decimal : public BaseClass {
  public:
    explicit Decimal(std::string num = "0.0");
    explicit Decimal(const Octal &o);
    explicit Decimal(const Binary &b);
    explicit Decimal(const Hexadecimal &h);
    Decimal(const Decimal &d);

    Octal toOct() override;
    Decimal toDec() override;
    Binary toBin() override;
    Hexadecimal toHex() override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Decimal &d);

    // operator overloadings of summing
    Decimal operator+(const Decimal& d);
    Decimal operator+(const Binary& b);
    Decimal operator+(const Octal& o);
    Decimal operator+(const Hexadecimal& h);
    // operator overloadings of substraction
    Decimal operator-(const Decimal& second);
    Decimal operator-(const Binary& b);
    Decimal operator-(const Octal& o);
    Decimal operator-(const Hexadecimal& h);
    // operator overloadings of multiply
    Decimal operator*(const Decimal& second);
    Decimal operator*(const Binary& b);
    Decimal operator*(const Octal& o);
    Decimal operator*(const Hexadecimal& h);
    // operator overloadings of divide
    Decimal operator/(const Decimal& second);
    Decimal operator/(const Binary& b);
    Decimal operator/(const Octal& o);
    Decimal operator/(const Hexadecimal& h);
    // operator overloadings of remainder
    Decimal operator%(const Decimal& second);
    Decimal operator%(const Binary& b);
    Decimal operator%(const Octal& o);
    Decimal operator%(const Hexadecimal& h);
    // assignment operator overloadings
	Decimal &operator=(const Decimal &d);

	Decimal &operator+=(const Decimal &d);
	Decimal &operator+=(const Binary &b);
	Decimal &operator+=(const Octal &o);
	Decimal &operator+=(const Hexadecimal &h);

	Decimal &operator-=(const Decimal &d);
	Decimal &operator-=(const Binary &b);
	Decimal &operator-=(const Octal &o);
	Decimal &operator-=(const Hexadecimal &h);

	Decimal &operator*=(const Decimal &d);
	Decimal &operator*=(const Binary &b);
	Decimal &operator*=(const Octal &o);
	Decimal &operator*=(const Hexadecimal &h);

	Decimal &operator/=(const Decimal &d);
	Decimal &operator/=(const Binary &b);
	Decimal &operator/=(const Octal &o);
	Decimal &operator/=(const Hexadecimal &h);

	Decimal &operator%=(const Decimal &d);
	Decimal &operator%=(const Binary &b);
	Decimal &operator%=(const Octal &o);
	Decimal &operator%=(const Hexadecimal &h);
};

#endif  // DECIMAL_H
