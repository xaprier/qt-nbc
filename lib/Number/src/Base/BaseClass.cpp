#include <cstdint>
#include <sstream>
#include <string>
#include <utility>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "NumberBase.hpp"
#include "Octal.hpp"

NumberBase::NumberBase(std::string NumberBase) : num(std::move(NumberBase)) {}

NumberBase::NumberBase(const Octal &o) : num(o.num) {}

NumberBase::NumberBase(const Hexadecimal &h) : num(h.num) {}

NumberBase::NumberBase(const Binary &b) : num(b.num) {}

NumberBase::NumberBase(const Decimal &d) : num(d.num) {}

std::string NumberBase::to_string_with_precision(const long double &value, int precision) {
    std::ostringstream out;
    out.precision(precision);
    out << std::fixed << value;
    return out.str();
}

void NumberBase::clean_number(std::string &num) {
    if (num == "NaN") return;

    if (num == "0" || num == "0.0" || num.empty()) {
        num = "0.0";
        return;
    }

    if (num.find('.') == -1)
        num += ".0";

    bool isItNegative = num.at(0) == '-';
    num = isItNegative ? num.substr(1, num.length()) : num;

    while (num.at(0) == '0' && num.at(1) != '.')
        num = num.substr(1, num.length());

    while (num.at(num.length() - 1) == '0' && num.at(num.length() - 2) != '.')
        num = num.substr(0, num.length() - 1);

    num = (num == "-." || num == "." || num == ".0") ? "0.0" : num;

    num = isItNegative ? "-" + num : num;
}

std::string NumberBase::sum(std::string val1, std::string val2) {
    if (val1 == "NaN" || val2 == "NaN")
        return "NaN";
    bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
    // remove the first character if it is negative
    val1[0] == '-' ? val1.erase(0, 1) : "";
    val2[0] == '-' ? val2.erase(0, 1) : "";
    std::string result;

    if (!val1IsNegative && val2IsNegative) {  // 13 + -52 = 13 - 52
        return this->sub(val1, val2);
    } else if (val1IsNegative && !val2IsNegative) {  // -13 + 52 = 52 - 13;
        return this->sub(val2, val1);
    } else if (val1IsNegative && val2IsNegative) {  // -13 + -52 = "-" + (13 + 52)
        return "-" + this->sum(val1, val2);
    }

    // integer to .
start:
    if (val1.find('.') != -1 && val2.find('.') != -1) {
        if (val1.find('.') > val2.find('.'))
            while (val1.find('.') != val2.find('.'))
                val2.insert(0, "0");
        else if (val1.find('.') < val2.find('.'))
            while (val1.find('.') != val2.find('.'))
                val1.insert(0, "0");
    } else if (val2.find('.') == -1) {
        val2.append(".0");
        goto start;
    } else if (val1.find('.') == -1) {
        val1.append(".0");
        goto start;
    }

    // . to end
    if (val1.substr(val1.find('.') + 1, val1.length()).length() < val2.substr(val2.find('.') + 1, val2.length()).length())
        while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
            val1.append("0");
    else if (val1.substr(val1.find('.') + 1, val1.length()).length() > val2.substr(val2.find('.') + 1, val2.length()).length())
        while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
            val2.append("0");

    int got = 0, i = 0;
    std::size_t index = val1.length() - 1;
    while (index != SIZE_MAX) {
        if (val1[index] == '.') {
            result.insert(0, ".");
            index--;
            continue;
        }

        i = int(val1[index] - '0') + int(val2[index] - '0') + got;

        got = 0;
        if (i >= 10) {
            got += 1;
            i %= 10;
        }
        result.insert(result.begin(), char(i + '0'));
        index--;
    }

    result.insert(result.begin(), char(got + '0'));

    clean_number(result);

    return result;
}

