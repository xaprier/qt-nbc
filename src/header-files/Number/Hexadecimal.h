#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include "Decimal.h"
#include "Binary.h"
#include "Octal.h"

class Hexadecimal : public BaseClass {
  public:
	explicit Hexadecimal(std::string num = "0.0");
	explicit Hexadecimal(const Octal &o);
	explicit Hexadecimal(const Decimal &d);
	explicit Hexadecimal(const Binary &b);
	Hexadecimal(const Hexadecimal &h);

	Octal toOct() override;
	Decimal toDec() override;
	Binary toBin() override;
	Hexadecimal toHex() override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Hexadecimal &h);

	// operator overloadings of summing
	Hexadecimal operator+(const Hexadecimal& h);
	Hexadecimal operator+(const Binary& b);
	Hexadecimal operator+(const Octal& o);
	Hexadecimal operator+(const Decimal& second);
	// operator overloadings of substraction
	Hexadecimal operator-(const Hexadecimal& h);
	Hexadecimal operator-(const Binary& b);
	Hexadecimal operator-(const Octal& o);
	Hexadecimal operator-(const Decimal& second);
	// operator overloadings of multiply
	Hexadecimal operator*(const Hexadecimal& h);
	Hexadecimal operator*(const Binary& b);
	Hexadecimal operator*(const Octal& o);
	Hexadecimal operator*(const Decimal& second);
	// operator overloadings of divide
	Hexadecimal operator/(const Hexadecimal& h);
	Hexadecimal operator/(const Binary& b);
	Hexadecimal operator/(const Octal& o);
	Hexadecimal operator/(const Decimal& second);
	// operator overloadings of remainder
	Hexadecimal operator%(const Hexadecimal& h);
	Hexadecimal operator%(const Binary& b);
	Hexadecimal operator%(const Octal& o);
	Hexadecimal operator%(const Decimal& second);
	// assignment operator overloadings
	Hexadecimal &operator=(const Hexadecimal &h);

	Hexadecimal &operator+=(const Hexadecimal &h);
	Hexadecimal &operator+=(const Binary &b);
	Hexadecimal &operator+=(const Octal &o);
	Hexadecimal &operator+=(const Decimal &d);

	Hexadecimal &operator-=(const Hexadecimal &h);
	Hexadecimal &operator-=(const Binary &b);
	Hexadecimal &operator-=(const Octal &o);
	Hexadecimal &operator-=(const Decimal &d);

	Hexadecimal &operator*=(const Hexadecimal &h);
	Hexadecimal &operator*=(const Binary &b);
	Hexadecimal &operator*=(const Octal &o);
	Hexadecimal &operator*=(const Decimal &d);

	Hexadecimal &operator/=(const Hexadecimal &h);
	Hexadecimal &operator/=(const Binary &b);
	Hexadecimal &operator/=(const Octal &o);
	Hexadecimal& operator/=(const Decimal& d);

	Hexadecimal &operator%=(const Hexadecimal &h);
	Hexadecimal &operator%=(const Binary &b);
	Hexadecimal &operator%=(const Octal &o);
	Hexadecimal &operator%=(const Decimal &d);
};

#endif  // HEXADECIMAL_H
