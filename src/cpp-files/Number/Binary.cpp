#include "../../header-files/Number/Binary.h"

#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

Binary::Binary(std::string num) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}

// object type and the parameter object type is same
Binary::Binary(const Binary &b) : Number(b) {}

Binary::Binary(const Decimal &d) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = d.num;

    clean_number(number); // clean if it starts/ends with 0

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

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}

Binary Binary::operator+(Octal o) {
    // convert binary object to decimal
    Decimal first(*this), second(o);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}

Binary Binary::operator+(Decimal second) {
    // convert binary object to decimal
    Decimal first(*this);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}

Binary Binary::operator+(Hexadecimal h) {
    // convert binary object to decimal
    Decimal first(*this), second(h);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}


Binary Binary::operator-(Binary b) {
    // convert binary objects to decimal
    Decimal first(*this), second(b);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(Octal o) {
    // convert binary objects to decimal
    Decimal first(*this), second(o);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(Decimal second) {
    // convert binary objects to decimal
    Decimal first(*this);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracts of values to binary and return
    return first.toBin();
}

Binary Binary::operator-(Hexadecimal h) {
    // convert binary objects to decimal
    Decimal first(*this), second(h);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to binary and return
    return first.toBin();
}

Binary Binary::operator*(Binary b) {
    // convert all values to decimal for multiply
    Decimal first(*this), second(b);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to binary and return
    return first.toBin();
}

Binary Binary::operator*(Octal o) {
    // convert all values to decimal for multiply
    Decimal first(*this), second(o);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator*(Decimal second) {
    // convert all values to decimal for multiply
    Decimal first(*this);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator*(Hexadecimal h) {
    // convert all values to decimal for multiply
    Decimal first(*this), second(h);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator/(Binary b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator/(Octal o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator/(Decimal second) {
    // creating return object/converting other object
    Decimal first(*this);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary Binary::operator/(Hexadecimal h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}