std::string NumberBase::sub(std::string val1, std::string val2) {
    if (val1 == "NaN" || val2 == "NaN")
        return "NaN";
    bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
    // remove the first character if it is negative
    val1[0] == '-' ? val1.erase(0, 1) : "";
    val2[0] == '-' ? val2.erase(0, 1) : "";
    std::string result;
    clean_number(val1);
    clean_number(val2);
    if (val1.empty() || val1 == "0.0")
        return "-" + val2;
    if (!val1IsNegative && val2IsNegative) {  // - - = +
        return this->sum(val1, val2);
    } else if (val1IsNegative && !val2IsNegative) {
        return "-" + this->sum(val2, val1);
    } else if (val1IsNegative && val2IsNegative) {
        return this->sub(val2, val1);
    } else if (std::stod(val1) < std::stod(val2)) {
        return "-" + this->sub(val2, val1);
    }

    // integer to .
    if (val1.find('.') != -1 && val2.find('.') != -1) {
        if (val1.find('.') > val2.find('.'))
            while (val1.find('.') != val2.find('.'))
                val2.insert(val2.begin(), '0');
        else if (val1.find('.') < val2.find('.'))
            while (val1.find('.') != val2.find('.'))
                val1.insert(val1.begin(), '0');
    } else if (val2.find('.') == -1)
        val2.append(".0");
    else if (val1.find('.') == -1)
        val1.append(".0");

    // . to end
    if (val1.substr(val1.find('.') + 1, val1.length()).length() < val2.substr(val2.find('.') + 1, val2.length()).length())
        while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
            val1.append("0");
    else if (val1.substr(val1.find('.') + 1, val1.length()).length() > val2.substr(val2.find('.') + 1, val2.length()).length())
        while (val1.substr(val1.find('.') + 1, val1.length()).length() != val2.substr(val2.find('.') + 1, val2.length()).length())
            val2.append("0");

    int borrow = 0, i = 0;
    std::size_t index = val1.length() - 1;
    while (index != SIZE_MAX) {
        if (val1[index] == '.') {
            result.insert(result.begin(), '.');
            index--;
            continue;
        }

        i = int(val1[index] - '0') - int(val2[index] - '0') - borrow;

        borrow = 0;
        if (i < 0) {
            borrow += 1;
            i += 10;
        }
        result.insert(result.begin(), char(i + '0'));
        index--;
    }

    clean_number(result);

    return result;
}

std::string NumberBase::mul(std::string val1, std::string val2) {
    if (val1 == "NaN" || val2 == "NaN")
        return "NaN";

    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");
    clean_number(val1);
    clean_number(val2);

    bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
    // remove the first character if it is negative
    val1[0] == '-' ? val1.erase(0, 1) : "";
    val2[0] == '-' ? val2.erase(0, 1) : "";

    if ((!val1IsNegative && val2IsNegative) || (val1IsNegative && !val2IsNegative)) {  // + * - = - || - * + = -
        return "-" + this->mul(val1, val2);
    } else if (val1IsNegative && val2IsNegative) {  // - * - = +
        return this->mul(val1, val2);
    }

    std::size_t decLoc = val1.substr(val1.find('.') + 1, val1.length()).length() + val2.substr(val2.find('.') + 1, val2.length()).length();
    std::string tVal1 = val1.substr(0, val1.find('.')) + val1.substr(val1.find('.') + 1, val1.length());
    std::string tVal2 = val2.substr(0, val2.find('.')) + val2.substr(val2.find('.') + 1, val2.length());
    auto *results = new std::string[tVal2.length()];
    std::size_t firstLen;
    for (std::size_t i = tVal2.length() - 1; i != SIZE_MAX; i--) {
        std::string n;
        int got = 0;
        for (std::size_t j = tVal1.length() - 1; j != SIZE_MAX; j--) {
            int res = int(tVal2[i] - '0') * int(tVal1[j] - '0') + got;
            got = static_cast<int>(res / 10);
            n.insert(n.begin(), static_cast<char>(res % 10 + '0'));
        }
        if (got > 0)
            n.insert(n.begin(), static_cast<char>(got + '0'));

        if (i == tVal2.length() - 1)
            firstLen = n.length();
        results[i] = std::string(firstLen - n.length() + i + 1, '0') + n + std::string(tVal2.length() - i - 1, '0');
    }

    std::string result = "0";
    for (int i = 0; i < tVal2.length(); i++) {
        result = this->sum(result, results[i]);
    }

    result.erase(result.size() - 2);  // remove last 2 items(.0)
    if (result.length() - decLoc < result.length())
        result.insert(result.length() - decLoc, ".");
    else
        result += ".0";

    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());
    clean_number(result);

    return result;
}

