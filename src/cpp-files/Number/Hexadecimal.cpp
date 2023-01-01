
#include "../header-files/Number/Hexadecimal.h"

#include <iostream>
#include <utility>

Hexadecimal::Hexadecimal(std::string num) : Number(std::move(num)) {}

Hexadecimal::Hexadecimal(const Octal &o) : Number(o) {}

Hexadecimal::Hexadecimal(const Decimal &d) : Number(d) {}

Hexadecimal::Hexadecimal(const Binary &b) : Number(b) {}

Hexadecimal::Hexadecimal(const Hexadecimal &h) : Number(h) {}

Octal Hexadecimal::toOct() {
    std::cout << "Hexadecimal class toOct() worked" << std::endl;
    return Octal();
}
Decimal Hexadecimal::toDec() {
    std::cout << "Hexadecimal class toDec() worked" << std::endl;
    return Decimal();
}
Binary Hexadecimal::toBin() {
    std::cout << "Hexadecimal class toBin() worked" << std::endl;
    return Binary();
}
Hexadecimal Hexadecimal::toHex() {
    std::cout << "Hexadecimal class toHex() worked" << std::endl;
    return Hexadecimal();
}
