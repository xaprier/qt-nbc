#include "../../header-files/Number/Number.h"
#include "header-files/Number/Octal.h"

#include <string>
#include <utility>
#include <cmath>
#include <sstream>

Number::Number(std::string number) : num(std::move(number)) {}

Number::Number( const Octal& o ) : num(o.num) {}

Number::Number( const Hexadecimal& h ) : num(h.num) {}

Number::Number( const Binary& b ) : num(b.num) {}

Number::Number( const Decimal& d ) : num(d.num) {}

std::string Number::to_string_with_precision(const long double value, int precision)
{
    std::ostringstream out;
    out.precision(precision);
    out << std::fixed << value;
    return out.str();
}

void Number::clean_number(std::string &num) {
    bool isItNegative = num.at(0) == '-';
    num = isItNegative ? num.substr(1, num.length()) : num;

    if (num == "0" || num == "0.0") {
        num = "0.0";
        return;
    }

    while(num.at(0) == '0' && num.at(1) != '.')
        num = num.substr(1, num.length());

    while (num.at(num.length() - 1) == '0')
        num = num.substr(0, num.length() - 1);

    num = (num == "-." || num == ".") ? "0.0" : num;

    num = isItNegative ? "-" + num : num;
}
