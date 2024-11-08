//
// Created by xaprier on 2/5/23.
//

//! IMPORTANT NOTE
//! THIS TEST CASES REMAINED FROM NOT REFACTORED OLD CODE BUT IT'S WORKS.
//! IF WE TRY TO REFACTOR IT, IT WILL TAKE TOO LONG.
//! SO, THIS PART OF CODE WILL NOT REFACTORED.

#include "test_cases.hpp"

#include <cassert>

#include "test.hpp"

Decimal d("12.75");
Octal o("175.652");                // 125.83203125
Hexadecimal h("1FC.ABF");          // 508.671630859375
Binary b("1100111011.110111101");  // 827.869140625
NumberBase *n;

// test successful
void testConstructors() {
    Tester t;

    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary(d);
    t.addTestCase(n->getNum(), "1100.11");
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal(d);
    t.addTestCase(n->getNum(), "14.6");
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal(d);
    t.addTestCase(n->getNum(), "12.75");
    // print hexa value of Decimal(12.75) = C.C
    n = new Hexadecimal(d);
    t.addTestCase(n->getNum(), "C.C");

    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary(o);
    t.addTestCase(n->getNum(), "1111101.11010101");
    // print octal value of Octal(175.652) = 175.652
    n = new Octal(o);
    t.addTestCase(n->getNum(), "175.652");
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal(o);
    t.addTestCase(n->getNum(), "125.83203125");
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal(o);
    t.addTestCase(n->getNum(), "7D.D5");

    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary(h);
    t.addTestCase(n->getNum(), "111111100.101010111111");
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal(h);
    t.addTestCase(n->getNum(), "774.5277");
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal(h);
    t.addTestCase(n->getNum(), "508.671630859375");
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal(h);
    t.addTestCase(n->getNum(), "1FC.ABF");

    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary(b);
    t.addTestCase(n->getNum(), "1100111011.110111101");
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal(b);
    t.addTestCase(n->getNum(), "1473.675");
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal(b);
    t.addTestCase(n->getNum(), "827.869140625");
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal(b);
    t.addTestCase(n->getNum(), "33B.DE8");
}

// test successful
void testConverters() {
    Tester t;

    // print binary value of Binary(1100111011.110111101) = 1100111011.110111101
    n = new Binary;
    *n = b.toBin();
    t.addTestCase(n->getNum(), "1100111011.110111101");
    // print octal value of Binary(1100111011.110111101) = 1473.675
    n = new Octal;
    *n = b.toOct();
    t.addTestCase(n->getNum(), "1473.675");
    // print decimal value of Binary(1100111011.110111101) = 827.869140625
    n = new Decimal;
    *n = b.toDec();
    t.addTestCase(n->getNum(), "827.869140625");
    // print hexadecimal value of Binary(1100111011.110111101) = 33B.DE8
    n = new Hexadecimal;
    *n = b.toHex();
    t.addTestCase(n->getNum(), "33B.DE8");

    // print binary value of Decimal(12.75) = 1100.11
    n = new Binary;
    *n = d.toBin();
    t.addTestCase(n->getNum(), "1100.11");
    // print octal value of Decimal(12.75) = 14.6
    n = new Octal;
    *n = d.toOct();
    t.addTestCase(n->getNum(), "14.6");
    // print decimal value of Decimal(12.75) = 12.75
    n = new Decimal;
    *n = d.toDec();
    t.addTestCase(n->getNum(), "12.75");
    // print hexadecimal value of Decimal(12.75) = C.C
    n = new Hexadecimal;
    *n = d.toHex();
    t.addTestCase(n->getNum(), "C.C");

    // print binary value of Octal(175.652) = 1111101.11010101
    n = new Binary;
    *n = o.toBin();
    t.addTestCase(n->getNum(), "1111101.11010101");
    // print octal value of Octal(175.652) = 175.652
    n = new Octal;
    *n = o.toOct();
    t.addTestCase(n->getNum(), "175.652");
    // print decimal value of Octal(175.652) = 125.83203125
    n = new Decimal;
    *n = o.toDec();
    t.addTestCase(n->getNum(), "125.83203125");
    // print hexadecimal value of Octal(175.652) = 7D.D5
    n = new Hexadecimal;
    *n = o.toHex();
    t.addTestCase(n->getNum(), "7D.D5");

    // print binary value of Hexadecimal(1FC.ABF) = 111111100.101010111111
    n = new Binary;
    *n = h.toBin();
    t.addTestCase(n->getNum(), "111111100.101010111111");
    // print octal value of Hexadecimal(1FC.ABF) = 774.5277
    n = new Octal;
    *n = h.toOct();
    t.addTestCase(n->getNum(), "774.5277");
    // print decimal value of Hexadecimal(1FC.ABF) = 508.671630859375
    n = new Decimal;
    *n = h.toDec();
    t.addTestCase(n->getNum(), "508.671630859375");
    // print hexadecimal value of Hexadecimal(1FC.ABF) = 1FC.ABF
    n = new Hexadecimal;
    *n = h.toHex();
    t.addTestCase(n->getNum(), "1FC.ABF");
}

// test successful
void ostreamOverloadTest() {
    Tester t;

    // for testing the number object
    n = new Binary(d);

    t.addTestCase(d.getNum() + "d 0" + o.getNum() + " 0x" + h.getNum() + " " + b.getNum() + "b " + n->getNum(), "12.75d 0175.652 0x1FC.ABF 1100111011.110111101b 1100.11");
}

