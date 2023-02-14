#include "header-files/Number/Binary.h"

#include <iostream>
#include <cmath>
#include <algorithm>

Binary::Binary(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

	if (num == "NaN") {
		this->num = "NaN";
		return;
	}

	// trim binary string
	if (num.substr(0, 2) == "0b" || num.substr(0, 2) == "0B") {
		num = num.substr(2);
	}

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}

// object type and the parameter object type is same
Binary::Binary(const Binary &b) : BaseClass(b) {}

Binary::Binary(const Decimal &d) {
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
	if (number.length() > number.find('.') + 1) {
        decPoint = std::stod(this->sub(number, number.substr(0, number.find('.') + 1) + "0"));
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

Octal Binary::toOct() const {
    return Octal(*this);
}

Decimal Binary::toDec() const {
    return Decimal(*this);
}

Binary Binary::toBin() const {
    return Binary { *this };
}

Hexadecimal Binary::toHex() const {
    return Hexadecimal(*this);
}

std::ostream &operator<<(std::ostream &output, const Binary &b) {
    return output << b.num << "b";
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

Binary::operator std::string() {
	return this->num;
}

Binary::Binary(const int &num) {
	this->num = Decimal(num).toBin().num;
}

Binary::Binary(const double &num) {
	this->num = Decimal(num).toBin().num;
}

