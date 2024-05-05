//
// Created by xaprier on 2/13/23.
//
#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

Binary Binary::operator-(const Binary &b) {
    // convert binary objects to decimal
    Decimal first(*this), second(b);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(const Octal &o) {
    // convert binary objects to decimal
    Decimal first(*this), second(o);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(const Decimal &second) {
    // convert binary objects to decimal
    Decimal first(*this);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(const Hexadecimal &h) {
    // convert binary objects to decimal
    Decimal first(*this), second(h);

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to binary and return
    return first.toBin();
}

Binary &Binary::operator-=(const Binary &b) {
    *this = *this - b;
    return *this;
}

Binary &Binary::operator-=(const Octal &o) {
    *this = *this - o;
    return *this;
}

Binary &Binary::operator-=(const Decimal &d) {
    *this = *this - d;
    return *this;
}

Binary &Binary::operator-=(const Hexadecimal &h) {
    *this = *this - h;
    return *this;
}