//
// Created by xaprier on 2/5/23.
//

//! IMPORTANT NOTE
//! THIS TEST CASES REMAINED FROM NOT REFACTORED OLD CODE BUT IT'S WORKS.
//! IF WE TRY TO REFACTOR IT, IT WILL TAKE TOO LONG.
//! SO, THIS PART OF CODE WILL NOT REFACTORED.

#include "test_cases.hpp"

#include <cassert>

Decimal d("12.75");
Octal o("175.652");                // 125.83203125
Hexadecimal h("1FC.ABF");          // 508.671630859375
Binary b("1100111011.110111101");  // 827.869140625
NumberBase *n;

void test(const std::string &expected, const std::string &output, int test_case) {
    if (expected == output) {
        std::cout << "Test " << test_case << " is successful!" << std::endl;
    } else {
        std::cerr << "Test " << test_case << " is unsuccessful!!" << std::endl;
        std::cout << "Expected : " << expected << "\n"
                  << "Output : " << output << std::endl;
        assert(expected == output);
    }
}

// test successful
void testConstructors() {
    std::cout << "Constructors With Parameter Decimal" << std::endl;
    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary(d);
    test(n->getNum(), "1100.11", 0);
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal(d);
    test(n->getNum(), "14.6", 1);
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal(d);
    test(n->getNum(), "12.75", 2);
    // print hexa value of Decimal(12.75) = C.C
    n = new Hexadecimal(d);
    test(n->getNum(), "C.C", 3);

    std::cout << "\nConstructors With Parameter Octal" << std::endl;
    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary(o);
    test(n->getNum(), "1111101.11010101", 0);
    // print octal value of Octal(175.652) = 175.652
    n = new Octal(o);
    test(n->getNum(), "175.652", 1);
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal(o);
    test(n->getNum(), "125.83203125", 2);
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal(o);
    test(n->getNum(), "7D.D5", 3);

    std::cout << "\nConstructors With Parameter Hexadecimal" << std::endl;
    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary(h);
    test(n->getNum(), "111111100.101010111111", 0);
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal(h);
    test(n->getNum(), "774.5277", 1);
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal(h);
    test(n->getNum(), "508.671630859375", 2);
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal(h);
    test(n->getNum(), "1FC.ABF", 3);

    std::cout << "\nConstructors With Parameter Binary" << std::endl;
    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary(b);
    test(n->getNum(), "1100111011.110111101", 0);
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal(b);
    test(n->getNum(), "1473.675", 1);
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal(b);
    test(n->getNum(), "827.869140625", 2);
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal(b);
    test(n->getNum(), "33B.DE8", 3);
}

// test successful
void testConverters() {
    std::cout << "\nBinary toX() Tests" << std::endl;
    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary;
    *n = b.toBin();
    test(n->getNum(), "1100111011.110111101", 0);
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal;
    *n = b.toOct();
    test(n->getNum(), "1473.675", 1);
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal;
    *n = b.toDec();
    test(n->getNum(), "827.869140625", 2);
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal;
    *n = b.toHex();
    test(n->getNum(), "33B.DE8", 3);

    std::cout << "\nDecimal toX() Tests" << std::endl;
    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary;
    *n = d.toBin();
    test(n->getNum(), "1100.11", 0);
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal;
    *n = d.toOct();
    test(n->getNum(), "14.6", 1);
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal;
    *n = d.toDec();
    test(n->getNum(), "12.75", 2);
    // print hexadecimal value of Decimal(12.75) = C.C
    n = new Hexadecimal;
    *n = d.toHex();
    test(n->getNum(), "C.C", 3);

    std::cout << "\nOctal toX() Tests" << std::endl;
    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary;
    *n = o.toBin();
    test(n->getNum(), "1111101.11010101", 0);
    // print octal value of Octal(175.652) = 175.652
    n = new Octal;
    *n = o.toOct();
    test(n->getNum(), "175.652", 1);
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal;
    *n = o.toDec();
    test(n->getNum(), "125.83203125", 2);
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal;
    *n = o.toHex();
    test(n->getNum(), "7D.D5", 3);

    std::cout << "\nHexadecimal toX() Tests" << std::endl;
    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary;
    *n = h.toBin();
    test(n->getNum(), "111111100.101010111111", 0);
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal;
    *n = h.toOct();
    test(n->getNum(), "774.5277", 1);
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal;
    *n = h.toDec();
    test(n->getNum(), "508.671630859375", 2);
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal;
    *n = h.toHex();
    test(n->getNum(), "1FC.ABF", 3);
}

// test successful
void ostreamOverloadTest() {
    // for testing the number object
    n = new Binary(d);
    std::cout << "\nostream<< Operator Overloadings" << std::endl;
    test(d.getNum() + "d 0" + o.getNum() + " 0x" + h.getNum() + " " + b.getNum() + "b " + n->getNum(), "12.75d 0175.652 0x1FC.ABF 1100111011.110111101b 1100.11", 0);
}

