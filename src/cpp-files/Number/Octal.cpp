#include "../../header-files/Number/Octal.h"

#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
Octal::Octal(std::string num) : Number(std::move(num)) {}
// copy constructor
Octal::Octal(const Octal &o) : Number(o) {}

Octal::Octal(const Decimal &d) {
    std::string number = d.num;
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");
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

Octal::Octal(const Hexadecimal &h) {
    // convert hexadecimal to decimal
    Decimal d(h);
    // convert decimal to octal
    Octal o(d);
    this->num = o.num;
}

Octal::Octal(const Binary &b) {
    // convert binary to decimal
    Decimal d(b);
    // convert decimal to octal
    Octal o(d);
    this->num = o.num;
}

Octal Octal::toOct() {
	std::cout << "Octal class toOct() worked" << std::endl;
    return Octal();
}
Decimal Octal::toDec() {
	std::cout << "Octal class toDec() worked" << std::endl;
    return Decimal();
}
Binary Octal::toBin() {
	std::cout << "Octal class toBin() worked" << std::endl;
    return Binary();
}
Hexadecimal Octal::toHex() {
	std::cout << "Octal class toHex() worked" << std::endl;
    return Hexadecimal();
}
