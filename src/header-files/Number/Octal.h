#ifndef OCTAL_H
#define OCTAL_H

#include "Number.h"
#include "Decimal.h"
#include "Binary.h"
#include "Hexadecimal.h"

class Octal : public Number {
  public:
	explicit Octal(std::string num = "0.0");
	explicit Octal(const Hexadecimal &h);
	explicit Octal(const Decimal &d);
	explicit Octal(const Binary &b);
	Octal(const Octal &o);

	Octal toOct() override;
	Decimal toDec() override;
	Binary toBin() override;
	Hexadecimal toHex() override;

	operator std::string() override;

	friend std::ostream &operator<<(std::ostream &output, const Octal &o);

	// operator overloadings of summing
	Octal operator+(Octal o);
	Octal operator+(Binary b);
	Octal operator+(Decimal second);
	Octal operator+(Hexadecimal h);
	// operator overloadings of substraction
	Octal operator-(Octal o);
	Octal operator-(Binary b);
	Octal operator-(Decimal second);
	Octal operator-(Hexadecimal h);
	// operator overloadings of multiply
	Octal operator*(Octal o);
	Octal operator*(Binary b);
	Octal operator*(Decimal second);
	Octal operator*(Hexadecimal h);
	// operator overloadings of divide
	Octal operator/(Octal o);
	Octal operator/(Binary b);
	Octal operator/(Decimal second);
	Octal operator/(Hexadecimal h);
	// operator overloadings of remainder
	Octal operator%(Octal o);
	Octal operator%(Binary b);
	Octal operator%(Decimal second);
	Octal operator%(Hexadecimal h);
	// assignment operator overloadings
	Octal &operator=(const Octal &o);

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
