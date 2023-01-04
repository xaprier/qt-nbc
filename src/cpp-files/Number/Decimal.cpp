#include "../../header-files/Number/Decimal.h"

#include <iostream>
#include <utility>
#include <cmath>
Decimal::Decimal(std::string num) : Number(std::move(num)) {}

Decimal::Decimal(const Decimal &d) : Number(d) {}

Decimal::Decimal(const Binary &b) {
    std::string number = b.num;
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
        intPoint = std::stoull(number.substr(0, (number.find('.') != -1)
                                                    ? number.length()
                                                    : number.find('.')));
    }
    unsigned long long decPoint = 0;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = std::stoull(
            number.substr(number.find('.') + 1, number.length()));
    }

    // calculate the decimal number from binary
    unsigned long long integer = 0;
    for (int i = 0; intPoint > 0; i++) {
        integer += intPoint % 10 * pow(2, i);
        intPoint /= 10;
    }

    // add calculated integer value of decimal to result string
    result += std::to_string(integer);
    // add a '.' to the end
    result.push_back('.');
    // if there is an entered decimal point or not
    if (decPoint != 0) {
        // calculate the decimal point of binary to decimal
        double decimal = 0;
        for (int i =
                 -1 * number.substr(number.find('.') + 1, number.length())
                          .length();
             decPoint > 0; i++) {
            decimal += decPoint % 10 * pow(2, i);
            decPoint /= 10;
        }

        // check the decimal point and add to end of string the char of number
        // if decimal not fully 0
        while (true) {
            decimal *= 10;
            if (fmodl(decimal, 1.0) == 0) {
                result.push_back(static_cast<char>(decimal) + '0');
                break;
            } else {
                result.push_back(static_cast<char>(
                    ((unsigned long long)decimal) + '0'));
                decimal -= (unsigned long long)decimal;
            }
        }
    } else {
        // if there isn't entered a decimal point enter .0
        result.push_back('0');
    }

    this->num = result;
}

Decimal::Decimal(const Octal &o) {
    std::string number = o.num;
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

    unsigned long long decPoint = 0;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = std::stoull(
            number.substr(number.find('.') + 1, number.length()));
    }

    // calculate the integer decimal number from octal
    unsigned long long integer = 0;
    for (int i = 0; intPoint > 0; i++) {
        integer += intPoint % 10 * pow(8, i);
        intPoint /= 10;
    }

    // add calculated integer value of decimal to result string
    result += std::to_string(integer);
    // add a '.' to the end
    result.push_back('.');
    // if there is an entered decimal point or not
    if (decPoint != 0) {
        // calculate the decimal point of octal to decimal
        double decimal = 0;
        for (int i =
                 -1 * number.substr(number.find('.') + 1, number.length())
                          .length();
             decPoint > 0; i++) {
            decimal += decPoint % 10 * pow(8, i);
            decPoint /= 10;
        }

        // check the decimal point and add to end of string the char of number
        // if decimal not fully 0
        while (true) {
            decimal *= 10;
            if (fmodl(decimal, 1.0) == 0) {
                result.push_back(static_cast<char>(decimal) + '0');
                break;
            } else {
                result.push_back(static_cast<char>(
                    ((unsigned long long)decimal) + '0'));
                decimal -= (unsigned long long)decimal;
            }
        }
    } else {
        // if there isn't entered a decimal point enter .0
        result.push_back('0');
    }

    this->num = result;
}

Decimal::Decimal(const Hexadecimal &h) {
    std::string number = h.num;
    if (number.length() == 0 || number == "0.0") {
        this->num = "0.0";
        return;
    }

    bool isItNegative = false;
    if (number.at(0) == '-') {
        number = number.substr(1, number.length());
        isItNegative = true;
    }

    double result = 0;
    // split the decimal number as it supposed to be
    std::string intPoint;
    if (number.length() != 0) {
        intPoint = number.substr(0, (number.length() > number.find('.'))
                                        ? number.find('.')
                                        : number.length());
    } else {
        intPoint = "0";
    }

    std::string decPoint;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = number.substr(number.find('.') + 1, number.length());
    }

    std::string sResult;

    // calculate the integer part of decimal from hexadecimal
    for (int i = intPoint.length() - 1; i >= 0; i--) {
        if (intPoint[i] == 'A')
            result += 10 * pow(16, intPoint.length() - i - 1);
        else if (intPoint[i] == 'B')
            result += 11 * pow(16, intPoint.length() - i - 1);
        else if (intPoint[i] == 'C')
            result += 12 * pow(16, intPoint.length() - i - 1);
        else if (intPoint[i] == 'D')
            result += 13 * pow(16, intPoint.length() - i - 1);
        else if (intPoint[i] == 'E')
            result += 14 * pow(16, intPoint.length() - i - 1);
        else if (intPoint[i] == 'F')
            result += 15 * pow(16, intPoint.length() - i - 1);
        else
            result += static_cast<int>(intPoint[i] - '0') *
                      pow(16, intPoint.length() - i - 1);
    }

    for (char i :
         std::to_string(static_cast<unsigned long long>(result))) {
        sResult.push_back(i);
    }
    sResult.push_back('.');
    result = 0;

    if (!decPoint.empty()) {
        int iterator = -1;
        for (char i : decPoint) {
            if (i == 'A')
                result += 10 * pow(16, iterator);
            else if (i == 'B')
                result += 11 * pow(16, iterator);
            else if (i == 'C')
                result += 12 * pow(16, iterator);
            else if (i == 'D')
                result += 13 * pow(16, iterator);
            else if (i == 'E')
                result += 14 * pow(16, iterator);
            else if (i == 'F')
                result += 15 * pow(16, iterator);
            else
                result += static_cast<int>(i - '0') * pow(16, iterator);
            iterator--;
        }
    }

    if (decPoint.length() != 0) {
        while (true) {
            result *= 10;
            if (fmodl(result, 1.0) == 0) {
                sResult.push_back(static_cast<char>(result) + '0');
                break;
            } else {
                sResult.push_back(static_cast<char>(((int)result) + '0'));
                result -= static_cast<int>(result);
            }
        }
    } else {
        sResult.push_back('0');
    }

    if (isItNegative) sResult.insert(0, "-");

    this->num = sResult;
}

Octal Decimal::toOct() {
    std::cout << "Decimal class toOct() worked" << std::endl;
    return Octal();
}
Decimal Decimal::toDec() {
    std::cout << "Decimal class toDec() worked" << std::endl;
    return Decimal();
}
Binary Decimal::toBin() {
    std::cout << "Decimal class toBin() worked" << std::endl;
    return Binary();
}
Hexadecimal Decimal::toHex() {
    std::cout << "Decimal class toHex() worked" << std::endl;
    return Hexadecimal();
}
