#ifndef OCTAL_H
#define OCTAL_H

#include "BaseClass.h"
#include "Decimal.h"
#include "Binary.h"
#include "Hexadecimal.h"

class Octal : public BaseClass {
  public:
	// expression must be in Octal format("0o0.0")
	explicit Octal(std::string num = "0o0.0");
	// expression must be as Decimal format(0)
	explicit Octal(const int &num);
	// expression must be as Decimal format(0.0)
	explicit Octal(const double &num);
	// expression must be a hexadecimal object
	explicit Octal(const Hexadecimal &h);
	// expression must be a decimal object
	explicit Octal(const Decimal &d);
	// expression must be a binary object
	explicit Octal(const Binary &b);
	// expression must be a octal object
	Octal(const Octal &o);

	[[nodiscard]] Octal toOct() const override;
	[[nodiscard]] Decimal toDec() const override;
	[[nodiscard]] Binary toBin() const override;
	[[nodiscard]] Hexadecimal toHex() const override;

	explicit operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Octal &o);

	// operator overloadings of summing
	Octal operator+(const Octal& o);
	Octal operator+(const Binary& b);
	Octal operator+(const Decimal& second);
	Octal operator+(const Hexadecimal& h);
	// operator overloadings of substraction
	Octal operator-(const Octal& o);
	Octal operator-(const Binary& b);
	Octal operator-(const Decimal& second);
	Octal operator-(const Hexadecimal& h);
	// operator overloadings of multiply
	Octal operator*(const Octal& o);
	Octal operator*(const Binary& b);
	Octal operator*(const Decimal& second);
	Octal operator*(const Hexadecimal& h);
	// operator overloadings of divide
	Octal operator/(const Octal& o);
	Octal operator/(const Binary& b);
	Octal operator/(const Decimal& second);
	Octal operator/(const Hexadecimal& h);
	// operator overloadings of remainder
	Octal operator%(const Octal& o);
	Octal operator%(const Binary& b);
	Octal operator%(const Decimal& second);
	Octal operator%(const Hexadecimal& h);
	// assignment operator overloadings
	Octal &operator=(const Octal &o);
	Octal &operator=(const Binary &b);
	Octal &operator=(const Decimal &d);
	Octal &operator=(const Hexadecimal &h);

	Octal &operator+=(const Octal &o);
	Octal &operator+=(const Binary &b);
	Octal &operator+=(const Decimal &d);
	Octal &operator+=(const Hexadecimal &h);

	Octal &operator-=(const Octal &o);
	Octal &operator-=(const Binary &b);
	Octal &operator-=(const Decimal &d);
	Octal &operator-=(const Hexadecimal &h);

	Octal &operator*=(const Octal &o);
	Octal &operator*=(const Binary &b);
	Octal &operator*=(const Decimal &d);
	Octal &operator*=(const Hexadecimal &h);

	Octal &operator/=(const Octal &o);
	Octal &operator/=(const Binary &b);
	Octal &operator/=(const Decimal &d);
	Octal &operator/=(const Hexadecimal &h);

	Octal &operator%=(const Octal &o);
	Octal &operator%=(const Binary &b);
	Octal &operator%=(const Decimal &d);
	Octal &operator%=(const Hexadecimal &h);
};

#endif  // OCTAL_H