// test successful
void operator_plusOverloading() {
    Tester t;

    Binary res1;
    // binary + binary = 1655.73828125 = 11001110111.10111101
    res1 = b + b;

    t.addTestCase(Decimal("1655.73828125").toBin().getNum(), res1.getNum());
    // binary + octal = 953.701171875 = 1110111001.101100111
    res1 = b + o;
    t.addTestCase(Decimal("953.701171875").toBin().getNum(), res1.getNum());
    // binary + decimal = 840.619140625 = 1101001000.100111101
    res1 = b + d;
    t.addTestCase(Decimal("840.619140625").toBin().getNum(), res1.getNum());
    // binary + hexadecimal = 1336.540771484375 = 10100111000.100010100111
    res1 = b + h;
    t.addTestCase(Decimal("1336.540771484375").toBin().getNum(), res1.getNum());

    Octal res2;
    // octal + octal = 251.6640625 = 373.524
    res2 = o + o;
    t.addTestCase(Decimal("251.6640625").toOct().getNum(), res2.getNum());
    // octal + binary = 953.701171875 = 1671.547
    res2 = o + b;
    t.addTestCase(Decimal("953.701171875").toOct().getNum(), res2.getNum());
    // octal + decimal = 138.58203125 = 212.452
    res2 = o + d;
    t.addTestCase(Decimal("138.58203125").toOct().getNum(), res2.getNum());
    // octal + hexadecimal = 634.503662109375 = 1172.4017
    res2 = o + h;
    t.addTestCase(Decimal("634.503662109375").toOct().getNum(), res2.getNum());

    // add the control of including . for precision finder
    Decimal res3;
    // decimal + decimal = 25.50
    res3 = d + d;
    t.addTestCase(Decimal("25.5").getNum(), res3.getNum());
    // decimal + binary = 840.619140625
    res3 = d + b;
    t.addTestCase(Decimal("840.619140625").getNum(), res3.getNum());
    // decimal + octal = 138.58203125
    res3 = d + o;
    t.addTestCase(Decimal("138.58203125").getNum(), res3.getNum());
    // decimal + hexadecimal  = 521.421630859375
    res3 = d + h;
    t.addTestCase(Decimal("521.421630859375").getNum(), res3.getNum());

    Hexadecimal res4;
    // hexadecimal + hexadecimal = 1017.34326171875 = 3F9.57E
    res4 = h + h;
    t.addTestCase(Decimal("1017.34326171875").toHex().getNum(), res4.getNum());
    // hexadecimal + binary = 1336.540771484375 = 538.8A7
    res4 = h + b;
    t.addTestCase(Decimal("1336.540771484375").toHex().getNum(), res4.getNum());
    // hexadecimal + octal = 634.503662109375 = 27A.80F
    res4 = h + o;
    t.addTestCase(Decimal("634.503662109375").toHex().getNum(), res4.getNum());
    // hexadecimal + decimal = 521.421630859375 = 209.6BF
    res4 = h + d;
    t.addTestCase(Decimal("521.421630859375").toHex().getNum(), res4.getNum());
}

// test successful
void operator_subtractOverloading() {
    Tester t;

    Binary res;
    // binary - binary - binary = -827.869140625 = -1100111011.110111101
    res = b - b - b;
    t.addTestCase(Decimal("-827.869140625").toBin().getNum(), res.getNum());
    // binary - octal = 702.037109375 = 1010111110.000010011
    res = b - o;
    t.addTestCase(Decimal("702.037109375").toBin().getNum(), res.getNum());
    // binary - decimal = 815.119140625 = 1100101111.000111101
    res = b - d;
    t.addTestCase(Decimal("815.119140625").toBin().getNum(), res.getNum());
    // binary - hexadecimal = 319.197509765625 = 100111111.001100101001
    res = b - h;
    t.addTestCase(Decimal("319.197509765625").toBin().getNum(), res.getNum());

    Octal res2;
    // octal - octal - octal = -125.83203125 = -175.652
    res2 = o - o - o;
    t.addTestCase(Decimal("-125.83203125").toOct().getNum(), res2.getNum());
    // octal - binary = -702.037109375 = -1276.023
    res2 = o - b;
    t.addTestCase(Decimal("-702.037109375").toOct().getNum(), res2.getNum());
    // octal - decimal = 113.08203125 = 161.052
    res2 = o - d;
    t.addTestCase(Decimal("113.08203125").toOct().getNum(), res2.getNum());
    // octal - hexadecimal = -382.839599609375 = -576.6557
    res2 = o - h;
    t.addTestCase(Decimal("-382.839599609375").toOct().getNum(), res2.getNum());

    Decimal res3;
    // decimal - decimal - decimal = -12.75
    res3 = d - d - d;
    t.addTestCase(Decimal("-12.75").getNum(), res3.getNum());
    // decimal - binary = -815.119140625
    res3 = d - b;
    t.addTestCase(Decimal("-815.119140625").getNum(), res3.getNum());
    // decimal - octal = -113.08203125
    res3 = d - o;
    t.addTestCase(Decimal("-113.08203125").getNum(), res3.getNum());
    // decimal - hexadecimal = -495.921630859375
    res3 = d - h;
    t.addTestCase(Decimal("-495.921630859375").getNum(), res3.getNum());

    Hexadecimal res4;
    // hexadecimal - hexadecimal - hexadecimal = -508.671630859375 = -1FC.ABF
    res4 = h - h - h;
    t.addTestCase(Decimal("-508.671630859375").toHex().getNum(), res4.getNum());
    // hexadecimal - binary = -319.197509765625 = -13F.329
    res4 = h - b;
    t.addTestCase(Decimal("-319.197509765625").toHex().getNum(), res4.getNum());
    // hexadecimal - octal = 382.839599609375 = 17E.D6F
    res4 = h - o;
    t.addTestCase(Decimal("382.839599609375").toHex().getNum(), res4.getNum());
    // hexadecimal - decimal = 495.921630859375 = 1EF.EBF
    res4 = h - d;
    t.addTestCase(Decimal("495.921630859375").toHex().getNum(), res4.getNum());
}

