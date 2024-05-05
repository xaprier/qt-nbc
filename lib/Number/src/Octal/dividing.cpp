//
// Created by xaprier on 2/13/23.
//
#include "Octal.hpp"

Octal Octal::operator/(const Octal &o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(const Binary &b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(const Decimal &second) {
    // creating return object/converting other object
    Decimal first(*this);

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(const Hexadecimal &h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal &Octal::operator/=(const Octal &o) {
    *this = *this / o;
    return *this;
}

Octal &Octal::operator/=(const Binary &b) {
    *this = *this / b;
    return *this;
}

Octal &Octal::operator/=(const Decimal &d) {
    *this = *this / d;
    return *this;
}

Octal &Octal::operator/=(const Hexadecimal &h) {
    *this = *this / h;
    return *this;
}