// test successful
void operator_plusOverloading() {
    Binary res1;
    // binary + binary = 1655.73828125 = 11001110111.10111101
    res1 = b + b;
    std::cout << "\nBinary Sum Operator Overloadings" << std::endl;
    test(Decimal("1655.73828125").toBin().getNum(), res1.getNum(), 0);
    // binary + octal = 953.701171875 = 1110111001.101100111
    res1 = b + o;
    test(Decimal("953.701171875").toBin().getNum(), res1.getNum(), 1);
    // binary + decimal = 840.619140625 = 1101001000.100111101
    res1 = b + d;
    test(Decimal("840.619140625").toBin().getNum(), res1.getNum(), 2);
    // binary + hexadecimal = 1336.540771484375 = 10100111000.100010100111
    res1 = b + h;
    test(Decimal("1336.540771484375").toBin().getNum(), res1.getNum(), 3);

    std::cout << "\nOctal Sum Operator Overloadings" << std::endl;
    Octal res2;
    // octal + octal = 251.6640625 = 373.524
    res2 = o + o;
    test(Decimal("251.6640625").toOct().getNum(), res2.getNum(), 0);
    // octal + binary = 953.701171875 = 1671.547
    res2 = o + b;
    test(Decimal("953.701171875").toOct().getNum(), res2.getNum(), 1);
    // octal + decimal = 138.58203125 = 212.452
    res2 = o + d;
    test(Decimal("138.58203125").toOct().getNum(), res2.getNum(), 2);
    // octal + hexadecimal = 634.503662109375 = 1172.4017
    res2 = o + h;
    test(Decimal("634.503662109375").toOct().getNum(), res2.getNum(), 3);

    std::cout << "\nDecimal Sum Operator Overloadings" << std::endl;
    // add the control of including . for precision finder
    Decimal res3;
    // decimal + decimal = 25.50
    res3 = d + d;
    test(Decimal("25.5").getNum(), res3.getNum(), 0);
    // decimal + binary = 840.619140625
    res3 = d + b;
    test(Decimal("840.619140625").getNum(), res3.getNum(), 1);
    // decimal + octal = 138.58203125
    res3 = d + o;
    test(Decimal("138.58203125").getNum(), res3.getNum(), 2);
    // decimal + hexadecimal  = 521.421630859375
    res3 = d + h;
    test(Decimal("521.421630859375").getNum(), res3.getNum(), 3);

    std::cout << "\nHexadecimal Sum Operator Overloadings" << std::endl;
    Hexadecimal res4;
    // hexadecimal + hexadecimal = 1017.34326171875 = 3F9.57E
    res4 = h + h;
    test(Decimal("1017.34326171875").toHex().getNum(), res4.getNum(), 0);
    // hexadecimal + binary = 1336.540771484375 = 538.8A7
    res4 = h + b;
    test(Decimal("1336.540771484375").toHex().getNum(), res4.getNum(), 1);
    // hexadecimal + octal = 634.503662109375 = 27A.80F
    res4 = h + o;
    test(Decimal("634.503662109375").toHex().getNum(), res4.getNum(), 2);
    // hexadecimal + decimal = 521.421630859375 = 209.6BF
    res4 = h + d;
    test(Decimal("521.421630859375").toHex().getNum(), res4.getNum(), 3);
}

// test successful
void operator_subtractOverloading() {
    std::cout << "\nBinary Substract Operator Overloadings" << std::endl;
    Binary res;
    // binary - binary - binary = -827.869140625 = -1100111011.110111101
    res = b - b - b;
    test(Decimal("-827.869140625").toBin().getNum(), res.getNum(), 0);
    // binary - octal = 702.037109375 = 1010111110.000010011
    res = b - o;
    test(Decimal("702.037109375").toBin().getNum(), res.getNum(), 1);
    // binary - decimal = 815.119140625 = 1100101111.000111101
    res = b - d;
    test(Decimal("815.119140625").toBin().getNum(), res.getNum(), 2);
    // binary - hexadecimal = 319.197509765625 = 100111111.001100101001
    res = b - h;
    test(Decimal("319.197509765625").toBin().getNum(), res.getNum(), 3);

    std::cout << "\nOctal Substract Operator Overloadings" << std::endl;
    Octal res2;
    // octal - octal - octal = -125.83203125 = -175.652
    res2 = o - o - o;
    test(Decimal("-125.83203125").toOct().getNum(), res2.getNum(), 0);
    // octal - binary = -702.037109375 = -1276.023
    res2 = o - b;
    test(Decimal("-702.037109375").toOct().getNum(), res2.getNum(), 1);
    // octal - decimal = 113.08203125 = 161.052
    res2 = o - d;
    test(Decimal("113.08203125").toOct().getNum(), res2.getNum(), 2);
    // octal - hexadecimal = -382.839599609375 = -576.6557
    res2 = o - h;
    test(Decimal("-382.839599609375").toOct().getNum(), res2.getNum(), 3);

    std::cout << "\nDecimal Substract Operator Overloadings" << std::endl;
    Decimal res3;
    // decimal - decimal - decimal = -12.75
    res3 = d - d - d;
    test(Decimal("-12.75").getNum(), res3.getNum(), 0);
    // decimal - binary = -815.119140625
    res3 = d - b;
    test(Decimal("-815.119140625").getNum(), res3.getNum(), 1);
    // decimal - octal = -113.08203125
    res3 = d - o;
    test(Decimal("-113.08203125").getNum(), res3.getNum(), 2);
    // decimal - hexadecimal = -495.921630859375
    res3 = d - h;
    test(Decimal("-495.921630859375").getNum(), res3.getNum(), 3);

    std::cout << "\nHexadecimal Substract Operator Overloadings" << std::endl;
    Hexadecimal res4;
    // hexadecimal - hexadecimal - hexadecimal = -508.671630859375 = -1FC.ABF
    res4 = h - h - h;
    test(Decimal("-508.671630859375").toHex().getNum(), res4.getNum(), 0);
    // hexadecimal - binary = -319.197509765625 = -13F.329
    res4 = h - b;
    test(Decimal("-319.197509765625").toHex().getNum(), res4.getNum(), 1);
    // hexadecimal - octal = 382.839599609375 = 17E.D6F
    res4 = h - o;
    test(Decimal("382.839599609375").toHex().getNum(), res4.getNum(), 2);
    // hexadecimal - decimal = 495.921630859375 = 1EF.EBF
    res4 = h - d;
    test(Decimal("495.921630859375").toHex().getNum(), res4.getNum(), 3);
}

