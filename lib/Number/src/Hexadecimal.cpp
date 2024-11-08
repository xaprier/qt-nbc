#include "Hexadecimal.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Octal.hpp"

Hexadecimal::Hexadecimal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::transform(num.begin(), num.end(), num.begin(), ::tolower);

    if (num.find("nan") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    // toupper character x in string
    std::transform(num.begin(), num.end(), num.begin(), ::toupper);

    // trim hexadecimal string
    if (num.substr(0, 2) == "0X")
        num = num.substr(2, num.length());
    else if (num.substr(0, 3) == "-0X")
        num = "-" + num.substr(3, num.length());
    else if (num.substr(0, 1) == "X")
        num = num.substr(1, num.length());

    clean_number(num);  // clean if it starts/ends with 0

    this->num = num;
}
// copy constructor
Hexadecimal::Hexadecimal(const Hexadecimal &h) : NumberBase(h) {}

Hexadecimal::Hexadecimal(const NumberBase &other) : Hexadecimal(other.toDec()) {}

// converter interface
Hexadecimal::Hexadecimal(const Decimal &d) {
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
    if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
        decPoint = std::stod(
            this->sub(number, number.substr(0, number.find('.') + 1) + "0"));
    }

    do {
        int remain = intPoint % 16;
        if (remain >= 10)
            result += static_cast<char>('A' + remain - 10);
        else
            result += static_cast<char>(intPoint % 16) + '0';
        intPoint /= 16;
    } while (intPoint > 0);

    result.at(0) == '-' ? std::reverse(result.begin() + 1, result.end())
                        : std::reverse(result.begin(), result.end());

    // add a '.' to the end
    result.push_back('.');
    // if there is an entered decimal point or not
    if (decPoint != 0) {
        while (true) {
            decPoint *= 16;
            int remain = static_cast<int>(decPoint);
            if (remain >= 10)
                result.push_back(static_cast<char>('A' + remain - 10));
            else
                result.push_back(static_cast<char>(((int)decPoint) + '0'));

            if (fmodl(decPoint, 1.0) == 0) {
                break;
            } else {
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

Octal Hexadecimal::toOct() const { return Octal(*this); }

Decimal Hexadecimal::toDec() const { return Decimal(*this); }

Binary Hexadecimal::toBin() const { return Binary(*this); }

Hexadecimal Hexadecimal::toHex() const { return Hexadecimal{*this}; }

Hexadecimal::Hexadecimal(const int &num) {
    this->num = Decimal(num).toHex().num;
}
Hexadecimal::Hexadecimal(const double &num) {
    this->num = Decimal(num).toHex().num;
}

#pragma region operators

std::ostream &operator<<(std::ostream &output, const Hexadecimal &h) {
    return output << "0x" << h.num;
}

Hexadecimal::operator std::string() { return this->num; }

Hexadecimal Hexadecimal::operator+(const NumberBase &other) {
    // convert objects to decimal for summing
    Decimal first(*this), second(other.toDec());

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toHex();
}

Hexadecimal &Hexadecimal::operator+=(const NumberBase &other) {
    *this = *this + other;
    return *this;
}

Hexadecimal Hexadecimal::operator-(const NumberBase &other) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(other.toDec());

    // calculate the subtracting of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtracting of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal &Hexadecimal::operator-=(const NumberBase &other) {
    *this = *this - other;
    return *this;
}

Hexadecimal Hexadecimal::operator*(const NumberBase &other) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(other.toDec());

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiplying of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal &Hexadecimal::operator*=(const NumberBase &other) {
    *this = *this * other;
    return *this;
}

Hexadecimal Hexadecimal::operator/(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal &Hexadecimal::operator/=(const NumberBase &other) {
    *this = *this / other;
    return *this;
}

Hexadecimal Hexadecimal::operator%(const NumberBase &other) {
    // creating return object/converting other object
    Decimal first(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Domain number cannot be zero!");

    // calculate the multiplying of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal &Hexadecimal::operator%=(const NumberBase &other) {
    *this = *this % other;
    return *this;
}

Hexadecimal &Hexadecimal::operator=(const NumberBase &other) {
    if (this == &other)
        return *this;

    // Try to cast `other` to `const Binary&`
    const Hexadecimal *hexPtr = dynamic_cast<const Hexadecimal *>(&other);
    if (hexPtr) {
        this->num = hexPtr->num;
    } else {
        this->num = other.toBin().num;
    }

    return *this;
}

#pragma endregion operators