#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include "Decimal.h"
#include "Binary.h"
#include "Octal.h"

class Hexadecimal : public BaseClass {
  public:
	// expression must be in hexadecimal format("0x...")
	explicit Hexadecimal(std::string num = "0x0.0");
	// expression must be decimal format(0)
	explicit Hexadecimal(const int &num);
	// expression must be decimal format(0.0)
	explicit Hexadecimal(const double &num);
	// expression must be octal object
	explicit Hexadecimal(const Octal &o);
	// expression must be decimal object
	explicit Hexadecimal(const Decimal &d);
	// expression must be binary object
	explicit Hexadecimal(const Binary &b);
	// copy constructor
	Hexadecimal(const Hexadecimal &h);

	[[nodiscard]] Octal toOct() const override;
	[[nodiscard]] Decimal toDec() const override;
	[[nodiscard]] Binary toBin() const override;
	[[nodiscard]] Hexadecimal toHex() const override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Hexadecimal &h);

	// operator overloadings of summing
	Hexadecimal operator+(const Hexadecimal& h);
	Hexadecimal operator+(const Binary& b);
	Hexadecimal operator+(const Octal& o);
	Hexadecimal operator+(const Decimal& second);
	// operator overloadings of subtraction
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
	Hexadecimal &operator=(const Binary &b);
	Hexadecimal &operator=(const Octal &o);
	Hexadecimal &operator=(const Decimal &d);

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
