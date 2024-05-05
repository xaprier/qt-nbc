//
// Created by xaprier on 2/13/23.
//
#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

Decimal Decimal::operator+(const Decimal &second) {
    Decimal result(*this);

    // calculate the sum of decimal values
    result.num = sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(const Binary &b) {
    // converting binary value to decimal with creating decimal object
    Decimal result(*this), second(b);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(const Octal &o) {
    // converting octal value to decimal with creating decimal object
    Decimal result(*this), second(o);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(const Hexadecimal &h) {
    // converting hexadecimal value to decimal with creating decimal object
    Decimal result(*this), second(h);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator+=(const Decimal &d) {
    *this = *this + d;
    return *this;
}

Decimal &Decimal::operator+=(const Binary &b) {
    *this = *this + b;
    return *this;
}

Decimal &Decimal::operator+=(const Octal &o) {
    *this = *this + o;
    return *this;
}

Decimal &Decimal::operator+=(const Hexadecimal &h) {
    *this = *this + h;
    return *this;
}