std::string NumberBase::div(std::string val1, std::string val2) {
    if (val1 == "NaN" || val2 == "NaN")
        return "NaN";
    bool val1IsNegative = val1[0] == '-', val2IsNegative = val2[0] == '-';
    // remove the first character if it is negative
    val1[0] == '-' ? val1.erase(0, 1) : "";
    val2[0] == '-' ? val2.erase(0, 1) : "";

    if ((!val1IsNegative && val2IsNegative) || (val1IsNegative && !val2IsNegative)) {  // + / - = - || - / + = -
        return "-" + this->div(val1, val2);
    } else if (val1IsNegative && val2IsNegative) {  // - / - = +
        return this->div(val1, val2);
    }

    std::string result;
    // create decimal point if not exist
    if (val1.find('.') == std::string::npos) {
        val1 += ".";
    }
    if (val2.find('.') == std::string::npos) {
        val2 += ".";
    }

    // make decimal points equal
    std::size_t i = val1.substr(val1.find('.') + 1, val1.length()).length(), j = val2.substr(val2.find('.') + 1, val2.length()).length();
    if (i > j) {
        val2.append(std::string(i - j, '0'));
    } else if (j > i) {
        val1.append(std::string(j - i, '0'));
    }

    // erase decimal points
    val1.erase(val1.find('.'), 1);
    val2.erase(val2.find('.'), 1);
    unsigned long long divisor;

    try {
        // divide and get remainder
        divisor = stoull(val2);
    } catch (const std::out_of_range &oor) {
        std::cerr << oor.what() << " threw std::out_of_range on second value\n";
        return "NaN";
    }

    unsigned long long remainder;

    try {
        remainder = std::stoull(val1) % divisor;
    } catch (const std::out_of_range &oor) {
        std::cerr << oor.what() << " threw std::out_of_range on first value\n";
        return "NaN";
    }

    result += std::to_string(static_cast<unsigned long long>(stoull(val1) / divisor));
    if (remainder != 0) {
        result += ".";
        std::string temp;
        while (remainder != 0) {
            remainder *= 10;
            if (remainder < divisor) {
                result += "0";
            } else if (remainder > divisor) {
                result += std::to_string(remainder / divisor);
                remainder %= divisor;
            } else {
                result += std::to_string(remainder / divisor);
                break;
            }
            // break the loop if the result is repeating
            if (result.substr(result.find('.') + 1, result.length()).length() > 16) {
                temp = result.substr(result.length() - 16, result.length());
                if (result.find(temp, result.find(temp) + 1) != std::string::npos) {
                    result = result.substr(0, result.length() - 16);
                    break;
                }
            }
        }
    } else {
        result += ".0";
    }

    return result;
}

bool NumberBase::operator<(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-';
}

bool NumberBase::operator<(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-';
}

bool NumberBase::operator<(const Decimal &second) {
    Decimal *first;
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-';
}

bool NumberBase::operator<(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-';
}
bool NumberBase::operator<=(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-' || first->num == "0.0";
}
bool NumberBase::operator<=(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-' || first->num == "0.0";
}
bool NumberBase::operator<=(const Decimal &second) {
    Decimal *first;
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-' || first->num == "0.0";
}
bool NumberBase::operator<=(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num[0] == '-' || first->num == "0.0";
}

bool NumberBase::operator>(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-';
}

bool NumberBase::operator>(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-';
}

bool NumberBase::operator>(const Decimal &sec) {
    Decimal *first, second(sec);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-';
}
bool NumberBase::operator>(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-';
}

bool NumberBase::operator>=(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-' || second.num == "0.0";
}

bool NumberBase::operator>=(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-' || second.num == "0.0";
}

bool NumberBase::operator>=(const Decimal &sec) {
    Decimal *first, second(sec);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-' || second.num == "0.0";
}

bool NumberBase::operator>=(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    second -= *first;
    return second.num[0] == '-' || second.num == "0.0";
}

bool NumberBase::operator==(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num == "0.0";
}

bool NumberBase::operator==(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num == "0.0";
}

bool NumberBase::operator==(const Decimal &second) {
    Decimal *first;
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num == "0.0";
}

bool NumberBase::operator==(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num == "0.0";
}

bool NumberBase::operator!=(const Binary &b) {
    Decimal *first, second(b);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num != "0.0";
}

bool NumberBase::operator!=(const Octal &o) {
    Decimal *first, second(o);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num != "0.0";
}

bool NumberBase::operator!=(const Decimal &second) {
    Decimal *first;
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num != "0.0";
}

bool NumberBase::operator!=(const Hexadecimal &h) {
    Decimal *first, second(h);
    if (dynamic_cast<Binary *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Binary *>(this));
    } else if (dynamic_cast<Octal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Octal *>(this));
    } else if (dynamic_cast<Decimal *>(this) != nullptr) {
        first = new Decimal(*dynamic_cast<Decimal *>(this));
    } else {
        first = new Decimal(*dynamic_cast<Hexadecimal *>(this));
    }
    *first -= second;
    return first->num != "0.0";
}