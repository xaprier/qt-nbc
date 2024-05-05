//
// Created by xaprier on 2/13/23.
//
#include "Hexadecimal.hpp"

Hexadecimal Hexadecimal::operator*(const Hexadecimal &h) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(h);

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(const Binary &b) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(b);

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(const Octal &o) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(o);

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(const Decimal &second) {
    // convert objects to decimal for calculating
    Decimal first(*this);

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal &Hexadecimal::operator*=(const Hexadecimal &h) {
    *this = *this * h;
    return *this;
}

Hexadecimal &Hexadecimal::operator*=(const Binary &b) {
    *this = *this * b;
    return *this;
}

Hexadecimal &Hexadecimal::operator*=(const Octal &o) {
    *this = *this * o;
    return *this;
}

Hexadecimal &Hexadecimal::operator*=(const Decimal &d) {
    *this = *this * d;
    return *this;
}