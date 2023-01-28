#include "../../header-files/Number/Decimal.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
Decimal::Decimal(std::string num) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}

Decimal::Decimal(const Decimal &d) : Number(d) {}

Decimal::Decimal(const Binary &b) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = b.num;

    clean_number(number);  // clean if it starts/ends with 0

    if (number.length() == 0 || number == "0.0") {
        this->num = "0.0";
        return;
    }

    std::string result = "";

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
    std::string decPoint;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = number.substr(number.find('.') + 1, number.length());
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
    if (decPoint.length() != 0) {
        // calculate the decimal point of binary to decimal
        double decimal = 0;
        for (int i = 0; i < decPoint.length(); i++) {
            decimal += (decPoint[i] - '0') * pow(2, -1 * i - 1);
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

    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());

    this->num = result;
}

Decimal::Decimal(const Octal &o) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = o.num;

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

    std::string decPoint;
    if (number.find('.') != -1 &&
        number.length() > number.find('.') + 1) {
        decPoint = number.substr(number.find('.') + 1, number.length());
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
    if (decPoint.length() != 0) {
        // calculate the decimal point of octal to decimal
        double decimal = 0;
        for (int i = 0; i < decPoint.length(); i++) {
            decimal += (decPoint[i] - '0') * pow(8, -1 * i - 1);
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

    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());

    this->num = result;
}

Decimal::Decimal(const Hexadecimal &h) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = h.num;

    clean_number(number);  // clean if it starts/ends with 0

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

    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());

    this->num = sResult;
}

Octal Decimal::toOct() {
    return Octal(*this);
}

Decimal Decimal::toDec() {
    return Decimal(*this);
}

Binary Decimal::toBin() {
    return Binary(*this);
}

Hexadecimal Decimal::toHex() {
    return Hexadecimal(*this);
}

std::ostream &operator<<(std::ostream &output, const Decimal &d) {
    return output << d.num << "d";
}

Decimal Decimal::operator+(Decimal second) {
    Decimal result(*this);

    // calculate the sum of decimal values
    result.num = sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(Binary b) {
    // converting binary value to decimal with creating decimal object
    Decimal result(*this), second(b);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(Octal o) {
    // converting octal value to decimal with creating decimal object
    Decimal result(*this), second(o);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator+(Hexadecimal h) {
    // converting hexadecimal value to decimal with creating decimal object
    Decimal result(*this), second(h);

    // calculate the sum of decimal values
    result.num = this->sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator-(Decimal second) {
    // Converting values to Decimal/Create result object
    Decimal result(*this);

    // calculate the subtract of decimal values
    result.num = this->sub(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator-(Binary b) {
    // Converting values to Decimal/Create result object
    Decimal result(*this), second(b);

    // calculate the subtract of decimal values
    result.num = this->sub(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator-(Octal o) {
    // Converting values to Decimal/Create result object
    Decimal result(*this), second(o);

    // calculate the subtract of decimal values
    result.num = this->sub(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator-(Hexadecimal h) {
    // Converting values to Decimal/Create result object
    Decimal result(*this), second(h);

    // calculate the subtract of decimal values
    result.num = this->sub(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator*(Decimal second) {
    // creating return object/converting other object
    Decimal result(*this);

    // calculate the multiply of decimal values
    result.num = this->mul(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator*(Binary b) {
    // creating return object/converting other object
    Decimal result(*this), second(b);

    // calculate the multiply of decimal values
    result.num = this->mul(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator*(Octal o) {
    // creating return object/converting other object
    Decimal result(*this), second(o);

    // calculate the multiply of decimal values
    result.num = this->mul(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator*(Hexadecimal h) {
    // creating return object/converting other object
    Decimal result(*this), second(h);

    // calculate the multiply of decimal values
    result.num = this->mul(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator/(Decimal second) {
    // creating return object/converting other object
    Decimal result(*this);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = this->div(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator/(Binary b) {
    // creating return object/converting other object
    Decimal result(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(std::stod(result.num) / std::stod(second.num), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator/(Octal o) {
    // creating return object/converting other object
    Decimal result(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(std::stod(result.num) / std::stod(second.num), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator/(Hexadecimal h) {
    // creating return object/converting other object
    Decimal result(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(std::stod(result.num) / std::stod(second.num), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator%(Decimal second) {
    // creating return object/converting other object
    Decimal result(*this);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(fmod(std::stod(result.num), std::stod(second.num)), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator%(Binary b) {
    // creating return object/converting other object
    Decimal result(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(fmod(std::stod(result.num), std::stod(second.num)), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator%(Octal o) {
    // creating return object/converting other object
    Decimal result(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(fmod(std::stod(result.num), std::stod(second.num)), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal Decimal::operator%(Hexadecimal h) {
    // creating return object/converting other object
    Decimal result(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    result.num = to_string_with_precision(fmod(std::stod(result.num), std::stod(second.num)), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator=(const Decimal &d) {
    if (this == &d)
        return *this;
    this->num = d.num;
    return *this;
}

Decimal &Decimal::operator+=(const Decimal &d) {
    *this = *this + d;
    return *this;
}

Decimal &Decimal::operator-=(const Decimal &d) {
    *this = *this - d;
    return *this;
}

Decimal &Decimal::operator*=(const Decimal &d) {
    *this = *this * d;
    return *this;
}

Decimal &Decimal::operator/=(const Decimal &d) {
    *this = *this / d;
    return *this;
}

Decimal &Decimal::operator%=(const Decimal &d) {
    *this = *this % d;
    return *this;
}
