#include "Octal.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"

Octal::Octal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::transform(num.begin(), num.end(), num.begin(), ::toupper);

    if (num.find("NAN") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    // tolower character x in string
    std::transform(num.begin(), num.end(), num.begin(), ::tolower);

    // trim octal string
    if (num.substr(0, 2) == "0o")
        num = num.substr(2, num.length());
    else if (num.substr(0, 3) == "-0o")
        num = "-" + num.substr(3, num.length());
    else if (num.substr(0, 1) == "o")
        num = num.substr(1, num.length());

    clean_number(num);  // clean if it starts/ends with 0

    this->num = num;
}

// copy constructor
Octal::Octal(const Octal &o) : NumberBase(o) {}

Octal::Octal(const NumberBase &other) : Octal(other.toDec()) {}

Octal::Octal(const Decimal &d) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = d.num;

    std::transform(number.begin(), number.end(), number.begin(), ::toupper);

    if (number.find("NAN") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    clean_number(number);  // clean if it starts/ends with 0

    std::string result;

    if (number.at(0) == '-') {
        number = number.substr(1, number.length());
        result += "-";
    }

    if (number.length() == 0 || number == "0.0") {
        this->num = "0.0";
        return;
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if (number.length() != 0) {
        intPoint = std::stoull(number.substr(0, number.find('.')));
    }
    double decPoint = 0;
    if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
        decPoint = std::stod(
            this->sub(number, number.substr(0, number.find('.') + 1) + "0"));
    }

    // calculate the octal number from decimal
    do {
        result += (static_cast<char>(intPoint % 8) + '0');
        intPoint /= 8;
    } while (intPoint > 0);

    result.at(0) == '-' ? std::reverse(result.begin() + 1, result.end())
                        : std::reverse(result.begin(), result.end());

    // add a '.' to the end
    result.push_back('.');
    // if there is an entered decimal point or not
    if (decPoint != 0) {
        while (true) {
            decPoint *= 8;
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

Octal Octal::toOct() const { return Octal{*this}; }

Binary Octal::toBin() const { return Binary(*this); }

Decimal Octal::toDec() const { return Decimal(*this); }

Hexadecimal Octal::toHex() const { return Hexadecimal(*this); }

Octal::Octal(const int &num) { this->num = Decimal(num).toOct().num; }

Octal::Octal(const double &num) { this->num = Decimal(num).toOct().num; }

#pragma region operators

std::ostream &operator<<(std::ostream &output, const Octal &o) {
    return output << "0" << o.num;
}

Octal::operator std::string() { return this->num; }

Octal Octal::operator+(const NumberBase &other) {
    // convert objects to decimal for summing
    Decimal first(*this), second(other.toDec());

    // calculate the sum of decimal values
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toOct();
}

Octal &Octal::operator+=(const NumberBase &other) {
    *this = *this + other;
    return *this;
}

Octal Octal::operator-(const NumberBase &other) {
    // convert objects to decimal for subtracting
    Decimal first(*this), second(other.toDec());

    // calculate the subtracting of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal &Octal::operator-=(const NumberBase &other) {
    *this = *this - other;
    return *this;
}

Octal Octal::operator*(const NumberBase &other) {
    // convert objects to decimal for multiply
    Decimal first(*this), second(other.toDec());

    // calculate the multiplying of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to octal and return
    return first.toOct();
}

Octal &Octal::operator*=(const NumberBase &other) {
    *this = *this * other;
    return *this;
}

Octal Octal::operator/(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal &Octal::operator/=(const NumberBase &other) {
    *this = *this / other;
    return *this;
}

Octal Octal::operator%(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Domain number cannot be zero!");

    // calculate the remainder of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal &Octal::operator%=(const NumberBase &other) {
    *this = *this % other;
    return *this;
}

Octal &Octal::operator=(const NumberBase &other) {
    if (this == &other)
        return *this;
    this->num = other.num;
    return *this;
}

#pragma endregion operators