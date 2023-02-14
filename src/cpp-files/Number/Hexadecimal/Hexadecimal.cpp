
#include "header-files/Number/Hexadecimal.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Hexadecimal::Hexadecimal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

	if (num == "NaN") {
		this->num = "NaN";
		return;
	}

	// trim hexadecimal string
	if (num.substr(0, 2) == "0x" || num.substr(0, 2) == "0X") {
		num = num.substr(2);
	}

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}
// copy constructor
Hexadecimal::Hexadecimal(const Hexadecimal &h) : BaseClass(h) {}

// converter interface
Hexadecimal::Hexadecimal(const Decimal &d) {
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

    do {
        if (intPoint % 16 == 15) {
            result += ('F');
        } else if (intPoint % 16 == 14) {
            result += ('E');
        } else if (intPoint % 16 == 13) {
            result += ('D');
        } else if (intPoint % 16 == 12) {
            result += ('C');
        } else if (intPoint % 16 == 11) {
            result += ('B');
        } else if (intPoint % 16 == 10) {
            result += ('A');
        } else {
            result += (static_cast<char>(intPoint % 16) + '0');
        }
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
            if (fmodl(decPoint, 1.0) == 0) {
                if ((int)decPoint == 15) {
                    result.push_back('F');
                } else if ((int)decPoint == 14) {
                    result.push_back('E');
                } else if ((int)decPoint == 13) {
                    result.push_back('D');
                } else if ((int)decPoint == 12) {
                    result.push_back('C');
                } else if ((int)decPoint == 11) {
                    result.push_back('B');
                } else if ((int)decPoint == 10) {
                    result.push_back('A');
                } else {
                    result.push_back(
                        static_cast<char>(((int)decPoint) + '0'));
                }
                break;
            } else {
                if ((int)decPoint == 15) {
                    result.push_back('F');
                } else if ((int)decPoint == 14) {
                    result.push_back('E');
                } else if ((int)decPoint == 13) {
                    result.push_back('D');
                } else if ((int)decPoint == 12) {
                    result.push_back('C');
                } else if ((int)decPoint == 11) {
                    result.push_back('B');
                } else if ((int)decPoint == 10) {
                    result.push_back('A');
                } else {
                    result.push_back(
                        static_cast<char>(((int)decPoint) + '0'));
                }
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

Hexadecimal::Hexadecimal(const Octal &o) {
    // convert octal to decimal
    Decimal d(o);
    // convert decimal to hexadecimal
    Hexadecimal h(d);
    this->num = h.num;
}

Hexadecimal::Hexadecimal(const Binary &b) {
    // convert binary to decimal
    Decimal d(b);
    // convert decimal to hexadecimal
    Hexadecimal h(d);
    this->num = h.num;
}

Octal Hexadecimal::toOct() const {
    return Octal(*this);
}

Decimal Hexadecimal::toDec() const {
    return Decimal(*this);
}

Binary Hexadecimal::toBin() const {
    return Binary(*this);
}

Hexadecimal Hexadecimal::toHex() const {
    return Hexadecimal { *this };
}

std::ostream &operator<<(std::ostream &output, const Hexadecimal &h) {
    return output << "0x" << h.num;
}

Hexadecimal::operator std::string() {
	return this->num;
}

Hexadecimal::Hexadecimal(const int &num) {
	this->num = Decimal(num).toHex().num;
}
Hexadecimal::Hexadecimal(const double &num) {
	this->num = Decimal(num).toHex().num;
}

Hexadecimal &Hexadecimal::operator=(const Hexadecimal &h) {
	if (this == &h)
		return *this;
	this->num = h.num;
	return *this;
}

Hexadecimal &Hexadecimal::operator=(const Binary &b) {
	this->num = b.toHex().num;
	return *this;
}

Hexadecimal &Hexadecimal::operator=(const Octal &o) {
	this->num = o.toHex().num;
	return *this;
}

Hexadecimal &Hexadecimal::operator=(const Decimal &d) {
	this->num = d.toHex().num;
	return *this;
}