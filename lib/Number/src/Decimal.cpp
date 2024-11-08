#include "Decimal.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>

#include "Binary.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

Decimal::Decimal(std::string num) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::transform(num.begin(), num.end(), num.begin(), ::tolower);

    if (num.find("nan") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    // trim decimal string
    if (num.substr(0, 2) == "0d")
        num = num.substr(2, num.length());
    else if (num.substr(0, 3) == "-0d")
        num = "-" + num.substr(3, num.length());
    else if (num.substr(0, 1) == "d")
        num = num.substr(1, num.length());

    clean_number(num);  // clean if it starts/ends with 0

    this->num = num;
}

Decimal::Decimal(const Decimal &d) : NumberBase(d) {}

Decimal::Decimal(const Binary &b) {
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = b.num;

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
    std::string intPoint;

    if (number.length() != 0) {
        intPoint = number.substr(0, number.find('.'));
    }

    std::string decPoint;
    if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
        decPoint = number.substr(number.find('.') + 1, number.length());
    }

    // calculate the decimal number from binary
    unsigned long long integer = 0;
    for (int i = intPoint.length() - 1; i >= 0; i--) {
        integer +=
            static_cast<int>(intPoint[i] - '0') * pow(2, intPoint.length() - i - 1);
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
                result.push_back(
                    static_cast<char>(((unsigned long long)decimal) + '0'));
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
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = o.num;

    std::transform(number.begin(), number.end(), number.begin(), ::tolower);

    if (number.find("nan") != std::string::npos) {
        this->num = "NaN";
        return;
    }

    std::string result;

    if (number.at(0) == '-') {
        number = number.substr(1, number.length());
        result += "-";
    }

    clean_number(number);  // clean if it starts/ends with 0

    if (number.length() == 0 || number == "0.0") {
        this->num = "0.0";
        return;
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if (number.length() != 0) {
        intPoint = std::stoull(number.substr(0, number.find('.')));
    }

    std::string decPoint;
    if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
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
                result.push_back(
                    static_cast<char>(((unsigned long long)decimal) + '0'));
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
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    std::string number = h.num;

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
    if (number.find('.') != -1 && number.length() > number.find('.') + 1) {
        decPoint = number.substr(number.find('.') + 1, number.length());
    }

    std::string sResult;

    // calculate the integer part of decimal from hexadecimal
    for (int i = intPoint.length() - 1; i >= 0; i--) {
        // if char is not digit
        if (intPoint[i] >= 65 && intPoint[i] <= 70)                                                  /** ABCDEF in ascii */
            result += static_cast<int>(intPoint[i] - 'A' + 10) * pow(16, intPoint.length() - i - 1); /** 65 is A, so -55 will be 10 */
        else
            result += static_cast<int>(intPoint[i] - '0') * pow(16, intPoint.length() - i - 1);
    }

    for (char i : std::to_string(static_cast<unsigned long long>(result))) {
        sResult.push_back(i);
    }
    sResult.push_back('.');
    result = 0;

    if (!decPoint.empty()) {
        int iterator = -1;
        for (char i : decPoint) {
            if (i >= 65 && i <= 70) /** ABCDEF in ascii */
                result += static_cast<int>(i - 'A' + 10) * pow(16, iterator);
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

    if (isItNegative)
        sResult.insert(0, "-");

    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());

    this->num = sResult;
}

Octal Decimal::toOct() const { return Octal(*this); }

Decimal Decimal::toDec() const { return Decimal{*this}; }

Binary Decimal::toBin() const { return Binary(*this); }

Hexadecimal Decimal::toHex() const { return Hexadecimal(*this); }

Decimal::Decimal(const int &num) { this->num = std::to_string(num) + ".0"; }

Decimal::Decimal(const double &num) {
    this->num = std::to_string(num);
    clean_number(this->num);
}

#pragma region operators

std::ostream &operator<<(std::ostream &output, const Decimal &d) {
    return output << d.num << "d";
}

Decimal::operator std::string() { return this->num; }

Decimal &Decimal::operator=(const NumberBase &other) {
    if (this == &other)
        return *this;

    // Try to cast `other` to `const Binary&`
    const Decimal *decPtr = dynamic_cast<const Decimal *>(&other);
    if (decPtr) {
        this->num = decPtr->num;
    } else {
        this->num = other.toDec().num;
    }

    return *this;
}

Decimal Decimal::operator+(const NumberBase &other) {
    Decimal result(*this), second = other.toDec();

    // calculate the sum of decimal values
    result.num = sum(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator+=(const NumberBase &other) {
    *this = *this + other;
    return *this;
}

Decimal Decimal::operator-(const NumberBase &other) {
    // Converting values to Decimal/Create result object
    Decimal result(*this), second(other.toDec());

    // calculate the subtracting of decimal values
    result.num = this->sub(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator-=(const NumberBase &other) {
    *this = *this - other;
    return *this;
}

Decimal Decimal::operator*(const NumberBase &other) {
    // creating return object/converting other object
    Decimal result(*this), second(other.toDec());

    // calculate the multiplying of decimal values
    result.num = this->mul(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator*=(const NumberBase &other) {
    *this = *this * other;
    return *this;
}

Decimal Decimal::operator/(const NumberBase &other) {
    // creating return object/converting other object
    Decimal result(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Divide by 0 exception.");

    // calculate the multiplying of decimal values
    result.num = this->div(result.num, second.num);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator/=(const NumberBase &other) {
    *this = *this / other;
    return *this;
}

Decimal Decimal::operator%(const NumberBase &other) {
    // creating return object/converting other object
    Decimal result(*this), second(other.toDec());

    if (second.num == "0.0")
        throw std::runtime_error("Domain number cannot be zero!");

    // calculate the multiplying of decimal values
    result.num = to_string_with_precision(fmod(std::stod(result.num), std::stod(second.num)), 30);

    // remove the last indexes if it is 0
    while (result.num.at(result.num.length() - 1) == '0' && result.num.at(result.num.length() - 2) != '.')
        result.num = result.num.substr(0, result.num.length() - 1);

    return result;
}

Decimal &Decimal::operator%=(const NumberBase &other) {
    *this = *this % other;
    return *this;
}

#pragma endregion operators