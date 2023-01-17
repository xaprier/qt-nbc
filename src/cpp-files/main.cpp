#include <cassert>
#include <iomanip>
#include <iostream>

#include "../header-files/Number/Binary.h"
#include "../header-files/Number/Decimal.h"
#include "../header-files/Number/Hexadecimal.h"
#include "../header-files/Number/Octal.h"

Decimal d("12.75");
Octal o("175.652");                // 125.83203125
Hexadecimal h("1FC.ABF");          // 508.671630859375
Binary b("1100111011.110111101");  // 827.869140625
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
    // decimal + decimal = 25.50
    res = d + d;
    std::cout << res << std::endl;
    // decimal + binary = 840.619140625
    res = d + b;
    std::cout << res << std::endl;
    // decimal + octal = 138.58203125
    res = d + o;
    std::cout << res << std::endl;
    // decimal + hexadecimal  = 521.421630859375
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

// test successful
void operator_subtractOverloading() {
    std::cout << std::endl;
    Binary res;
    // binary - binary - binary = -827.869140625 = -1100111011.110111101
    res = b - b - b;
    std::cout << res << std::endl;
    // binary - octal = 702.037109375 = 1010111110.000010011
    res = b - o;
    std::cout << res << std::endl;
    // binary - decimal = 815.119140625 = 1100101111.000111101
    res = b - d;
    std::cout << res << std::endl;
    // binary - hexadecimal = 319.197509765625 = 100111111.001100101001
    res = b - h;
    std::cout << res << std::endl;

    Octal res2;
    // octal - octal - octal = -125.83203125 = -175.652
    res2 = o - o - o;
    std::cout << res2 << std::endl;
    // octal - binary = -702.037109375 = -1276.023
    res2 = o - b;
    std::cout << res2 << std::endl;
    // octal - decimal = 113.08203125 = 161.052
    res2 = o - d;
    std::cout << res2 << std::endl;
    // octal - hexadecimal = -382.839599609375 = -576.6557
    res2 = o - h;
    std::cout << res2 << std::endl;

    Decimal res3;
    // decimal - decimal - decimal = -12.75
    res3 = d - d - d;
    std::cout << res3 << std::endl;
    // decimal - binary = -815.119140625
    res3 = d - b;
    std::cout << res3 << std::endl;
    // decimal - octal = -113.08203125
    res3 = d - o;
    std::cout << res3 << std::endl;
    // decimal - hexadecimal = -495.921630859375
    res3 = d - h;
    std::cout << res3 << std::endl;

    Hexadecimal res4;
    // hexadecimal - hexadecimal - hexadecimal = -508.671630859375 = -1FC.ABF
    res4 = h - h - h;
    std::cout << res4 << std::endl;
    // hexadecimal - binary = -319.197509765625 = -13F.329
    res4 = h - b;
    std::cout << res4 << std::endl;
    // hexadecimal - octal = 382.839599609375 = 17E.D6F
    res4 = h - o;
    std::cout << res4 << std::endl;
    // hexadecimal - decimal = 495.921630859375 = 1EF.EBF
    res4 = h - d;
    std::cout << res4 << std::endl;
}

void operator_multiplyOverloading() {
    Binary res1;
    // binary * binary = 827.869140625 * -827.869140625 = -685367.313999176025390625 = -10100111010100110111.010100000110001001
    res1 = b * Binary("-1100111011.110111101"); // confirmed
    std::cout << Decimal(res1) << " " << res1 << std::endl;
    // binary * octal = 827.869140625 * -125.83203125 = -104172.45557403564453125 = -11001011011101100.01110100101000001
    res1 = b * Octal("-175.652"); // confirmed
    std::cout << Decimal(res1) << " " << res1 << std::endl;
    // binary * decimal = 827.869140625 * -12.75 = -10555.33154296875 = -10100100111011.01010100111
    res1 = b * Decimal("-12.75"); // confirmed
    std::cout << Decimal(res1) << " " << res1 << std::endl;
    // binary * hexadecimal = 827.869140625 * -508.671630859375 = -421113.545899868011474609375 =  -1100110110011111001.100010111100000000011
    res1 = b * Hexadecimal("-1FC.ABF"); // confirmed
    std::cout << Decimal(res1) << " " << res1 << std::endl;

    Octal res2;
    // octal * octal = 125.83203125 * -125.83203125 = -15833.7000885009765625 = -36731.546344
    res2 = o * Octal("-175.652"); // confirmed
    std::cout << res2.toDec() << " " << res2 << std::endl;
    // octal * binary = 125.83203125 * -827.869140625 = -104172.45557403564453125 = -313354.351202
    res2 = o * Binary("-1100111011.110111101"); // confirmed
    std::cout << res2.toDec() << " " << res2 << std::endl;
    // octal * decimal = 125.83203125 * -12.75 = -1604.3583984375 = -3104.2674
    res2 = o * Decimal("-12.75"); // confirmed
    std::cout << res2.toDec() << " " << res2 << std::endl;
    // octal * hexadecimal = 125.83203125 * -508.671630859375 = -64007.18455028533935546875 = -175007.1363726
    res2 = o * Hexadecimal("-1FC.ABF"); // confirmed
    std::cout << res2.toDec() << " " << res2 << std::endl;

    Decimal res3;
    // decimal * decimal = 12.75 * -12.75 = -162.5625
    res3 = d * Decimal("-12.75"); // confirmed
    std::cout << res3 << std::endl;
    // decimal * binary = 12.75 * -827.869140625 = -10555.33154296875
    res3 = d * Binary("-1100111011.110111101"); // confirmed
    std::cout << res3 << std::endl;
    // decimal * octal = 12.75 * -125.83203125 = -1604.3583984375
    res3 = d * Octal("-175.652"); // confirmed
    std::cout << res3 << std::endl;
    // decimal * hexadecimal = 12.75 * -508.671630859375 = -6485.563293457031
    res3 = d * Hexadecimal("-1FC.ABF"); // confirmed
    std::cout << res3 << std::endl;

    Hexadecimal res4;
    // hexadecimal * hexadecimal = 508.671630859375 * -508.671630859375 = -258746.828041136264801025390625 = -3F2BA.D3FA81
    res4 = h * Hexadecimal("-1FC.ABF"); // confirmed
    std::cout << res4.toDec() << " " << res4 << std::endl;
    // hexadecimal * binary = 508.671630859375 * -827.869140625 = -421113.545899868011474609375 = -66CF9.8BC018
    res4 = h * Binary("-1100111011.110111101"); // confirmed
    std::cout << res4.toDec() << " " << res4 << std::endl;
    // hexadecimal * octal = 508.671630859375 * -125.83203125 = -64007.18455028533935546875 = -FA07.2F3EB
    res4 = h * Octal("-175.652"); // confirmed
    std::cout << res4.toDec() << " " << res4 << std::endl;
    // hexadecimal * octal = 508.671630859375 * -12.75 = -6485.56329345703125 = -1955.9034
    res4 = h * Decimal("-12.75"); // confirmed
    std::cout << res4.toDec() << " " << res4 << std::endl;
}

int main() {
    testConstructors();
    testConverters();
    ostreamOverloadTest();
    operator_plusOverloading();
    operator_subtractOverloading();
    operator_multiplyOverloading();

    return 0;
}
