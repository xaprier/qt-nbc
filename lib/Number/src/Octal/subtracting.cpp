//
// Created by xaprier on 2/13/23.
//
#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

Octal Octal::operator-(const Octal &o) {
    // convert objects to decimal for subtracting
    Decimal first(*this), second(o);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(const Binary &b) {
    // convert objects to decimal for subtracting
    Decimal first(*this), second(b);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(const Decimal &second) {
    // convert objects to decimal for subtracting
    Decimal first(*this);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(const Hexadecimal &h) {
    // convert objects to decimal for subtracting
    Decimal first(*this), second(h);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal &Octal::operator-=(const Octal &o) {
    *this = *this - o;
    return *this;
}

Octal &Octal::operator-=(const Binary &b) {
    *this = *this - b;
    return *this;
}

Octal &Octal::operator-=(const Decimal &d) {
    *this = *this - d;
    return *this;
}

Octal &Octal::operator-=(const Hexadecimal &h) {
    *this = *this - h;
    return *this;
}