void operator_multiplyOverloading() {
    Tester t;

    Binary res1;
    // 1100111011.110111101 * -111111100.101010111111 = -1100110110011111001.100010111100000000011
    res1 = b * Binary("-111111100.101010111111");
    t.addTestCase(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 * -774.5277 = -1100110110011111001.100010111100000000011
    res1 = b * Octal("-774.5277");
    t.addTestCase(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 * -508.671630859375 = -1100110110011111001.100010111100000000011
    res1 = b * Decimal("-508.671630859375");
    t.addTestCase(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 * -1FC.ABF = -1100110110011111001.100010111100000000011
    res1 = b * Hexadecimal("-1FC.ABF");
    t.addTestCase(Decimal("-421113.54589986801147460938").toBin().getNum(), res1.getNum());

    Octal res2;
    // 175.652 * -774.5277 = -175007.1363726
    res2 = o * Octal("-774.5277");
    t.addTestCase(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum());
    // 175.652 * -111111100.101010111111 = -175007.1363726
    res2 = o * Binary("-111111100.101010111111");
    t.addTestCase(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum());
    // 175.652 * -508.671630859375 = -175007.1363726
    res2 = o * Decimal("-508.671630859375");
    t.addTestCase(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum());
    // 175.652 * -1FC.ABF = -175007.1363726
    res2 = o * Hexadecimal("-1FC.ABF");
    t.addTestCase(Decimal("-64007.18455028533935546875").toOct().getNum(), res2.getNum());

    Decimal res3;
    // 12.75 * -508.671630859375 = -6485.56329345703125
    res3 = d * Decimal("-508.671630859375");
    t.addTestCase(Decimal("-6485.56329345703125").getNum(), res3.getNum());
    // 12.75 * -111111100.101010111111 = -6485.56329345703125
    res3 = d * Binary("-111111100.101010111111");
    t.addTestCase(Decimal("-6485.56329345703125").getNum(), res3.getNum());
    // 12.75 * -774.5277 = -6485.56329345703125
    res3 = d * Octal("-774.5277");
    t.addTestCase(Decimal("-6485.56329345703125").getNum(), res3.getNum());
    // 12.75 * -1FC.ABF = -6485.56329345703125
    res3 = d * Hexadecimal("-1FC.ABF");
    t.addTestCase(Decimal("-6485.56329345703125").getNum(), res3.getNum());

    Hexadecimal res4;
    // 1FC.ABF * -1FC.ABF = -3F2BA.D3FA81
    res4 = h * Hexadecimal("-1FC.ABF");
    t.addTestCase(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum());
    // 1FC.ABF * -111111100.101010111111 = -3F2BA.D3FA81
    res4 = h * Binary("-111111100.101010111111");
    t.addTestCase(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum());
    // 1FC.ABF * -774.5277 = -3F2BA.D3FA81
    res4 = h * Octal("-774.5277");
    t.addTestCase(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum());
    // 1FC.ABF * -508.671630859375 = -3F2BA.D3FA81
    res4 = h * Decimal("-508.671630859375");
    t.addTestCase(Decimal("-258746.82804113626480102539").toHex().getNum(), res4.getNum());
}

void operator_divideOverloading() {
    Tester t;

    Binary res1;
    // 1100111011.110111101 / -0.101 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Binary("-0000.101");
    t.addTestCase(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 / -0.5 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Octal("-0000.50000");
    t.addTestCase(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 / -0.625 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Decimal("-0000.625000");
    t.addTestCase(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum());
    // 1100111011.110111101 / -0.A = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Hexadecimal("-000.A000");
    t.addTestCase(Decimal("-1324.59062499999999995559").toBin().getNum(), res1.getNum());

    Octal res2;
    // 175.652 / -0.5 = -201.33125
    res2 = o / Octal("-0000.50000");
    t.addTestCase(Decimal("-201.33125").toOct().getNum(), res2.getNum());
    // 175.652 / -0.101 = -201.33125d
    res2 = o / Binary("-0000.101");
    t.addTestCase(Decimal("-201.33125").toOct().getNum(), res2.getNum());
    // 175.652 / -0.625 = -201.33125d
    res2 = o / Decimal("-0000.625000");
    t.addTestCase(Decimal("-201.33125").toOct().getNum(), res2.getNum());
    // 175.652 / -0.A = -201.33125d
    res2 = o / Hexadecimal("-000.A000");
    t.addTestCase(Decimal("-201.33125").toOct().getNum(), res2.getNum());

    Decimal res3;
    // 12.75 / -0.625 = -20.4
    res3 = d / Decimal("-0000.625000");
    t.addTestCase(Decimal("-20.4").getNum(), res3.getNum());
    // 12.75 / -0.001 = -20.4
    res3 = d / Binary("-0000000.101");
    t.addTestCase(Decimal("-20.4").getNum(), res3.getNum());
    // 12.75 / -0.5 = -20.4
    res3 = d / Octal("-0000.50000");
    t.addTestCase(Decimal("-20.4").getNum(), res3.getNum());
    // 12.75 / -0.A = -20.4
    res3 = d / Hexadecimal("-000.A000");
    t.addTestCase(Decimal("-20.4").getNum(), res3.getNum());

    Hexadecimal res4;
    // 1FC.ABF / -0.A = -32D.DFE66666666
    res4 = h / Hexadecimal("-000.A000");
    t.addTestCase(Decimal("-813.874609375").toHex().getNum(), res4.getNum());
    // 1FC.ABF / -0.625 = -32D.DFE66666666
    res4 = h / Decimal("-0000.625000");
    t.addTestCase(Decimal("-813.874609375").toHex().getNum(), res4.getNum());
    // 1FC.ABF / -0.001 = -32D.DFE66666666
    res4 = h / Binary("-000000.101");
    t.addTestCase(Decimal("-813.874609375").toHex().getNum(), res4.getNum());
    // 1FC.ABF / -0.5 = -32D.DFE66666666
    res4 = h / Octal("-0000.50000");
    t.addTestCase(Decimal("-813.874609375").toHex().getNum(), res4.getNum());
}

void operator_remainderOverloading() {
    Tester t;

    Decimal d1("4.75");
    Binary b1("100.11");
    Octal o1("4.6");
    Hexadecimal h1("4.C");

    Binary res1;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % b1;
    t.addTestCase(Decimal("1.369140625").toBin().getNum(), res1.getNum());
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % o1;
    t.addTestCase(Decimal("1.369140625").toBin().getNum(), res1.getNum());
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % d1;
    t.addTestCase(Decimal("1.369140625").toBin().getNum(), res1.getNum());
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % h1;
    t.addTestCase(Decimal("1.369140625").toBin().getNum(), res1.getNum());

    Octal res2;
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % o1;
    t.addTestCase(Decimal("2.33203125").toOct().getNum(), res2.getNum());
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % b1;
    t.addTestCase(Decimal("2.33203125").toOct().getNum(), res2.getNum());
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % d1;
    t.addTestCase(Decimal("2.33203125").toOct().getNum(), res2.getNum());
    // 125.83203125 % 4.75 = 2.33203125 = 02.252
    res2 = o % h1;
    t.addTestCase(Decimal("2.33203125").toOct().getNum(), res2.getNum());

    Decimal res3;
    // 12.75 % 4.75 = 3.25
    res3 = d % d1;
    t.addTestCase(Decimal("3.25").getNum(), res3.getNum());
    // 12.75 % 4.75 = 3.25
    res3 = d % b1;
    t.addTestCase(Decimal("3.25").getNum(), res3.getNum());
    // 12.75 % 4.75 = 3.25
    res3 = d % o1;
    t.addTestCase(Decimal("3.25").getNum(), res3.getNum());
    // 12.75 % 4.75 = 3.25
    res3 = d % h1;
    t.addTestCase(Decimal("3.25").getNum(), res3.getNum());

    Hexadecimal res4;
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % h1;
    t.addTestCase(Decimal("0.421630859375").toHex().getNum(), res4.getNum());
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % b1;
    t.addTestCase(Decimal("0.421630859375").toHex().getNum(), res4.getNum());
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % o1;
    t.addTestCase(Decimal("0.421630859375").toHex().getNum(), res4.getNum());
    // 508.671630859375 % 4.75 = 0.421630859375 = 0x0.6BF
    res4 = h % d1;
    t.addTestCase(Decimal("0.421630859375").toHex().getNum(), res4.getNum());
}

void operator_assignmentsOverloading() {
    Tester t;

    Binary b1("1001.1001");   // 9.5625
    Octal o1("13.54");        // 11.6875
    Decimal d1("157.55");     // 157.55
    Hexadecimal h1("1F.6C");  // 31.421875
    // Binary
    {
        // 9.5625
        b = b1;
        t.addTestCase(b1.getNum(), b.getNum());
        // 9.5625 + 9.5625 = 19.125
        b += b1;
        t.addTestCase(Decimal("19.125").toBin().getNum(), b.getNum());
        // 19.125 + 11.6875 = 30.8125
        b += o1;
        t.addTestCase(Decimal("30.8125").toBin().getNum(), b.getNum());
        // 30.8125 + 157.55 = 188.3625
        b += d1;
        t.addTestCase(Decimal("188.3625").toBin().getNum(), b.getNum());
        // 188.3625 + 31.421875 = 219.784375
        b += h1;
        t.addTestCase(Decimal("219.784375").toBin().getNum(), b.getNum());
        // 219.784375 - 9.5625 = 210.221875
        b -= b1;
        t.addTestCase(Decimal("210.221875").toBin().getNum(), b.getNum());
        // 210.221875 - 11.6875 = 198.534375
        b -= o1;
        t.addTestCase(Decimal("198.534375").toBin().getNum(), b.getNum());
        // 198.534375 - 157.55 = 40.984375
        b -= d1;
        t.addTestCase(Decimal("40.984375").toBin().getNum(), b.getNum());
        // 40.984375 - 31.421875 = 9.5625
        b -= h1;
        t.addTestCase(Decimal("9.5625").toBin().getNum(), b.getNum());

        // 9.5625 * 9.5625 = 91.44140625 = 1011011.01110001b
        b *= b1;
        t.addTestCase(Decimal("91.44140625").toBin().getNum(), b.getNum());
        // 91.44140625 * 11.6875 = 1068.721435546875
        b *= o1;
        t.addTestCase(Decimal("1068.721435546875").toBin().getNum(), b.getNum());
        // 1068.721435546875 * 157.55 = 168377.06217041015625
        b *= d1;
        t.addTestCase(Decimal("168377.06217041015625").toBin().getNum(), b.getNum());
        // 168377.06217041015625 * 31.421875 = 5290723.000385856
        b *= h1;
        t.addTestCase(Decimal("5290723.00038585662841796875").toBin().getNum(), b.getNum());

        // 5290723.00038585662841796875 / 9.5625
        b /= b1;
        t.addTestCase("NaN", b.getNum());
        // 9.5625 / 11.6875 = 0.8181818181818181
        b = b1;
        b /= o1;
        t.addTestCase(Decimal("0.81").toBin().getNum(), b.getNum());
        b = d1.toBin();
        b /= d1;
        t.addTestCase("1.0", b.getNum());
        b = Decimal("827.869140625").toBin();
        b /= h1;
        t.addTestCase(Decimal("26.3469045251118846096005654544569551944732666015625").toBin().getNum(), b.getNum());

        // 9.5625 % 3.25 = 3.0625
        b = b1;
        b1 = Binary("11.01");
        b %= b1;
        t.addTestCase(Decimal("3.0625").toBin().getNum(), b.getNum());
        // 3.0625 % 3.0625 = 0.0
        o1 = Octal("3.04");
        b %= o1;
        t.addTestCase("0.0", b.getNum());
        // 3.25 % 3 = 0.25
        b = b1;  // 11.01 = 3.25
        b %= Decimal("3");
        t.addTestCase(Decimal("0.25").toBin().getNum(), b.getNum());
        // 0.25 % 10.6875 = 0.25
        b %= Hexadecimal("A.B");
        t.addTestCase(Decimal("0.25").toBin().getNum(), b.getNum());
    }
    // Octal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        // 11.6875
        o = o1;
        t.addTestCase(o1.getNum(), o.getNum());
        // 11.6875 + 11.6875 = 23.375
        o = o1;
        o += o1;
        t.addTestCase(Decimal("23.375").toOct().getNum(), o.getNum());
        // 11.6875 + 9.5625 = 21.25
        o = o1;
        o += b1;
        t.addTestCase(Decimal("21.25").toOct().getNum(), o.getNum());
        // 11.6875 + 157.55 = 169.2375
        o = o1;
        o += d1;
        t.addTestCase(Decimal("169.2375").toOct().getNum(), o.getNum());
        // 11.6875 + 31.41796875 = 43.10546875
        o = o1;
        o += h1;
        t.addTestCase(Decimal("43.10546875").toOct().getNum(), o.getNum());

        // 11.6875 - 11.6875 = 0.0
        o = o1;
        o -= o1;
        t.addTestCase(Decimal("0.0").toOct().getNum(), o.getNum());
        // 11.6875 - 9.5625 = 2.125
        o = o1;
        o -= b1;
        t.addTestCase(Decimal("2.125").toOct().getNum(), o.getNum());
        // 11.6875 - 157.55 = -145.8625
        o = o1;
        o -= d1;
        t.addTestCase(Decimal("-145.8625").toOct().getNum(), o.getNum());
        // 11.6875 - 31.41796875 = -19.73046875
        o = o1;
        o -= h1;
        t.addTestCase(Decimal("-19.73046875").toOct().getNum(), o.getNum());

        // 11.6875 * 11.6875 = 136.59765625
        o = o1;
        o *= o1;
        t.addTestCase(Decimal("136.59765625").toOct().getNum(), o.getNum());
        // 11.6875 * 9.5625 = 111.76171875
        o = o1;
        o *= b1;
        t.addTestCase(Decimal("111.76171875").toOct().getNum(), o.getNum());
        // 11.6875 * 157.55 = 1841.365625
        o = o1;
        o *= d1;
        t.addTestCase(Decimal("1841.365625").toOct().getNum(), o.getNum());
        // 11.6875 * 31.41796875 = 367.197509765625
        o = o1;
        o *= h1;
        t.addTestCase(Decimal("367.197509765625").toOct().getNum(), o.getNum());

        // 11.6875 / 11.6875 = 1.0
        o = o1;
        o /= o1;
        t.addTestCase(Decimal("1.0").toOct().getNum(), o.getNum());
        // 11.6875 / 9.5625 = 1.2
        o = o1;
        o /= b1;
        t.addTestCase(Decimal("1.2").toOct().getNum(), o.getNum());
        // 11.6875 / 157.55 = 0.07418279911139321
        o = o1;
        o /= d1;
        t.addTestCase(Decimal("0.07418279911139321").toOct().getNum(), o.getNum());
        // 11.6875 / 31.41796875 = 0.3720004973268681
        o = o1;
        o /= h1;
        t.addTestCase(Decimal("0.3720004973268681").toOct().getNum(), o.getNum());

        // 11.6875 % 11.6875 = 0.0
        o = o1;
        o %= o1;
        t.addTestCase(Decimal("0.0").toOct().getNum(), o.getNum());
        // 11.6875 % 9.5625 = 2.125
        o = o1;
        o %= b1;
        t.addTestCase(Decimal("2.125").toOct().getNum(), o.getNum());
        // 11.6875 % 157.55 = 11.6875
        o = o1;
        o %= d1;
        t.addTestCase(Decimal("11.6875").toOct().getNum(), o.getNum());
        // 11.6875 % 31.41796875 = 11.6875
        o = o1;
        o %= h1;
        t.addTestCase(Decimal("11.6875").toOct().getNum(), o.getNum());
    }
    // Decimal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        // 157.55
        d = d1;
        t.addTestCase(d1.getNum(), d.getNum());
        // 157.55 + 157.55 = 315.1
        d += d;
        t.addTestCase(Decimal("315.1").getNum(), d.getNum());
        // 315.1 - 157.55 = 157.55
        d -= d1;
        t.addTestCase(Decimal("157.55").getNum(), d.getNum());
        // 157.55 * 2 = 315.1
        d *= Decimal("2");
        t.addTestCase(Decimal("315.1").getNum(), d.getNum());
        // 315.1 / 2 = 157.55
        d /= Decimal("2");
        t.addTestCase(Decimal("157.55").getNum(), d.getNum());
        // 157.55 - 157.55 = 0.0
        d -= d1;
        t.addTestCase(Decimal("0.0").getNum(), d.getNum());

        // 157.55 + 9.5625 = 167.1125
        d = d1;
        d += b1;
        t.addTestCase(Decimal("167.1125").getNum(), d.getNum());
        // 157.55 - 9.5625 = 147.9875
        d = d1;
        d -= b1;
        t.addTestCase(Decimal("147.9875").getNum(), d.getNum());
        // 157.55 * 9.5625 = 1506.571875
        d = d1;
        d *= b1;
        t.addTestCase(Decimal("1506.571875").getNum(), d.getNum());
        // 157.55 / 9.5625 = 16.47581699346405228
        d = d1;
        d /= b1;
        t.addTestCase(Decimal("16.47581699346405228").getNum(), d.getNum());
        // 157.55 % 9.5625 = 4.550000000000011368683772161603
        d = d1;
        d %= b1;
        t.addTestCase(Decimal("4.550000000000011368683772161603").getNum(), d.getNum());

        // 157.55 + 11.6875 = 169.2375
        d = d1;
        d += o1;
        t.addTestCase(Decimal("169.2375").getNum(), d.getNum());
        // 157.55 - 11.6875 = 145.8625
        d = d1;
        d -= o1;
        t.addTestCase(Decimal("145.8625").getNum(), d.getNum());
        // 157.55 * 11.6875 = 1841.365625
        d = d1;
        d *= o1;
        t.addTestCase(Decimal("1841.365625").getNum(), d.getNum());
        // 157.55 / 11.6875 = 13.4802139037433155
        d = d1;
        d /= o1;
        t.addTestCase(Decimal("13.4802139037433155").getNum(), d.getNum());
        // 157.55 % 11.6875 = 5.612500000000011368683772161603
        d = d1;
        d %= o1;
        t.addTestCase(Decimal("5.612500000000011368683772161603").getNum(), d.getNum());

        // 157.55 + 31.41796875 = 188.96796875
        d = d1;
        d += h1;
        t.addTestCase(Decimal("188.96796875").getNum(), d.getNum());
        // 157.55 - 31.41796875 = 126.13203125
        d = d1;
        d -= h1;
        t.addTestCase(Decimal("126.13203125").getNum(), d.getNum());
        // 157.55 * 31.41796875 = 4949.9009765625
        d = d1;
        d *= h1;
        t.addTestCase(Decimal("4949.9009765625").getNum(), d.getNum());
        // 157.55 / 31.41796875 = 5.0146462762650752206887977122964068133780927514608976749968917070744746984955862240457540718637324381449707820465000621658585105060300882755190849185627253512371005843590699987566828297898793982344896183016287454929752579883128186000248663434042024120353102076339674250901404948402337436279995026731319159517592937958473206514981971901031953251274400099465373616809648141240830535869700360561979360934974511998010692527663807037175183389282605992788760412781300509760039786149446723859256496332214347880144224791744373989804799204277011065522814870073355713042397115504165112520203904015914459778689543702598532885739152057689916697749595921919681710804426209125948029342285216958846201666045008081561606365783911475817481039413154295660823075966679099838368767872684321770483650379211736914086783538480666418003232624642546313564590326992415765261718264329230386671639935347507149073728708193460151684694765634713415392266567201293049857018525425836130796966306104687305731692154668655974139002859629491483277384060673877906253885366156906626880517219942807410170334452318786522441874922292676861867462389655601143851796593310953624269551162501554
        d = d1;
        d /= h1;
        t.addTestCase(Decimal("5.0146462762650752206887977122964068133780927514608976749968917070744746984955862240457540718637324381449707820465000621658585105060300882755190849185627253512371005843590699987566828297898793982344896183016287454929752579883128186000248663434042024120353102076339674250901404948402337436279995026731319159517592937958473206514981971901031953251274400099465373616809648141240830535869700360561979360934974511998010692527663807037175183389282605992788760412781300509760039786149446723859256496332214347880144224791744373989804799204277011065522814870073355713042397115504165112520203904015914459778689543702598532885739152057689916697749595921919681710804426209125948029342285216958846201666045008081561606365783911475817481039413154295660823075966679099838368767872684321770483650379211736914086783538480666418003232624642546313564590326992415765261718264329230386671639935347507149073728708193460151684694765634713415392266567201293049857018525425836130796966306104687305731692154668655974139002859629491483277384060673877906253885366156906626880517219942807410170334452318786522441874922292676861867462389655601143851796593310953624269551162501554").getNum(), d.getNum());
        // 157.55 % 31.41796875 = 0.460156250000011368683772161603
        d = d1;
        d %= h1;
        t.addTestCase(Decimal("0.460156250000011368683772161603").getNum(), d.getNum());
    }
    // Hexadecimal
    {
        b1 = Binary("1001.1001");   // 9.5625
        o1 = Octal("13.54");        // 11.6875
        d1 = Decimal("157.55");     // 157.55
        h1 = Hexadecimal("1F.6B");  // 31.41796875
        // 31.41796875
        h = h1;
        t.addTestCase(h1.getNum(), h.getNum());
        // 31.41796875 + 31.41796875 = 62.8359375
        h = h1;
        h += h1;
        t.addTestCase(Decimal("62.8359375").toHex().getNum(), h.getNum());
        // 31.41796875 - 31.41796875 = 0
        h = h1;
        h -= h1;
        t.addTestCase(Hexadecimal("0").getNum(), h.getNum());
        // 31.41796875 * 31.41796875 = 987.0887603759766
        h = h1;
        h *= h1;
        t.addTestCase(Decimal("987.0887603759765625").toHex().getNum(), h.getNum());
        // 31.41796875 / 31.41796875 = 1
        h = h1;
        h /= h1;
        t.addTestCase(Hexadecimal("1").getNum(), h.getNum());
        // 31.41796875 % 31.41796875 = 0
        h = h1;
        h %= h1;
        t.addTestCase(Hexadecimal("0").getNum(), h.getNum());
        // 31.41796875 + 9.5625 = 40.98046875
        h = h1;
        h += b1;
        t.addTestCase(Decimal("40.98046875").toHex().getNum(), h.getNum());
        // 31.41796875 - 9.5625 = 21.85546875
        h = h1;
        h -= b1;
        t.addTestCase(Decimal("21.85546875").toHex().getNum(), h.getNum());
        // 31.41796875 * 9.5625 = 300.434326171875
        h = h1;
        h *= b1;
        t.addTestCase(Decimal("300.434326171875").toHex().getNum(), h.getNum());
        // 31.41796875 / 9.5625 = 3.28553921568627449457
        h = h1;
        h /= b1;
        t.addTestCase(Decimal("3.28553921568627449457").toHex().getNum(), h.getNum());
        // 31.41796875 % 9.5625 = 2.73046875
        h = h1;
        h %= b1;
        t.addTestCase(Decimal("2.73046875").toHex().getNum(), h.getNum());

        // 31.41796875 + 11.6875 = 43.10546875
        h = h1;
        h += o1;
        t.addTestCase(Decimal("43.10546875").toHex().getNum(), h.getNum());
        // 31.41796875 - 11.6875 = 19.73046875
        h = h1;
        h -= o1;
        t.addTestCase(Decimal("19.73046875").toHex().getNum(), h.getNum());
        // 31.41796875 * 11.6875 = 367.197509765625
        h = h1;
        h *= o1;
        t.addTestCase(Decimal("367.197509765625").toHex().getNum(), h.getNum());
        // 31.41796875 / 11.6875 = 2.68816844919786090973
        h = h1;
        h /= o1;
        t.addTestCase(Decimal("2.68816844919786090973").toHex().getNum(), h.getNum());
        // 31.41796875 % 11.6875 = 8.04296875
        h = h1;
        h %= o1;
        t.addTestCase(Decimal("8.04296875").toHex().getNum(), h.getNum());

        // 31.41796875 + 157.55 = 188.96796875
        h = h1;
        h += d1;
        t.addTestCase(Decimal("188.96796875").toHex().getNum(), h.getNum());
        // 31.41796875 - 157.55 = -126.13203125000000001665
        h = h1;
        h -= d1;
        t.addTestCase(Decimal("-126.13203125000000001665").toHex().getNum(), h.getNum());
        // 31.41796875 * 157.55 = 4949.90097656249999991118
        h = h1;
        h *= d1;
        t.addTestCase(Decimal("4949.90097656249999991118").toHex().getNum(), h.getNum());
        // 31.41796875 / 157.55 = 0.19941586004443034863
        h = h1;
        h /= d1;
        t.addTestCase(Decimal("0.19941586004443034863").toHex().getNum(), h.getNum());
        // 31.41796875 % 157.55 = 31.41796875
        h = h1;
        h %= d1;
        t.addTestCase(Decimal("31.41796875").toHex().getNum(), h.getNum());
    }
}

void operator_RelationOverloading() {
    Tester t;

    Decimal d("12.75");
    Octal o("175.652");                // 125.83203125
    Hexadecimal h("1FC.ABF");          // 508.671630859375
    Binary b("1100111011.110111101");  // 827.869140625

    // 827.869140625 < 827.869140625 = false
    t.addTestCase("0", std::to_string(b < b));
    // 827.869140625 < 125.83203125 = false
    t.addTestCase("0", std::to_string(b < o));
    // 827.869140625 < 12.75 = false
    t.addTestCase("0", std::to_string(b < d));
    // 827.869140625 < 508.671630859375 = false
    t.addTestCase("0", std::to_string(b < h));

    // 125.83203125 < 125.83203125 = false
    t.addTestCase("0", std::to_string(o < o));
    // 125.83203125 < 827.869140625 = true
    t.addTestCase("1", std::to_string(o < b));
    // 125.83203125 < 12.75 = false
    t.addTestCase("0", std::to_string(o < d));
    // 125.83203125 < 508.671630859375 = true
    t.addTestCase("1", std::to_string(o < h));

    // 12.75 < 12.75 = false
    t.addTestCase("0", std::to_string(d < d));
    // 12.75 < 827.869140625 = true
    t.addTestCase("1", std::to_string(d < b));
    // 12.75 < 125.83203125 = true
    t.addTestCase("1", std::to_string(d < o));
    // 12.75 < 508.671630859375 = true
    t.addTestCase("1", std::to_string(d < h));

    // 508.671630859375 < 508.671630859375 = false
    t.addTestCase("0", std::to_string(h < h));
    // 508.671630859375 < 827.869140625 = true
    t.addTestCase("1", std::to_string(h < b));
    // 508.671630859375 < 125.83203125 = false
    t.addTestCase("0", std::to_string(h < o));
    // 508.671630859375 < 12.75 = false
    t.addTestCase("0", std::to_string(h < d));

    // 827.869140625 <= 827.869140625 = true
    t.addTestCase("1", std::to_string(b <= b));
    // 827.869140625 <= 125.83203125 = false
    t.addTestCase("0", std::to_string(b <= o));
    // 827.869140625 <= 12.75 = false
    t.addTestCase("0", std::to_string(b <= d));
    // 827.869140625 <= 508.671630859375 = false
    t.addTestCase("0", std::to_string(b <= h));

    // 125.83203125 <= 125.83203125 = true
    t.addTestCase("1", std::to_string(o <= o));
    // 125.83203125 <= 827.869140625 = true
    t.addTestCase("1", std::to_string(o <= b));
    // 125.83203125 <= 12.75 = false
    t.addTestCase("0", std::to_string(o <= d));
    // 125.83203125 <= 508.671630859375 = true
    t.addTestCase("1", std::to_string(o <= h));

    // 12.75 <= 12.75 = true
    t.addTestCase("1", std::to_string(d <= d));
    // 12.75 <= 827.869140625 = true
    t.addTestCase("1", std::to_string(d <= b));
    // 12.75 <= 125.83203125 = true
    t.addTestCase("1", std::to_string(d <= o));
    // 12.75 <= 508.671630859375 = true
    t.addTestCase("1", std::to_string(d <= h));

    // 508.671630859375 <= 508.671630859375 = true
    t.addTestCase("1", std::to_string(h <= h));
    // 508.671630859375 <= 827.869140625 = true
    t.addTestCase("1", std::to_string(h <= b));
    // 508.671630859375 <= 125.83203125 = false
    t.addTestCase("0", std::to_string(h <= o));
    // 508.671630859375 <= 12.75 = false
    t.addTestCase("0", std::to_string(h <= d));

    // 827.869140625 > 827.869140625 = false
    t.addTestCase("0", std::to_string(b > b));
    // 827.869140625 > 125.83203125 = true
    t.addTestCase("1", std::to_string(b > o));
    // 827.869140625 > 12.75 = true
    t.addTestCase("1", std::to_string(b > d));
    // 827.869140625 > 508.671630859375 = true
    t.addTestCase("1", std::to_string(b > h));

    // 125.83203125 > 125.83203125 = false
    t.addTestCase("0", std::to_string(o > o));
    // 125.83203125 > 827.869140625 = false
    t.addTestCase("0", std::to_string(o > b));
    // 125.83203125 > 12.75 = true
    t.addTestCase("1", std::to_string(o > d));
    // 125.83203125 > 508.671630859375 = false
    t.addTestCase("0", std::to_string(o > h));

    // 12.75 > 12.75 = false
    t.addTestCase("0", std::to_string(d > d));
    // 12.75 > 827.869140625 = false
    t.addTestCase("0", std::to_string(d > b));
    // 12.75 > 125.83203125 = false
    t.addTestCase("0", std::to_string(d > o));
    // 12.75 > 508.671630859375 = false
    t.addTestCase("0", std::to_string(d > h));

    // 508.671630859375 > 508.671630859375 = false
    t.addTestCase("0", std::to_string(h > h));
    // 508.671630859375 > 827.869140625 = false
    t.addTestCase("0", std::to_string(h > b));
    // 508.671630859375 > 125.83203125 = true
    t.addTestCase("1", std::to_string(h > o));
    // 508.671630859375 > 12.75 = true
    t.addTestCase("1", std::to_string(h > d));

    // 827.869140625 >= 827.869140625 = true
    t.addTestCase("1", std::to_string(b >= b));
    // 827.869140625 >= 125.83203125 = true
    t.addTestCase("1", std::to_string(b >= o));
    // 827.869140625 >= 12.75 = true
    t.addTestCase("1", std::to_string(b >= d));
    // 827.869140625 >= 508.671630859375 = true
    t.addTestCase("1", std::to_string(b >= h));

    // 125.83203125 >= 125.83203125 = true
    t.addTestCase("1", std::to_string(o >= o));
    // 125.83203125 >= 827.869140625 = false
    t.addTestCase("0", std::to_string(o >= b));
    // 125.83203125 >= 12.75 = true
    t.addTestCase("1", std::to_string(o >= d));
    // 125.83203125 >= 508.671630859375 = false
    t.addTestCase("0", std::to_string(o >= h));

    // 12.75 >= 12.75 = true
    t.addTestCase("1", std::to_string(d >= d));
    // 12.75 >= 827.869140625 = false
    t.addTestCase("0", std::to_string(d >= b));
    // 12.75 >= 125.83203125 = false
    t.addTestCase("0", std::to_string(d >= o));
    // 12.75 >= 508.671630859375 = false
    t.addTestCase("0", std::to_string(d >= h));

    // 508.671630859375 >= 508.671630859375 = true
    t.addTestCase("1", std::to_string(h >= h));
    // 508.671630859375 >= 827.869140625 = false
    t.addTestCase("0", std::to_string(h >= b));
    // 508.671630859375 >= 125.83203125 = true
    t.addTestCase("1", std::to_string(h >= o));
    // 508.671630859375 >= 12.75 = true
    t.addTestCase("1", std::to_string(h >= d));

    // 827.869140625 == 827.869140625 = true
    t.addTestCase("1", std::to_string(b == b));
    // 827.869140625 == 125.83203125 = false
    t.addTestCase("0", std::to_string(b == o));
    // 827.869140625 == 12.75 = false
    t.addTestCase("0", std::to_string(b == d));
    // 827.869140625 == 508.671630859375 = false
    t.addTestCase("0", std::to_string(b == h));

    // 125.83203125 == 125.83203125 = true
    t.addTestCase("1", std::to_string(o == o));
    // 125.83203125 == 827.869140625 = false
    t.addTestCase("0", std::to_string(o == b));
    // 125.83203125 == 12.75 = false
    t.addTestCase("0", std::to_string(o == d));
    // 125.83203125 == 508.671630859375 = false
    t.addTestCase("0", std::to_string(o == h));

    // 12.75 == 12.75 = true
    t.addTestCase("1", std::to_string(d == d));
    // 12.75 == 827.869140625 = false
    t.addTestCase("0", std::to_string(d == b));
    // 12.75 == 125.83203125 = false
    t.addTestCase("0", std::to_string(d == o));
    // 12.75 == 508.671630859375 = false
    t.addTestCase("0", std::to_string(d == h));

    // 508.671630859375 == 508.671630859375 = true
    t.addTestCase("1", std::to_string(h == h));
    // 508.671630859375 == 827.869140625 = false
    t.addTestCase("0", std::to_string(h == b));
    // 508.671630859375 == 125.83203125 = false
    t.addTestCase("0", std::to_string(h == o));
    // 508.671630859375 == 12.75 = false
    t.addTestCase("0", std::to_string(h == d));
}