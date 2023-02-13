#include "header-files/Number/Octal.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Octal::Octal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

	if (num == "NaN") {
		this->num = "NaN";
		return;
	}

    clean_number(num); // clean if it starts/ends with 0

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

Octal Octal::toOct() {
    return Octal { *this };
}

Binary Octal::toBin() {
    return Binary(*this);
}

Decimal Octal::toDec() {
    return Decimal(*this);
}

Hexadecimal Octal::toHex() {
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

Octal::operator std::string() {
	return this->num;
}
