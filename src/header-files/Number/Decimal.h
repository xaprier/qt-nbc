#ifndef DECIMAL_H
#define DECIMAL_H

#include "Binary.h"
#include "Hexadecimal.h"
#include "Octal.h"
#include <iostream>

class Decimal : public Number {
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

    friend std::ostream &operator<<(std::ostream &output, const Decimal &d);

    Decimal operator+(Decimal d);
    Decimal operator+(Binary b);
    Decimal operator+(Octal o);
    Decimal operator+(Hexadecimal h);
    Decimal operator-(Decimal second);
    Decimal operator-(Binary b);
    Decimal operator-(Octal o);
    Decimal operator-(Hexadecimal h);
    Decimal operator*(Decimal second);
    Decimal operator*(Binary b);
    Decimal operator*(Octal o);
    Decimal operator*(Hexadecimal h);
};

#endif  // DECIMAL_H