void operator_multiplyOverloading() {
    std::cout << "\nBinary Multiply Operator Overloadings" << std::endl;
    Binary res1;
    // 1100111011.110111101 * -111111100.101010111111 = -1100110110011111001.100010111100000000011
    res1 = b * Binary("-111111100.101010111111");
    test(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum(), 0);
    // 1100111011.110111101 * -774.5277 = -1100110110011111001.100010111100000000011
    res1 = b * Octal("-774.5277");
    test(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum(), 1);
    // 1100111011.110111101 * -508.671630859375 = -1100110110011111001.100010111100000000011
    res1 = b * Decimal("-508.671630859375");
    test(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum(), 2);
    // 1100111011.110111101 * -1FC.ABF = -1100110110011111001.100010111100000000011
    res1 = b * Hexadecimal("-1FC.ABF");
    test(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum(), 3);

    std::cout << "\nOctal Multiply Operator Overloadings" << std::endl;
    Octal res2;
    // 175.652 * -774.5277 = -175007.1363726
    res2 = o * Octal("-774.5277");
    test(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum(), 0);
    // 175.652 * -111111100.101010111111 = -175007.1363726
    res2 = o * Binary("-111111100.101010111111");
    test(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum(), 1);
    // 175.652 * -508.671630859375 = -175007.1363726
    res2 = o * Decimal("-508.671630859375");
    test(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum(), 2);
    // 175.652 * -1FC.ABF = -175007.1363726
    res2 = o * Hexadecimal("-1FC.ABF");
    test(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum(), 3);

    std::cout << "\nDecimal Multiply Operator Overloadings" << std::endl;
    Decimal res3;
    // 12.75 * -508.671630859375 = -6485.56329345703125
    res3 = d * Decimal("-508.671630859375");
    test(Decimal("-6485.56329345703125").getNum(), res3.getNum(), 0);
    // 12.75 * -111111100.101010111111 = -6485.56329345703125
    res3 = d * Binary("-111111100.101010111111");
    test(Decimal("-6485.56329345703125").getNum(), res3.getNum(), 1);
    // 12.75 * -774.5277 = -6485.56329345703125
    res3 = d * Octal("-774.5277");
    test(Decimal("-6485.56329345703125").getNum(), res3.getNum(), 2);
    // 12.75 * -1FC.ABF = -6485.56329345703125
    res3 = d * Hexadecimal("-1FC.ABF");
    test(Decimal("-6485.56329345703125").getNum(), res3.getNum(), 3);

    std::cout << "\nHexadecimal Multiply Operator Overloadings" << std::endl;
    Hexadecimal res4;
    // 1FC.ABF * -1FC.ABF = -3F2BA.D3FA81
    res4 = h * Hexadecimal("-1FC.ABF");
    test(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum(), 0);
    // 1FC.ABF * -111111100.101010111111 = -3F2BA.D3FA81
    res4 = h * Binary("-111111100.101010111111");
    test(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum(), 1);
    // 1FC.ABF * -774.5277 = -3F2BA.D3FA81
    res4 = h * Octal("-774.5277");
    test(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum(), 2);
    // 1FC.ABF * -508.671630859375 = -3F2BA.D3FA81
    res4 = h * Decimal("-508.671630859375");
    test(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum(), 3);
}

void operator_divideOverloading() {
    std::cout << "\nBinary Divide Operator Overloadings" << std::endl;
    Binary res1;
    // 1100111011.110111101 / -0.101 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Binary("-0000.101");
    test(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum(), 0);
    // 1100111011.110111101 / -0.5 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Octal("-0000.50000");
    test(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum(), 1);
    // 1100111011.110111101 / -0.625 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Decimal("-0000.625000");
    test(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum(), 2);
    // 1100111011.110111101 / -0.A = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Hexadecimal("-000.A000");
    test(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum(), 3);

    std::cout << "\nOctal Divide Operator Overloadings" << std::endl;
    Octal res2;
    // 175.652 / -0.5 = -201.33125
    res2 = o / Octal("-0000.50000");
    test(Decimal("-201.33125").toOct().getNum(), res2.getNum(), 0);
    // 175.652 / -0.101 = -201.33125d
    res2 = o / Binary("-0000.101");
    test(Decimal("-201.33125").toOct().getNum(), res2.getNum(), 0);
    // 175.652 / -0.625 = -201.33125d
    res2 = o / Decimal("-0000.625000");
    test(Decimal("-201.33125").toOct().getNum(), res2.getNum(), 0);
    // 175.652 / -0.A = -201.33125d
    res2 = o / Hexadecimal("-000.A000");
    test(Decimal("-201.33125").toOct().getNum(), res2.getNum(), 0);

    std::cout << "\nDecimal Divide Operator Overloadings" << std::endl;
    Decimal res3;
    // 12.75 / -0.625 = -20.4
    res3 = d / Decimal("-0000.625000");
    test(Decimal("-20.4").getNum(), res3.getNum(), 0);
    // 12.75 / -0.001 = -20.4
    res3 = d / Binary("-0000000.101");
    test(Decimal("-20.4").getNum(), res3.getNum(), 1);
    // 12.75 / -0.5 = -20.4
    res3 = d / Octal("-0000.50000");
    test(Decimal("-20.4").getNum(), res3.getNum(), 2);
    // 12.75 / -0.A = -20.4
    res3 = d / Hexadecimal("-000.A000");
    test(Decimal("-20.4").getNum(), res3.getNum(), 3);

    std::cout << "\nHexadecimal Divide Operator Overloadings" << std::endl;
    Hexadecimal res4;
    // 1FC.ABF / -0.A = -32D.DFE66666666
    res4 = h / Hexadecimal("-000.A000");
    test(Decimal("-813.874609375").toHex().getNum(), res4.getNum(), 0);
    // 1FC.ABF / -0.625 = -32D.DFE66666666
    res4 = h / Decimal("-0000.625000");
    test(Decimal("-813.874609375").toHex().getNum(), res4.getNum(), 1);
    // 1FC.ABF / -0.001 = -32D.DFE66666666
    res4 = h / Binary("-000000.101");
    test(Decimal("-813.874609375").toHex().getNum(), res4.getNum(), 2);
    // 1FC.ABF / -0.5 = -32D.DFE66666666
    res4 = h / Octal("-0000.50000");
    test(Decimal("-813.874609375").toHex().getNum(), res4.getNum(), 3);
}

