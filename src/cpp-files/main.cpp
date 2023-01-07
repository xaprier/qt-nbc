#include <iostream>
#include <iomanip>
#include <cassert>

#include "../header-files/Number/Binary.h"
#include "../header-files/Number/Decimal.h"
#include "../header-files/Number/Hexadecimal.h"
#include "../header-files/Number/Octal.h"

Decimal d("12.75");
Octal o("175.652"); // 125.83203125
Hexadecimal h("1FC.ABF"); // 508.671630859375
Binary b("1100111011.110111101"); // 827.869140625
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

// test successful
void ostreamOverloadTest() {
    // for testing the number object
    n = new Binary(d);

    std::cout << d << " " << o << " " << h << " " << b << " " << *n << std::endl;
}

// test successful
void operator_plusOverloading() {
    Binary res2;

    // binary + binary = 1655.73828125 = 11001110111.10111101
    res2 = b + b;
    std::cout << res2 << std::endl;

    // binary + octal = 953.701171875 = 1110111001.101100111
    res2 = b + o;
    std::cout << res2 << std::endl;

    // binary + decimal = 840.619140625 = 1101001000.100111101
    res2 = b + d;
    std::cout << res2 << std::endl;

    // binary + hexadecimal = 1336.540771484375 = 10100111000.100010100111
    res2 = b + h;
    std::cout << res2 << std::endl;

    Octal res4;
    // octal + octal = 251.6640625 = 373.524
    res4 = o + o;
    std::cout << res4 << std::endl;
    // octal + binary = 953.701171875 = 1671.547
    res4 = o + b;
    std::cout << res4 << std::endl;
    // octal + decimal = 138.58203125 = 212.452
    res4 = o + d;
    std::cout << res4 << std::endl;
    // octal + hexadecimal = 634.503662109375 = 1172.4017
    res4 = o + h;
    std::cout << res4 << std::endl;

    // add the control of including . for precision finder
    Decimal res;

    // decimal + decimal = 25.500
    res = d + d;
    std::cout << res << std::endl;

    // decimal + binary = 840.61914062500
    res = d + b;
    std::cout << res << std::endl;

    // decimal + octal = 138.5820312500
    res = d + o;
    std::cout << res << std::endl;

    // decimal + hexadecimal  = 521.42163085937500
    res = d + h;
    std::cout << res << std::endl;

    Hexadecimal res3;

    // hexadecimal + hexadecimal = 1017.34326171875 = 3F9.57E
    res3 = h + h;
    std::cout << res3 << std::endl;

    // hexadecimal + binary = 1336.540771484375 = 538.8A7
    res3 = h + b;
    std::cout << res3 << std::endl;

    // hexadecimal + octal = 634.503662109375 = 27A.80F
    res3 = h + o;
    std::cout << res3 << std::endl;

    // hexadecimal + decimal = 521.421630859375 = 209.6BF
    res3 = h + d;
    std::cout << res3 << std::endl;
}

int main() {
    testConstructors();
    testConverters();
    ostreamOverloadTest();
    operator_plusOverloading();
    return 0;
}
