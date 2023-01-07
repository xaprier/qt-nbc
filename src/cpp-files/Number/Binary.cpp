#include "../../header-files/Number/Binary.h"

#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

Binary::Binary(std::string num) : Number(std::move(num)) {}

// object type and the parameter object type is same
Binary::Binary(const Binary &b) : Number(b) {}

Binary::Binary(const Decimal &d) {
    std::string number = d.num;
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");
    if (number.length() == 0 || number == "0.0") {
        this->num = "0.0";
        return;
    }

    std::string result;

    if (number.at(0) == '-') {
        number = number.substr(1, number.length());
        result += "-";
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if (number.length() != 0) {
        intPoint = std::stoull(number.substr(0, number.find('.')));
    }
    double decPoint = 0;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = std::stod(number);
        decPoint -= static_cast<int>(decPoint);
    }

    // calculate the binary number from decimal
    do {
        result += (static_cast<char>(intPoint % 2) + '0');
        intPoint /= 2;
    } while (intPoint > 0);

    result.at(0) == '-' ? std::reverse(result.begin() + 1, result.end())
                        : std::reverse(result.begin(), result.end());

    // add a '.' to the end
    result.push_back('.');
    // if there is an entered decimal point or not
    if (fmod(decPoint, 1) != 0) {
        while (true) {
            decPoint *= 2;
            if (fmodl(decPoint, 1.0) == 0) {
                result.push_back(static_cast<char>(decPoint) + '0');
                break;
            } else {
                result.push_back(
                    static_cast<char>(((int)decPoint) + '0'));
                decPoint -= (int)decPoint;
            }
        }
    } else {
        result.push_back('0');
    }
    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());
    this->num = result;
}

// convert octal to binary
Binary::Binary(const Octal &o) {
    // converting octal to decimal with decimal class
    Decimal d(o);
    // converting decimal to binary
    Binary b(d);
    this->num = b.num;
}

Binary::Binary(const Hexadecimal &h) {
    // converting hexadecimal to decimal
    Decimal d(h);
    // converting decimal to binary
    Binary b(d);
    this->num = b.num;
}

Octal Binary::toOct() {
    return Octal(*this);
}

Decimal Binary::toDec() {
    return Decimal(*this);
}

Binary Binary::toBin() {
    return Binary(*this);
}

Hexadecimal Binary::toHex() {
    return Hexadecimal(*this);
}

std::ostream &operator<<(std::ostream &output, const Binary &b) {
    return output << b.num;
}

Binary Binary::operator+(Binary b) {
    // convert binary objects to decimal
    Decimal first(*this), second(b);
    // find the max length of decimal points
    int precision = std::max(
        (first.num.find('.') != -1) ?
            first.num.substr(first.num.find('.'), first.num.length()).length() :
            0,
        (second.num.find('.') != -1) ?
            second.num.substr(second.num.find('.'), second.num.length()).length() :
            0
    );
    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), precision);
    // then convert the sum of values to binary and return
    Binary result(first);
    return result;
}

Binary Binary::operator+(Decimal second) {
    // convert binary object to decimal
    Decimal first(*this);
    // find the max length of decimal points
    int precision = std::max(
        (first.num.find('.') != -1) ?
            first.num.substr(first.num.find('.'), first.num.length()).length() :
            0,
        (second.num.find('.') != -1) ?
            second.num.substr(second.num.find('.'), second.num.length()).length() :
            0
    );
    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), precision);
    // then convert the sum of values to binary and return
    Binary result(first);
    return result;
}

Binary Binary::operator+(Hexadecimal h) {
    // convert binary object to decimal
    Decimal first(*this), second(h);
    // find the max length of decimal points
    int precision = std::max(
        (first.num.find('.') != -1) ?
            first.num.substr(first.num.find('.'), first.num.length()).length() :
            0,
        (second.num.find('.') != -1) ?
            second.num.substr(second.num.find('.'), second.num.length()).length() :
            0
    );
    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), precision);
    // then convert the sum of values to binary and return
    Binary result(first);
    return result;
}

Binary Binary::operator+(Octal o) {
    // convert binary object to decimal
    Decimal first(*this), second(o);
    // find the max length of decimal points
    int precision = std::max(
        (first.num.find('.') != -1) ?
            first.num.substr(first.num.find('.'), first.num.length()).length() :
            0,
        (second.num.find('.') != -1) ?
            second.num.substr(second.num.find('.'), second.num.length()).length() :
            0
    );
    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), precision);
    // then convert the sum of values to binary and return
    Binary result(first);
    return result;
}