void operator_remainderOverloading() {
    Decimal d1("4.75");
    Binary b1("100.11");
    Octal o1("4.6");
    Hexadecimal h1("4.C");

    std::cout << "\nBinary Remainder Operator Overloadings" << std::endl;
    Binary res1;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % b1;
    test(Decimal("1.369140625").toBin().getNum(), res1.getNum(), 0);
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % o1;
    test(Decimal("1.369140625").toBin().getNum(), res1.getNum(), 1);
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % d1;
    test(Decimal("1.369140625").toBin().getNum(), res1.getNum(), 2);
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % h1;
    test(Decimal("1.369140625").toBin().getNum(), res1.getNum(), 3);

    std::cout << "\nOctal Remainder Operator Overloadings" << std::endl;
    Octal res2;
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % o1;
    test(Decimal("2.33203125").toOct().getNum(), res2.getNum(), 0);
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % b1;
    test(Decimal("2.33203125").toOct().getNum(), res2.getNum(), 1);
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % d1;
    test(Decimal("2.33203125").toOct().getNum(), res2.getNum(), 2);
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % h1;
    test(Decimal("2.33203125").toOct().getNum(), res2.getNum(), 3);

    std::cout << "\nDecimal Remainder Operator Overloadings" << std::endl;
    Decimal res3;
    // 12.75 % 4.75 = 3.25
    res3 = d % d1;
    test(Decimal("3.25").getNum(), res3.getNum(), 0);
    // 12.75 % 4.75 = 3.25
    res3 = d % b1;
    test(Decimal("3.25").getNum(), res3.getNum(), 1);
    // 12.75 % 4.75 = 3.25
    res3 = d % o1;
    test(Decimal("3.25").getNum(), res3.getNum(), 2);
    // 12.75 % 4.75 = 3.25
    res3 = d % h1;
    test(Decimal("3.25").getNum(), res3.getNum(), 3);

    std::cout << "\nHexaecimal Remainder Operator Overloadings" << std::endl;
    Hexadecimal res4;
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % h1;
    test(Decimal("0.421630859375").toHex().getNum(), res4.getNum(), 0);
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % b1;
    test(Decimal("0.421630859375").toHex().getNum(), res4.getNum(), 1);
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % o1;
    test(Decimal("0.421630859375").toHex().getNum(), res4.getNum(), 2);
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % d1;
    test(Decimal("0.421630859375").toHex().getNum(), res4.getNum(), 3);
}

