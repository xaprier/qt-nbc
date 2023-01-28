#include "../../header-files/Number/Octal.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
Octal::Octal(std::string num) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}
// copy constructor
Octal::Octal(const Octal &o) : Number(o) {}

Octal::Octal(const Decimal &d) {
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
    return Octal(*this);
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

Octal Octal::operator+(Octal o) {
    // convert objects to decimal for summing
    Decimal first(*this), second(o);

    // calculate the sum of decimal values
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toOct();
}

Octal Octal::operator+(Binary b) {
    // convert objects to decimal for summing
    Decimal first(*this), second(b);

    // calculate the sum of decimal values
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toOct();
}

Octal Octal::operator+(Decimal second) {
    // convert objects to decimal for summing
    Decimal first(*this);

    // calculate the sum of decimal values
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toOct();
}

Octal Octal::operator+(Hexadecimal h) {
    // convert objects to decimal for summing
    Decimal first(*this), second(h);

    // calculate the sum of decimal values
    first.num = this->sum(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toOct();
}

Octal Octal::operator-(Octal o) {
    // convert objects to decimal for substracting
    Decimal first(*this), second(o);

    // calculate the substract of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(Binary b) {
    // convert objects to decimal for substracting
    Decimal first(*this), second(b);

    // calculate the substract of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(Decimal second) {
    // convert objects to decimal for substracting
    Decimal first(*this);

    // calculate the substract of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator-(Hexadecimal h) {
    // convert objects to decimal for substracting
    Decimal first(*this), second(h);

    // calculate the substract of decimal values
    first.num = this->sub(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator*(Octal o) {
    // convert objects to decimal for multiply
    Decimal first(*this), second(o);

    // calculate the multiply of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator*(Binary b) {
    // convert objects to decimal for multiply
    Decimal first(*this), second(b);

    // calculate the multiply of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator*(Decimal second) {
    // convert objects to decimal for multiply
    Decimal first(*this);

    // calculate the substract of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator*(Hexadecimal h) {
    // convert objects to decimal for multiply
    Decimal first(*this), second(h);

    // calculate the multiply of decimal values
    first.num = this->mul(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the substract of values to octal and return
    return first.toOct();
}

Octal Octal::operator/(Octal o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(Binary b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(Decimal second) {
    // creating return object/converting other object
    Decimal first(*this);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator/(Hexadecimal h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the divide of decimal values
    first.num = this->div(first.num, second.num);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator%(Octal o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the remainder of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator%(Binary b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the remainder of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator%(Decimal second) {
    // creating return object/converting other object
    Decimal first(*this);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the remainder of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}

Octal Octal::operator%(Hexadecimal h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the remainder of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toOct();
}
Octal &Octal::operator=(const Octal &o) {
	if (this == &o)
		return *this;
	this->num = o.num;
	return *this;
}

Octal &Octal::operator+=(const Octal &o) {
	*this = *this + o;
	return *this;
}

Octal &Octal::operator-=(const Octal &o) {
	*this = *this - o;
	return *this;
}

Octal &Octal::operator*=(const Octal &o) {
	*this = *this * o;
	return *this;
}

Octal &Octal::operator/=(const Octal &o) {
	*this = *this / o;
	return *this;
}

Octal &Octal::operator%=(const Octal &o) {
	*this = *this % o;
	return *this;
}