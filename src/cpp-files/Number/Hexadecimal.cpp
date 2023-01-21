
#include "../../header-files/Number/Hexadecimal.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

Hexadecimal::Hexadecimal(std::string num) {
    // setting locale for qapplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    clean_number(num); // clean if it starts/ends with 0

    this->num = num;
}
// copy constructor
Hexadecimal::Hexadecimal(const Hexadecimal &h) : Number(h) {}
// converter interface
Hexadecimal::Hexadecimal(const Decimal &d) {
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
        decPoint = std::stod(number.substr(0, number.length()));
        decPoint -= static_cast<unsigned long long>(decPoint);
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

Octal Hexadecimal::toOct() {
    return Octal(*this);
}

Decimal Hexadecimal::toDec() {
    return Decimal(*this);
}

Binary Hexadecimal::toBin() {
    return Binary(*this);
}

Hexadecimal Hexadecimal::toHex() {
    return Hexadecimal(*this);
}

std::ostream &operator<<(std::ostream &output, const Hexadecimal &h) {
    return output << h.num;
}

Hexadecimal Hexadecimal::operator+(Hexadecimal h) {
    // convert objects to decimal for summing
    Decimal first(*this), second(h);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator+(Binary b) {
    // convert objects to decimal for summing
    Decimal first(*this), second(b);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator+(Octal o) {
    // convert objects to decimal for summing
    Decimal first(*this), second(o);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator+(Decimal second) {
    // convert objects to decimal for summing
    Decimal first(*this);

    // calculate the sum of decimal values
    first.num = to_string_with_precision(std::stold(first.num) + std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the sum of values to binary and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator-(Hexadecimal h) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(h);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator-(Binary b) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(b);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator-(Octal o) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(o);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator-(Decimal second) {
    // convert objects to decimal for calculating
    Decimal first(*this);

    // calculate the subtract of decimal values
    first.num = to_string_with_precision(std::stold(first.num) - std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the subtract of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(Hexadecimal h) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(h);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiply of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(Binary b) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(b);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiply of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(Octal o) {
    // convert objects to decimal for calculating
    Decimal first(*this), second(o);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiply of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator*(Decimal second) {
    // convert objects to decimal for calculating
    Decimal first(*this);

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) * std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    // then convert the multiply of values to hexadecimal and return
    return first.toHex();
}

Hexadecimal Hexadecimal::operator/(Hexadecimal h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator/(Binary b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator/(Octal o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator/(Decimal second) {
    // creating return object/converting other object
    Decimal first(*this);

    try {
        if (second.num == "0.0")
            throw "Divide by 0 exception. Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(std::stold(first.num) / std::stold(second.num), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator%(Hexadecimal h) {
    // creating return object/converting other object
    Decimal first(*this), second(h);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator%(Binary b) {
    // creating return object/converting other object
    Decimal first(*this), second(b);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator%(Octal o) {
    // creating return object/converting other object
    Decimal first(*this), second(o);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}

Hexadecimal Hexadecimal::operator%(Decimal second) {
    // creating return object/converting other object
    Decimal first(*this);

    try {
        if (second.num == "0.0")
            throw "Domain number cannot be zero! Exiting...";
    } catch(const char* er) {
        std::cerr << er << std::endl;
        exit(1);
    }

    // calculate the multiply of decimal values
    first.num = to_string_with_precision(fmod(std::stold(first.num), std::stold(second.num)), 30);

    // remove the last indexes if it is 0
    while (first.num.at(first.num.length() - 1) == '0' && first.num.at(first.num.length() - 2) != '.')
        first.num = first.num.substr(0, first.num.length() - 1);

    return first.toHex();
}
