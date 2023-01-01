#include "../header-files/Number/Decimal.h"

#include <iostream>
#include <utility>
Decimal::Decimal(std::string num) : Number(std::move(num)) {}

Decimal::Decimal(const Decimal &d) : Number(d) {}

Decimal::Decimal(const Binary &b) : Number(b) {}

Decimal::Decimal(const Octal &o) : Number(o) {}

Decimal::Decimal(const Hexadecimal &h) : Number(h) {}

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