void operator_assignmentsOverloading() {
    Binary b1("1001.1001");   // 9.5625
    Octal o1("13.54");        // 11.6875
    Decimal d1("157.55");     // 157.55
    Hexadecimal h1("1F.6C");  // 31.421875
    // Binary
    {
        std::cout << "\nBinary Assignment Tests" << std::endl;
        // 9.5625
        b = b1;
        test(b1.getNum(), b.getNum(), 0);
        // 9.5625 + 9.5625 = 19.125
        b += b1;
        test(Decimal("19.125").toBin().getNum(), b.getNum(), 1);
        // 19.125 + 11.6875 = 30.8125
        b += o1;
        test(Decimal("30.8125").toBin().getNum(), b.getNum(), 2);
        // 30.8125 + 157.55 = 188.3625
        b += d1;
        test(Decimal("188.3625").toBin().getNum(), b.getNum(), 3);
        // 188.3625 + 31.421875 = 219.784375
        b += h1;
        test(Decimal("219.784375").toBin().getNum(), b.getNum(), 4);
        // 219.784375 - 9.5625 = 210.221875
        b -= b1;
        test(Decimal("210.221875").toBin().getNum(), b.getNum(), 5);
        // 210.221875 - 11.6875 = 198.534375
        b -= o1;
        test(Decimal("198.534375").toBin().getNum(), b.getNum(), 6);
        // 198.534375 - 157.55 = 40.984375
        b -= d1;
        test(Decimal("40.984375").toBin().getNum(), b.getNum(), 7);
        // 40.984375 - 31.421875 = 9.5625
        b -= h1;
        test(Decimal("9.5625").toBin().getNum(), b.getNum(), 8);

        // 9.5625 * 9.5625 = 91.44140625 = 1011011.01110001b
        b *= b1;
        test(Decimal("91.44140625").toBin().getNum(), b.getNum(), 9);
        // 91.44140625 * 11.6875 = 1068.721435546875
        b *= o1;
        test(Decimal("1068.721435546875").toBin().getNum(), b.getNum(), 10);
        // 1068.721435546875 * 157.55 = 168377.06217041015625
        b *= d1;
        test(Decimal("168377.06217041015625").toBin().getNum(), b.getNum(), 11);
        // 168377.06217041015625 * 31.421875 = 5290723.000385856
        b *= h1;
        test(Decimal("5290723.00038585662841796875").toBin().getNum(), b.getNum(), 12);

        // 5290723.00038585662841796875 / 9.5625
        b /= b1;
        test("NaN", b.getNum(), 13);
        // 9.5625 / 11.6875 = 0.8181818181818181
        b = b1;
        b /= o1;
        test(Decimal("0.81").toBin().getNum(), b.getNum(), 14);
        b = d1.toBin();
        b /= d1;
        test("1.0", b.getNum(), 15);
        b = Decimal("827.869140625").toBin();
        b /= h1;
        test(Decimal("26.3469045251118846096005654544569551944732666015625").toBin().getNum(), b.getNum(), 16);

        // 9.5625 % 3.25 = 3.0625
        b = b1;
        b1 = Binary("11.01");
        b %= b1;
        test(Decimal("3.0625").toBin().getNum(), b.getNum(), 17);
        // 3.0625 % 3.0625 = 0.0
        o1 = Octal("3.04");
        b %= o1;
        test("0.0", b.getNum(), 18);
        // 3.25 % 3 = 0.25
        b = b1;  // 11.01 = 3.25
        b %= Decimal("3");
        test(Decimal("0.25").toBin().getNum(), b.getNum(), 19);
        // 0.25 % 10.6875 = 0.25
        b %= Hexadecimal("A.B");
        test(Decimal("0.25").toBin().getNum(), b.getNum(), 20);
    }
    // Octal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        std::cout << std::endl
                  << "\nOctal Assignment Tests" << std::endl;
        // 11.6875
        o = o1;
        test(o1.getNum(), o.getNum(), 0);
        // 11.6875 + 11.6875 = 23.375
        o = o1;
        o += o1;
        test(Decimal("23.375").toOct().getNum(), o.getNum(), 1);
        // 11.6875 + 9.5625 = 21.25
        o = o1;
        o += b1;
        test(Decimal("21.25").toOct().getNum(), o.getNum(), 2);
        // 11.6875 + 157.55 = 169.2375
        o = o1;
        o += d1;
        test(Decimal("169.2375").toOct().getNum(), o.getNum(), 3);
        // 11.6875 + 31.41796875 = 43.10546875
        o = o1;
        o += h1;
        test(Decimal("43.10546875").toOct().getNum(), o.getNum(), 4);

        // 11.6875 - 11.6875 = 0.0
        o = o1;
        o -= o1;
        test(Decimal("0.0").toOct().getNum(), o.getNum(), 5);
        // 11.6875 - 9.5625 = 2.125
        o = o1;
        o -= b1;
        test(Decimal("2.125").toOct().getNum(), o.getNum(), 6);
        // 11.6875 - 157.55 = -145.8625
        o = o1;
        o -= d1;
        test(Decimal("-145.8625").toOct().getNum(), o.getNum(), 7);
        // 11.6875 - 31.41796875 = -19.73046875
        o = o1;
        o -= h1;
        test(Decimal("-19.73046875").toOct().getNum(), o.getNum(), 8);

        // 11.6875 * 11.6875 = 136.59765625
        o = o1;
        o *= o1;
        test(Decimal("136.59765625").toOct().getNum(), o.getNum(), 9);
        // 11.6875 * 9.5625 = 111.76171875
        o = o1;
        o *= b1;
        test(Decimal("111.76171875").toOct().getNum(), o.getNum(), 10);
        // 11.6875 * 157.55 = 1841.365625
        o = o1;
        o *= d1;
        test(Decimal("1841.365625").toOct().getNum(), o.getNum(), 11);
        // 11.6875 * 31.41796875 = 367.197509765625
        o = o1;
        o *= h1;
        test(Decimal("367.197509765625").toOct().getNum(), o.getNum(), 12);

        // 11.6875 / 11.6875 = 1.0
        o = o1;
        o /= o1;
        test(Decimal("1.0").toOct().getNum(), o.getNum(), 13);
        // 11.6875 / 9.5625 = 1.2
        o = o1;
        o /= b1;
        test(Decimal("1.2").toOct().getNum(), o.getNum(), 14);
        // 11.6875 / 157.55 = 0.07418279911139321
        o = o1;
        o /= d1;
        test(Decimal("0.07418279911139321").toOct().getNum(), o.getNum(), 15);
        // 11.6875 / 31.41796875 = 0.3720004973268681
        o = o1;
        o /= h1;
        test(Decimal("0.3720004973268681").toOct().getNum(), o.getNum(), 16);

        // 11.6875 % 11.6875 = 0.0
        o = o1;
        o %= o1;
        test(Decimal("0.0").toOct().getNum(), o.getNum(), 17);
        // 11.6875 % 9.5625 = 2.125
        o = o1;
        o %= b1;
        test(Decimal("2.125").toOct().getNum(), o.getNum(), 18);
        // 11.6875 % 157.55 = 11.6875
        o = o1;
        o %= d1;
        test(Decimal("11.6875").toOct().getNum(), o.getNum(), 19);
        // 11.6875 % 31.41796875 = 11.6875
        o = o1;
        o %= h1;
        test(Decimal("11.6875").toOct().getNum(), o.getNum(), 20);
    }
    // Decimal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        std::cout << std::endl
                  << "Decimal Assignment Tests" << std::endl;
        // 157.55
        d = d1;
        test(d1.getNum(), d.getNum(), 0);
        // 157.55 + 157.55 = 315.1
        d += d;
        test(Decimal("315.1").getNum(), d.getNum(), 1);
        // 315.1 - 157.55 = 157.55
        d -= d1;
        test(Decimal("157.55").getNum(), d.getNum(), 2);
        // 157.55 * 2 = 315.1
        d *= Decimal("2");
        test(Decimal("315.1").getNum(), d.getNum(), 3);
        // 315.1 / 2 = 157.55
        d /= Decimal("2");
        test(Decimal("157.55").getNum(), d.getNum(), 4);
        // 157.55 - 157.55 = 0.0
        d -= d1;
        test(Decimal("0.0").getNum(), d.getNum(), 5);

        // 157.55 + 9.5625 = 167.1125
        d = d1;
        d += b1;
        test(Decimal("167.1125").getNum(), d.getNum(), 6);
        // 157.55 - 9.5625 = 147.9875
        d = d1;
        d -= b1;
        test(Decimal("147.9875").getNum(), d.getNum(), 7);
        // 157.55 * 9.5625 = 1506.571875
        d = d1;
        d *= b1;
        test(Decimal("1506.571875").getNum(), d.getNum(), 8);
        // 157.55 / 9.5625 = 16.47581699346405228
        d = d1;
        d /= b1;
        test(Decimal("16.47581699346405228").getNum(), d.getNum(), 9);
        // 157.55 % 9.5625 = 4.550000000000011368683772161603
        d = d1;
        d %= b1;
        test(Decimal("4.550000000000011368683772161603").getNum(), d.getNum(), 10);

        // 157.55 + 11.6875 = 169.2375
        d = d1;
        d += o1;
        test(Decimal("169.2375").getNum(), d.getNum(), 11);
        // 157.55 - 11.6875 = 145.8625
        d = d1;
        d -= o1;
        test(Decimal("145.8625").getNum(), d.getNum(), 12);
        // 157.55 * 11.6875 = 1841.365625
        d = d1;
        d *= o1;
        test(Decimal("1841.365625").getNum(), d.getNum(), 13);
        // 157.55 / 11.6875 = 13.4802139037433155
        d = d1;
        d /= o1;
        test(Decimal("13.4802139037433155").getNum(), d.getNum(), 14);
        // 157.55 % 11.6875 = 5.612500000000011368683772161603
        d = d1;
        d %= o1;
        test(Decimal("5.612500000000011368683772161603").getNum(), d.getNum(), 15);

        // 157.55 + 31.41796875 = 188.96796875
        d = d1;
        d += h1;
        test(Decimal("188.96796875").getNum(), d.getNum(), 16);
        // 157.55 - 31.41796875 = 126.13203125
        d = d1;
        d -= h1;
        test(Decimal("126.13203125").getNum(), d.getNum(), 17);
        // 157.55 * 31.41796875 = 4949.9009765625
        d = d1;
        d *= h1;
        test(Decimal("4949.9009765625").getNum(), d.getNum(), 18);
        // 157.55 / 31.41796875 = 5.0146462762650752206887977122964068133780927514608976749968917070744746984955862240457540718637324381449707820465000621658585105060300882755190849185627253512371005843590699987566828297898793982344896183016287454929752579883128186000248663434042024120353102076339674250901404948402337436279995026731319159517592937958473206514981971901031953251274400099465373616809648141240830535869700360561979360934974511998010692527663807037175183389282605992788760412781300509760039786149446723859256496332214347880144224791744373989804799204277011065522814870073355713042397115504165112520203904015914459778689543702598532885739152057689916697749595921919681710804426209125948029342285216958846201666045008081561606365783911475817481039413154295660823075966679099838368767872684321770483650379211736914086783538480666418003232624642546313564590326992415765261718264329230386671639935347507149073728708193460151684694765634713415392266567201293049857018525425836130796966306104687305731692154668655974139002859629491483277384060673877906253885366156906626880517219942807410170334452318786522441874922292676861867462389655601143851796593310953624269551162501554
        d = d1;
        d /= h1;
        test(Decimal("5.0146462762650752206887977122964068133780927514608976749968917070744746984955862240457540718637324381449707820465000621658585105060300882755190849185627253512371005843590699987566828297898793982344896183016287454929752579883128186000248663434042024120353102076339674250901404948402337436279995026731319159517592937958473206514981971901031953251274400099465373616809648141240830535869700360561979360934974511998010692527663807037175183389282605992788760412781300509760039786149446723859256496332214347880144224791744373989804799204277011065522814870073355713042397115504165112520203904015914459778689543702598532885739152057689916697749595921919681710804426209125948029342285216958846201666045008081561606365783911475817481039413154295660823075966679099838368767872684321770483650379211736914086783538480666418003232624642546313564590326992415765261718264329230386671639935347507149073728708193460151684694765634713415392266567201293049857018525425836130796966306104687305731692154668655974139002859629491483277384060673877906253885366156906626880517219942807410170334452318786522441874922292676861867462389655601143851796593310953624269551162501554").getNum(), d.getNum(), 19);
        // 157.55 % 31.41796875 = 0.460156250000011368683772161603
        d = d1;
        d %= h1;
        test(Decimal("0.460156250000011368683772161603").getNum(), d.getNum(), 20);
    }
    // Hexadecimal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        std::cout << std::endl
                  << "Hexadecimal Assignment Tests" << std::endl;
        // 31.41796875
        h = h1;
        test(h1.getNum(), h.getNum(), 0);
        // 31.41796875 + 31.41796875 = 62.8359375
        h = h1;
        h += h1;
        test(Decimal("62.8359375").toHex().getNum(), h.getNum(), 1);
        // 31.41796875 - 31.41796875 = 0
        h = h1;
        h -= h1;
        test(Hexadecimal("0").getNum(), h.getNum(), 2);
        // 31.41796875 * 31.41796875 = 987.0887603759766
        h = h1;
        h *= h1;
        test(Decimal("987.0887603759765625").toHex().getNum(), h.getNum(), 3);
        // 31.41796875 / 31.41796875 = 1
        h = h1;
        h /= h1;
        test(Hexadecimal("1").getNum(), h.getNum(), 4);
        // 31.41796875 % 31.41796875 = 0
        h = h1;
        h %= h1;
        test(Hexadecimal("0").getNum(), h.getNum(), 5);
        // 31.41796875 + 9.5625 = 40.98046875
        h = h1;
        h += b1;
        test(Decimal("40.98046875").toHex().getNum(), h.getNum(), 6);
        // 31.41796875 - 9.5625 = 21.85546875
        h = h1;
        h -= b1;
        test(Decimal("21.85546875").toHex().getNum(), h.getNum(), 7);
        // 31.41796875 * 9.5625 = 300.434326171875
        h = h1;
        h *= b1;
        test(Decimal("300.434326171875").toHex().getNum(), h.getNum(), 8);
        // 31.41796875 / 9.5625 = 3.28553921568627449457
        h = h1;
        h /= b1;
        test(Decimal("3.28553921568627449457").toHex().getNum(), h.getNum(), 9);
        // 31.41796875 % 9.5625 = 2.73046875
        h = h1;
        h %= b1;
        test(Decimal("2.73046875").toHex().getNum(), h.getNum(), 10);

        // 31.41796875 + 11.6875 = 43.10546875
        h = h1;
        h += o1;
        test(Decimal("43.10546875").toHex().getNum(), h.getNum(), 11);
        // 31.41796875 - 11.6875 = 19.73046875
        h = h1;
        h -= o1;
        test(Decimal("19.73046875").toHex().getNum(), h.getNum(), 12);
        // 31.41796875 * 11.6875 = 367.197509765625
        h = h1;
        h *= o1;
        test(Decimal("367.197509765625").toHex().getNum(), h.getNum(), 13);
        // 31.41796875 / 11.6875 = 2.68816844919786090973
        h = h1;
        h /= o1;
        test(Decimal("2.68816844919786090973").toHex().getNum(), h.getNum(), 14);
        // 31.41796875 % 11.6875 = 8.04296875
        h = h1;
        h %= o1;
        test(Decimal("8.04296875").toHex().getNum(), h.getNum(), 15);

        // 31.41796875 + 157.55 = 188.96796875
        h = h1;
        h += d1;
        test(Decimal("188.96796875").toHex().getNum(), h.getNum(), 16);
        // 31.41796875 - 157.55 = -126.13203125000000001665
        h = h1;
        h -= d1;
        test(Decimal("-126.13203125000000001665").toHex().getNum(), h.getNum(), 17);
        // 31.41796875 * 157.55 = 4949.90097656249999991118
        h = h1;
        h *= d1;
        test(Decimal("4949.90097656249999991118").toHex().getNum(), h.getNum(), 18);
        // 31.41796875 / 157.55 = 0.19941586004443034863
        h = h1;
        h /= d1;
        test(Decimal("0.19941586004443034863").toHex().getNum(), h.getNum(), 19);
        // 31.41796875 % 157.55 = 31.41796875
        h = h1;
        h %= d1;
        test(Decimal("31.41796875").toHex().getNum(), h.getNum(), 20);
    }
}

