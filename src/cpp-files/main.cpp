#include <iostream>

#include "../header-files/Number/Binary.h"
#include "../header-files/Number/Decimal.h"
#include "../header-files/Number/Hexadecimal.h"
#include "../header-files/Number/Octal.h"

Decimal d("12.75");
Octal o("175.652");
Hexadecimal h("1FC.ABF");
Binary b("1100111011.110111101");
Number *n;

std::ostream &operator<<(std::ostream &output, const Number &n) {
    output << n.num << std::endl;
    return output;
}
// test successful
void testConstructors() {
    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary(d);
    std::cout << *n;
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal(d);
    std::cout << *n;
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal(d);
    std::cout << *n;
    // print hexa value of Decimal(12.75) = C.C
    n = new Hexadecimal(d);
    std::cout << *n << std::endl;


    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary(o);
    std::cout << *n;
    // print octal value of Octal(175.652) = 175.652
    n = new Octal(o);
    std::cout << *n;
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal(o);
    std::cout << *n;
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal(o);
    std::cout << *n << std::endl;

    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary(h);
    std::cout << *n;
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal(h);
    std::cout << *n;
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal(h);
    std::cout << *n;
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal(h);
    std::cout << *n << std::endl;

    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary(b);
    std::cout << *n;
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal(b);
    std::cout << *n;
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal(b);
    std::cout << *n;
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal(b);
    std::cout << *n << std::endl;
}

// test successful
void testConverters() {
    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary;
    *n = d.toBin();
    std::cout << *n;
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal;
    *n = d.toOct();
    std::cout << *n;
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal;
    *n = d.toDec();
    std::cout << *n;
    // print hexa value of Decimal(12.75) = C.C
    n = new Hexadecimal;
    *n = d.toHex();
    std::cout << *n << std::endl;

    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary;
    *n = o.toBin();
    std::cout << *n;
    // print octal value of Octal(175.652) = 175.652
    n = new Octal;
    *n = o.toOct();
    std::cout << *n;
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal;
    *n = o.toDec();
    std::cout << *n;
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal;
    *n = o.toHex();
    std::cout << *n << std::endl;

    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary;
    *n = h.toBin();
    std::cout << *n;
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal;
    *n = h.toOct();
    std::cout << *n;
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal;
    *n = h.toDec();
    std::cout << *n;
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal;
    *n = h.toHex();
    std::cout << *n << std::endl;

    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary;
    *n = b.toBin();
    std::cout << *n;
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal;
    *n = b.toOct();
    std::cout << *n;
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal;
    *n = b.toDec();
    std::cout << *n;
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal;
    *n = b.toHex();
    std::cout << *n << std::endl;

}

int main() {
    testConverters();
    return 0;
}
