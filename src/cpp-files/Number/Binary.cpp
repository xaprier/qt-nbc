#include "../header-files/Number/Binary.h"

#include <iostream>
#include <utility>

Binary::Binary(std::string num) : Number(std::move(num)) {}

Binary::Binary(const Binary &b) : Number(b) {}

Binary::Binary(const Octal &o) : Number(o) {}

Binary::Binary(const Hexadecimal &h) : Number(h) {}

Binary::Binary(const Decimal &d) : Number(d) {}

Octal Binary::toOct() {
    std::cout << "Binary class toOct() worked" << std::endl;
    return Octal();
}
Decimal Binary::toDec() {
    std::cout << "Binary class toDec() worked" << std::endl;
    return Decimal();
}
Binary Binary::toBin() {
    std::cout << "Binary class toBin() worked" << std::endl;
    return Binary();
}
Hexadecimal Binary::toHex() {
    std::cout << "Binary class toHex() worked" << std::endl;
    return Hexadecimal();
}