void operator_RelationOverloading() {
    Decimal d("12.75");
    Octal o("175.652");                // 125.83203125
    Hexadecimal h("1FC.ABF");          // 508.671630859375
    Binary b("1100111011.110111101");  // 827.869140625
    std::cout << "\nBinary operator< Tests" << std::endl;
    // 827.869140625 < 827.869140625 = false
    test("0", std::to_string(b < b), 0);
    // 827.869140625 < 125.83203125 = false
    test("0", std::to_string(b < o), 1);
    // 827.869140625 < 12.75 = false
    test("0", std::to_string(b < d), 2);
    // 827.869140625 < 508.671630859375 = false
    test("0", std::to_string(b < h), 3);

    std::cout << "\nOctal operator< Tests" << std::endl;
    // 125.83203125 < 125.83203125 = false
    test("0", std::to_string(o < o), 0);
    // 125.83203125 < 827.869140625 = true
    test("1", std::to_string(o < b), 1);
    // 125.83203125 < 12.75 = false
    test("0", std::to_string(o < d), 2);
    // 125.83203125 < 508.671630859375 = true
    test("1", std::to_string(o < h), 3);

    std::cout << "\nDecimal operator< Tests" << std::endl;
    // 12.75 < 12.75 = false
    test("0", std::to_string(d < d), 0);
    // 12.75 < 827.869140625 = true
    test("1", std::to_string(d < b), 1);
    // 12.75 < 125.83203125 = true
    test("1", std::to_string(d < o), 2);
    // 12.75 < 508.671630859375 = true
    test("1", std::to_string(d < h), 3);

    std::cout << "\nHexadecimal operator< Tests" << std::endl;
    // 508.671630859375 < 508.671630859375 = false
    test("0", std::to_string(h < h), 0);
    // 508.671630859375 < 827.869140625 = true
    test("1", std::to_string(h < b), 1);
    // 508.671630859375 < 125.83203125 = false
    test("0", std::to_string(h < o), 2);
    // 508.671630859375 < 12.75 = false
    test("0", std::to_string(h < d), 3);

    std::cout << "\nBinary operator<= Tests" << std::endl;
    // 827.869140625 <= 827.869140625 = true
    test("1", std::to_string(b <= b), 0);
    // 827.869140625 <= 125.83203125 = false
    test("0", std::to_string(b <= o), 1);
    // 827.869140625 <= 12.75 = false
    test("0", std::to_string(b <= d), 2);
    // 827.869140625 <= 508.671630859375 = false
    test("0", std::to_string(b <= h), 3);

    std::cout << "\nOctal operator<= Tests" << std::endl;
    // 125.83203125 <= 125.83203125 = true
    test("1", std::to_string(o <= o), 0);
    // 125.83203125 <= 827.869140625 = true
    test("1", std::to_string(o <= b), 1);
    // 125.83203125 <= 12.75 = false
    test("0", std::to_string(o <= d), 2);
    // 125.83203125 <= 508.671630859375 = true
    test("1", std::to_string(o <= h), 3);

    std::cout << "\nDecimal operator<= Tests" << std::endl;
    // 12.75 <= 12.75 = true
    test("1", std::to_string(d <= d), 0);
    // 12.75 <= 827.869140625 = true
    test("1", std::to_string(d <= b), 1);
    // 12.75 <= 125.83203125 = true
    test("1", std::to_string(d <= o), 2);
    // 12.75 <= 508.671630859375 = true
    test("1", std::to_string(d <= h), 3);

    std::cout << "\nHexadecimal operator<= Tests" << std::endl;
    // 508.671630859375 <= 508.671630859375 = true
    test("1", std::to_string(h <= h), 0);
    // 508.671630859375 <= 827.869140625 = true
    test("1", std::to_string(h <= b), 1);
    // 508.671630859375 <= 125.83203125 = false
    test("0", std::to_string(h <= o), 2);
    // 508.671630859375 <= 12.75 = false
    test("0", std::to_string(h <= d), 3);

    std::cout << "\nBinary operator> Tests" << std::endl;
    // 827.869140625 > 827.869140625 = false
    test("0", std::to_string(b > b), 0);
    // 827.869140625 > 125.83203125 = true
    test("1", std::to_string(b > o), 1);
    // 827.869140625 > 12.75 = true
    test("1", std::to_string(b > d), 2);
    // 827.869140625 > 508.671630859375 = true
    test("1", std::to_string(b > h), 3);

    std::cout << "\nOctal operator> Tests" << std::endl;
    // 125.83203125 > 125.83203125 = false
    test("0", std::to_string(o > o), 0);
    // 125.83203125 > 827.869140625 = false
    test("0", std::to_string(o > b), 1);
    // 125.83203125 > 12.75 = true
    test("1", std::to_string(o > d), 2);
    // 125.83203125 > 508.671630859375 = false
    test("0", std::to_string(o > h), 3);

    std::cout << "\nDecimal operator> Tests" << std::endl;
    // 12.75 > 12.75 = false
    test("0", std::to_string(d > d), 0);
    // 12.75 > 827.869140625 = false
    test("0", std::to_string(d > b), 1);
    // 12.75 > 125.83203125 = false
    test("0", std::to_string(d > o), 2);
    // 12.75 > 508.671630859375 = false
    test("0", std::to_string(d > h), 3);

    std::cout << "\nHexadecimal operator> Tests" << std::endl;
    // 508.671630859375 > 508.671630859375 = false
    test("0", std::to_string(h > h), 0);
    // 508.671630859375 > 827.869140625 = false
    test("0", std::to_string(h > b), 1);
    // 508.671630859375 > 125.83203125 = true
    test("1", std::to_string(h > o), 2);
    // 508.671630859375 > 12.75 = true
    test("1", std::to_string(h > d), 3);

    std::cout << "\nBinary operator>= Tests" << std::endl;
    // 827.869140625 >= 827.869140625 = true
    test("1", std::to_string(b >= b), 0);
    // 827.869140625 >= 125.83203125 = true
    test("1", std::to_string(b >= o), 1);
    // 827.869140625 >= 12.75 = true
    test("1", std::to_string(b >= d), 2);
    // 827.869140625 >= 508.671630859375 = true
    test("1", std::to_string(b >= h), 3);

    std::cout << "\nOctal operator>= Tests" << std::endl;
    // 125.83203125 >= 125.83203125 = true
    test("1", std::to_string(o >= o), 0);
    // 125.83203125 >= 827.869140625 = false
    test("0", std::to_string(o >= b), 1);
    // 125.83203125 >= 12.75 = true
    test("1", std::to_string(o >= d), 2);
    // 125.83203125 >= 508.671630859375 = false
    test("0", std::to_string(o >= h), 3);

    std::cout << "\nDecimal operator>= Tests" << std::endl;
    // 12.75 >= 12.75 = true
    test("1", std::to_string(d >= d), 0);
    // 12.75 >= 827.869140625 = false
    test("0", std::to_string(d >= b), 1);
    // 12.75 >= 125.83203125 = false
    test("0", std::to_string(d >= o), 2);
    // 12.75 >= 508.671630859375 = false
    test("0", std::to_string(d >= h), 3);

    std::cout << "\nHexadecimal operator>= Tests" << std::endl;
    // 508.671630859375 >= 508.671630859375 = true
    test("1", std::to_string(h >= h), 0);
    // 508.671630859375 >= 827.869140625 = false
    test("0", std::to_string(h >= b), 1);
    // 508.671630859375 >= 125.83203125 = true
    test("1", std::to_string(h >= o), 2);
    // 508.671630859375 >= 12.75 = true
    test("1", std::to_string(h >= d), 3);

    std::cout << "\nBinary operator== Tests" << std::endl;
    // 827.869140625 == 827.869140625 = true
    test("1", std::to_string(b == b), 0);
    // 827.869140625 == 125.83203125 = false
    test("0", std::to_string(b == o), 1);
    // 827.869140625 == 12.75 = false
    test("0", std::to_string(b == d), 2);
    // 827.869140625 == 508.671630859375 = false
    test("0", std::to_string(b == h), 3);

    std::cout << "\nOctal operator== Tests" << std::endl;
    // 125.83203125 == 125.83203125 = true
    test("1", std::to_string(o == o), 0);
    // 125.83203125 == 827.869140625 = false
    test("0", std::to_string(o == b), 1);
    // 125.83203125 == 12.75 = false
    test("0", std::to_string(o == d), 2);
    // 125.83203125 == 508.671630859375 = false
    test("0", std::to_string(o == h), 3);

    std::cout << "\nDecimal operator== Tests" << std::endl;
    // 12.75 == 12.75 = true
    test("1", std::to_string(d == d), 0);
    // 12.75 == 827.869140625 = false
    test("0", std::to_string(d == b), 1);
    // 12.75 == 125.83203125 = false
    test("0", std::to_string(d == o), 2);
    // 12.75 == 508.671630859375 = false
    test("0", std::to_string(d == h), 3);

    std::cout << "\nHexadecimal operator== Tests" << std::endl;
    // 508.671630859375 == 508.671630859375 = true
    test("1", std::to_string(h == h), 0);
    // 508.671630859375 == 827.869140625 = false
    test("0", std::to_string(h == b), 1);
    // 508.671630859375 == 125.83203125 = false
    test("0", std::to_string(h == o), 2);
    // 508.671630859375 == 12.75 = false
    test("0", std::to_string(h == d), 3);
}