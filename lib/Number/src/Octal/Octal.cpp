#include "Octal.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"

Octal::Octal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    if (num == "NaN") {
        this->num = "NaN";
        return;
    }

    // tolower character x in string
    std::transform(num.begin(), num.end(), num.begin(), [](unsigned char c) { return std::tolower(c); });

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
Octal::Octal(const Octal &o) : BaseClass(o) {}

Octal::Octal(const Decimal &d) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = d.num;

    if (number == "NaN") {
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
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = std::stod(this->sub(number, number.substr(0, number.find('.') + 1) + "0"));
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

Octal::Octal(const Binary &b) {
    // convert binary to decimal
    Decimal d(b);
    // convert decimal to octal
    Octal o(d);
    this->num = o.num;
}

Octal::Octal(const Hexadecimal &h) {
    // convert hexadecimal to decimal
    Decimal d(h);
    // convert decimal to octal
    Octal o(d);
    this->num = o.num;
}

Octal Octal::toOct() const {
    return Octal{*this};
}

Binary Octal::toBin() const {
    return Binary(*this);
}

Decimal Octal::toDec() const {
    return Decimal(*this);
}

Hexadecimal Octal::toHex() const {
    return Hexadecimal(*this);
}

std::ostream &operator<<(std::ostream &output, const Octal &o) {
    return output << "0" << o.num;
}

Octal &Octal::operator=(const Octal &o) {
    if (this == &o)
        return *this;
    this->num = o.num;
    return *this;
}

Octal &Octal::operator=(const Binary &b) {
    this->num = b.toOct().num;
    return *this;
}

Octal &Octal::operator=(const Decimal &d) {
    this->num = d.toOct().num;
    return *this;
}

Octal &Octal::operator=(const Hexadecimal &h) {
    this->num = h.toOct().num;
    return *this;
}

Octal::operator std::string() {
    return this->num;
}

Octal::Octal(const int &num) {
    this->num = Decimal(num).toOct().num;
}

Octal::Octal(const double &num) {
    this->num = Decimal(num).toOct().num;
}
