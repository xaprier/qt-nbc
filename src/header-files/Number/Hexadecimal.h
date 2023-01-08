#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

#include "Decimal.h"
#include "Binary.h"
#include "Octal.h"

class Hexadecimal : public Number {
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

	friend std::ostream &operator<<(std::ostream &output, const Hexadecimal &h);

	Hexadecimal operator+(Hexadecimal h);
	Hexadecimal operator+(Binary b);
	Hexadecimal operator+(Octal o);
	Hexadecimal operator+(Decimal second);
	Hexadecimal operator-(Hexadecimal h);
	Hexadecimal operator-(Binary b);
	Hexadecimal operator-(Octal o);
	Hexadecimal operator-(Decimal second);
};

#endif  // HEXADECIMAL_H
