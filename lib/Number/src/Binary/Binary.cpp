#include "Binary.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "Decimal.hpp"
#include "Hexadecimal.hpp"
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

// object type and the parameter object type is same
Binary::Binary(const Binary &b) : NumberBase(b) {}

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

Octal Binary::toOct() const { return Octal(*this); }

Decimal Binary::toDec() const { return Decimal(*this); }

Binary Binary::toBin() const { return Binary{*this}; }

Hexadecimal Binary::toHex() const { return Hexadecimal(*this); }

std::ostream &operator<<(std::ostream &output, const Binary &b) {
    return output << "0b" + b.num;
}

Binary &Binary::operator=(const Binary &b) {
    if (this == &b)
        return *this;
    this->num = b.num;
    return *this;
}

Binary &Binary::operator=(const Octal &o) {
    this->num = o.toBin().num;
    return *this;
}

Binary &Binary::operator=(const Decimal &d) {
    this->num = d.toBin().num;
    return *this;
}

Binary &Binary::operator=(const Hexadecimal &h) {
    this->num = h.toBin().num;
    return *this;
}

Binary::operator std::string() { return this->num; }

Binary::Binary(const int &num) { this->num = Decimal(num).toBin().num; }

Binary::Binary(const double &num) { this->num = Decimal(num).toBin().num; }
