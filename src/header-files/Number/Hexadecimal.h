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
};

#endif  // HEXADECIMAL_H