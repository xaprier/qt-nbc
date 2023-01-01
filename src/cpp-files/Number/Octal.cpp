#include "../header-files/Octal.h"

#include <iostream>
#include <utility>
Octal::Octal(std::string num) : Number(std::move(num)) {}
Octal::Octal(const Hexadecimal &h) : Number(h) {}
Octal::Octal(const Decimal &d) : Number(d) {}
Octal::Octal(const Binary &b) : Number(b) {}
Octal::Octal(const Octal &o) : Number(o) {}

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
