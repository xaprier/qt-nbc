#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>

#include "Binary.h"
#include "Hexadecimal.h"
#include "Octal.h"

class Decimal : public BaseClass {
  public:
	// expression must be in decimal format("0.0")
    explicit Decimal(std::string num = "0.0");
	// expression must be in decimal format(0)
	explicit Decimal(const int &num);
	// expression must be in decimal format(0.0)
	explicit Decimal(const double &num);
	// expression must be an octal object
    explicit Decimal(const Octal &o);
	// expression must be a binary object
    explicit Decimal(const Binary &b);
	// expression must be a hexadecimal object
    explicit Decimal(const Hexadecimal &h);
	// expression must be a decimal object
    Decimal(const Decimal &d);

    [[nodiscard]] Octal toOct() const override;
    [[nodiscard]] Decimal toDec() const override;
    [[nodiscard]] Binary toBin() const override;
    [[nodiscard]] Hexadecimal toHex() const override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Decimal &d);

    // operator overloadings of summing
    Decimal operator+(const Decimal& d);
    Decimal operator+(const Binary& b);
    Decimal operator+(const Octal& o);
    Decimal operator+(const Hexadecimal& h);
    // operator overloadings of subtraction
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
	Decimal &operator=(const Binary &b);
	Decimal &operator=(const Octal &o);
	Decimal &operator=(const Hexadecimal &h);

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
