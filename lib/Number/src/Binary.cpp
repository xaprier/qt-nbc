#include "Binary.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "NumberBase.hpp"
#include "Octal.hpp"

Binary::Binary(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    if (num == "NaN") {
        this->num = "NaN";
        return;
    }

    // tolower character b in string
    std::transform(num.begin(), num.end(), num.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    // trim binary string
    if (num.substr(0, 2) == "0b")
        num = num.substr(2, num.length());
    else if (num.substr(0, 3) == "-0b")
        num = "-" + num.substr(3, num.length());
    else if (num.substr(0, 1) == "b")
        num = num.substr(1, num.length());

    clean_number(num);  // clean if it starts/ends with 0

    this->num = num;
}

Binary::Binary(const Decimal &d) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = d.num;
    std::transform(number.begin(), number.end(), number.begin(), ::tolower);

    if (number.find("nan") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    clean_number(number);  // clean if it starts/ends with 0

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
    if (number.length() > number.find('.') + 1) {
        decPoint = std::stod(
            this->sub(number, number.substr(0, number.find('.') + 1) + "0"));
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
                result.push_back(static_cast<char>(((int)decPoint) + '0'));
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

// object type and the parameter object type is same
Binary::Binary(const Binary &b) : NumberBase(b) {}

Binary::Binary(const NumberBase &other) : Binary(other.toDec()) {}

Octal Binary::toOct() const { return Octal(*this); }

Decimal Binary::toDec() const { return Decimal(*this); }

Binary Binary::toBin() const { return Binary{*this}; }

Hexadecimal Binary::toHex() const { return Hexadecimal(*this); }

Binary::Binary(const int &num) { this->num = Decimal(num).toBin().num; }

Binary::Binary(const double &num) { this->num = Decimal(num).toBin().num; }

#pragma region operators

std::ostream &operator<<(std::ostream &output, const Binary &b) {
    return output << "0b" + b.num;
}

Binary &Binary::operator=(const NumberBase &other) {
    if (this == &other)
        return *this;

    // Try to cast `other` to `const Binary&`
    const Binary *binaryPtr = dynamic_cast<const Binary *>(&other);
    if (binaryPtr) {
        this->num = binaryPtr->num;
    } else {
        this->num = other.toBin().num;
    }

    return *this;
}

Binary::operator std::string() { return this->num; }

Binary Binary::operator+(const NumberBase &other) {
    // convert objects to decimal for calculation
    Decimal first = this->toDec(), second = other.toDec();

    // calculate
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}

Binary &Binary::operator+=(const NumberBase &other) {
    *this = *this + other;
    return *this;
}

Binary Binary::operator-(const NumberBase &other) {
    // convert objects to decimal for calculation
    Decimal first = this->toDec(), second = other.toDec();

    // calculate
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toBin();
}

Binary &Binary::operator-=(const NumberBase &other) {
    *this = *this - other;
    return *this;
}

Binary Binary::operator*(const NumberBase &other) {
    // convert all values to decimal for multiply
    Decimal first = this->toDec(), second = other.toDec();

    // calculate the multiplying of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to binary and return
    return first.toBin();
}

Binary &Binary::operator*=(const NumberBase &other) {
    *this = *this * other;
    return *this;
}

Binary Binary::operator/(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first = this->toDec(), second = other.toDec();

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the multiplying of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary &Binary::operator/=(const NumberBase &other) {
    *this = *this / other;
    return *this;
}

Binary Binary::operator%(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first = this->toDec(), second = other.toDec();

    if (second.num == "0.0")
        throw std::runtime_error("Domain number cannot be zero!");

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toBin();
}

Binary &Binary::operator%=(const NumberBase &other) {
    *this = *this % other;
    return *this;
}

#pragma endregion operators