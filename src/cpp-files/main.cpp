#include <cassert>
#include <cmath>
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

void test(const std::string &expected, const std::string &output, int test_case) {
	if (expected == output) {
		std::cout << "Test " << test_case << " is successful!" << std::endl;
	} else {
		std::cerr << "Test " << test_case << " is unsuccessful!!" << std::endl;
		std::cout << "Expected : " << expected << "\n" << "Output : " << output << std::endl;
		assert(expected == output);
	}
}

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
    // 1100111011.110111101 * -111111100.101010111111 = -1100110110011111001.100010111100000000011
    res1 = b * Binary("-111111100.101010111111");  // confirmed
    std::cout << b << " * " << Binary("-111111100.101010111111") << " = " << res1 << std::endl;
    // 1100111011.110111101 * -774.5277 = -1100110110011111001.100010111100000000011
    res1 = b * Octal("-774.5277");  // confirmed
    std::cout << b << " * " << Octal("-774.5277") << " = " << res1 << std::endl;
    // 1100111011.110111101 * -508.671630859375 = -1100110110011111001.100010111100000000011
    res1 = b * Decimal("-508.671630859375");  // confirmed
    std::cout << b << " * " << Decimal("-508.671630859375") << " = " << res1 << std::endl;
    // 1100111011.110111101 * -1FC.ABF = -1100110110011111001.100010111100000000011
    res1 = b * Hexadecimal("-1FC.ABF");  // confirmed
    std::cout << b << " * " << Hexadecimal("-1FC.ABF") << " = " << res1 << std::endl;

    Octal res2;
    // 175.652 * -774.5277 = -175007.1363726
    res2 = o * Octal("-774.5277");  // confirmed
    std::cout << o << " * " << Octal("-774.5277") << " = " << res2 << std::endl;
    // 175.652 * -111111100.101010111111 = -175007.1363726
    res2 = o * Binary("-111111100.101010111111");  // confirmed
    std::cout << o << " * " << Binary("-111111100.101010111111") << " = " << res2 << std::endl;
    // 175.652 * -508.671630859375 = -175007.1363726
    res2 = o * Decimal("-508.671630859375");  // confirmed
    std::cout << o << " * " << Decimal("-508.671630859375") << " = " << res2 << std::endl;
    // 175.652 * -1FC.ABF = -175007.1363726
    res2 = o * Hexadecimal("-1FC.ABF");  // confirmed
    std::cout << o << " * " << Hexadecimal("-1FC.ABF") << " = " << res2 << std::endl;

    Decimal res3;
    // 12.75 * -508.671630859375 = -6485.56329345703125
    res3 = d * Decimal("-508.671630859375");  // confirmed
    std::cout << d << " * " << Decimal("-508.671630859375") << " = " << res3 << std::endl;
    // 12.75 * -111111100.101010111111 = -6485.56329345703125
    res3 = d * Binary("-111111100.101010111111");  // confirmed
    std::cout << d << " * " << Binary("-111111100.101010111111") << " = " << res3 << std::endl;
    // 12.75 * -774.5277 = -6485.56329345703125
    res3 = d * Octal("-774.5277");  // confirmed
    std::cout << d << " * " << Octal("-774.5277") << " = " << res3 << std::endl;
    // 12.75 * -1FC.ABF = -6485.56329345703125
    res3 = d * Hexadecimal("-1FC.ABF");  // confirmed
    std::cout << d << " * " << Hexadecimal("-1FC.ABF") << " = " << res3 << std::endl;

    Hexadecimal res4;
    // 1FC.ABF * -1FC.ABF = -3F2BA.D3FA81
    res4 = h * Hexadecimal("-1FC.ABF");  // confirmed
    std::cout << h << " * " << Hexadecimal("-1FC.ABF") << " = " << res4 << std::endl;
    // 1FC.ABF * -111111100.101010111111 = -3F2BA.D3FA81
    res4 = h * Binary("-111111100.101010111111");  // confirmed
    std::cout << h << " * " << Binary("-111111100.101010111111") << " = " << res4 << std::endl;
    // 1FC.ABF * -774.5277 = -3F2BA.D3FA81
    res4 = h * Octal("-774.5277");  // confirmed
    std::cout << h << " * " << Octal("-774.5277") << " = " << res4 << std::endl;
    // 1FC.ABF * -508.671630859375 = -3F2BA.D3FA81
    res4 = h * Decimal("-508.671630859375");  // confirmed
    std::cout << h << " * " << Decimal("-508.671630859375") << " = " << res4 << std::endl;
}

void operator_divideOverloading() {
    Binary res1;
    // 1100111011.110111101 / -0.101 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Binary("-0000.101");  // confirmed
    std::cout << b << " / " << Binary("-0000.101") << " = " << res1 << std::endl;
    // 1100111011.110111101 / -0.5 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Octal("-0000.50000");  // confirmed
    std::cout << b << " / " << Octal("-0000.50000") << " = " << res1 << std::endl;
    // 1100111011.110111101 / -0.625 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Decimal("-0000.625000");  // confirmed
    std::cout << b << " / " << Decimal("-0000.625000") << " = " << res1 << std::endl;
    // 1100111011.110111101 / -0.A = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Hexadecimal("-000.A000");  // confirmed
    std::cout << b << " / " << Hexadecimal("-000.A000") << " = " << res1 << std::endl;

    Octal res2;
    // 175.652 / -0.5 = -311.251463146314632
    res2 = o / Octal("-0000.50000");  // confirmed
    std::cout << o << " / " << Octal("-0000.50000") << " = " << res2 << std::endl;
    // 175.652 / -0.101 = -311.251463146314632
    res2 = o / Binary("-0000.101");  // confirmed
    std::cout << o << " / " << Binary("-0000.101") << " = " << res2 << std::endl;
    // 175.652 / -0.625 = -311.251463146314632
    res2 = o / Decimal("-0000.625000");  // confirmed
    std::cout << o << " / " << Decimal("-0000.625000") << " = " << res2 << std::endl;
    // 175.652 / -0.A = -311.251463146314632
    res2 = o / Hexadecimal("-000.A000");  // confirmed
    std::cout << o << " / " << Hexadecimal("-000.A000") << " = " << res2 << std::endl;

    Decimal res3;
    // 12.75 / -0.625 = -20.399999999999999999653055304805
    res3 = d / Decimal("-0000.625000");  // confirmed
    std::cout << d << " / " << Decimal("-0000.625000") << " = " << res3 << std::endl;
    // 12.75 / -0.001 = -102.0
    res3 = d / Binary("-0000000.101");  // confirmed
    std::cout << d << " / " << Binary("-0000000.101") << " = " << res3 << std::endl;
    // 12.75 / -0.5 = -20.399999999999999999653055304805
    res3 = d / Octal("-0000.50000");  // confirmed
    std::cout << d << " / " << Octal("-0000.50000") << " = " << res3 << std::endl;
    // 12.75 / -0.A = -20.399999999999999999653055304805
    res3 = d / Hexadecimal("-000.A000");  // confirmed
    std::cout << d << " / " << Hexadecimal("-000.A000") << " = " << res3 << std::endl;

    Hexadecimal res4;
    // 1FC.ABF / -0.A = -32D.DFE66666666
    res4 = h / Hexadecimal("-000.A000");  // confirmed
    std::cout << h << " / " << Hexadecimal("-000.A000") << " = " << res4 << std::endl;
    // 1FC.ABF / -0.625 = -32D.DFE66666666
    res4 = h / Decimal("-0000.625000");  // confirmed
    std::cout << h << " / " << Decimal("-0000.625000") << " = " << res4 << std::endl;
    // 1FC.ABF / -0.001 = -FE5.5F8
    res4 = h / Binary("-000000.101");  // confirmed
    std::cout << h << " / " << Binary("-0000000.101") << " = " << res4 << std::endl;
    // 1FC.ABF / -0.5 = -32D.DFE66666666
    res4 = h / Octal("-0000.50000");  // confirmed
    std::cout << h << " / " << Octal("-0000.50000") << " = " << res4 << std::endl;
}

void operator_remainderOverloading() {
    Decimal d1("4.75");
    Binary b1("100.11");
    Octal o1("4.6");
    Hexadecimal h1("4.C");

    Binary res1;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % b1;  // confirmed
    std::cout << b << " % " << b1 << " = " << res1 << std::endl;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % o1;  // confirmed
    std::cout << b << " % " << o1 << " = " << res1 << std::endl;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % d1;  // confirmed
    std::cout << b << " % " << d1 << " = " << res1 << std::endl;
    // 827.869140625 % 4.75 = 1.369140625 = 1.010111101
    res1 = b % h1;  // confirmed
    std::cout << b << " % " << h1 << " = " << res1 << std::endl;

    Octal res2;
    // 125.83203125 % 4.75 = 2.33203125 = 2.252
    res2 = o % o1;  // confirmed
    std::cout << o << " % " << o1 << " = " << res2 << std::endl;
    // 125.83203125 % 4.75 = 2.33203125 = 2.252
    res2 = o % b1;  // confirmed
    std::cout << o << " % " << b1 << " = " << res2 << std::endl;
    // 125.83203125 % 4.75 = 2.33203125 = 2.252
    res2 = o % d1;  // confirmed
    std::cout << o << " % " << d1 << " = " << res2 << std::endl;
    // 125.83203125 % 4.75 = 2.33203125 = 2.252
    res2 = o % h1;  // confirmed
    std::cout << o << " % " << h1 << " = " << res2 << std::endl;

    Decimal res3;
    // 12.75 % 4.75 = 3.25
    res3 = d % d1;  // confirmed
    std::cout << d << " % " << d1 << " = " << res3 << std::endl;
    // 12.75 % 4.75 = 3.25
    res3 = d % b1;  // confirmed
    std::cout << d << " % " << b1 << " = " << res3 << std::endl;
    // 12.75 % 4.75 = 3.25
    res3 = d % o1;  // confirmed
    std::cout << d << " % " << o1 << " = " << res3 << std::endl;
    // 12.75 % 4.75 = 3.25
    res3 = d % h1;  // confirmed
    std::cout << d << " % " << h1 << " = " << res3 << std::endl;

    Hexadecimal res4;
    // 508.671630859375 % 4.75 = 3.25 = 0.6BF
    res4 = h % h1;  // confirmed
    std::cout << d << " % " << d1 << " = " << res4 << std::endl;
    // 508.671630859375 % 4.75 = 3.25 = 0.6BF
    res4 = h % b1;  // confirmed
    std::cout << d << " % " << b1 << " = " << res4 << std::endl;
    // 508.671630859375 % 4.75 = 3.25 = 0.6BF
    res4 = h % o1;  // confirmed
    std::cout << d << " % " << o1 << " = " << res4 << std::endl;
    // 508.671630859375 % 4.75 = 3.25 = 0.6BF
    res4 = h % d1;  // confirmed
    std::cout << d << " % " << h1 << " = " << res4 << std::endl;
}

void operator_assignmentsOverloading() {
    Binary b1("1001.1001");  // 9.5625
    Octal o1("13.54");
    Decimal d1("157.55");
    Hexadecimal h1("1F.6C");

	std::cout << "Binary Assignment Tests" << std::endl;
    // 1001.1001
    b = b1;
	test(b1.getNum(), b.getNum(), 0);
    // 1001.1001 + 1001.1001 = 19.125 = 10011.001b
    b += b1;
	test(Decimal("19.125").toBin().getNum(), b.getNum(), 1);
    // 10011.001 - 1001.1001 = 9.5625 = 1001.1001b
    b -= b1;
	test(Decimal("9.5625").toBin().getNum(), b.getNum(), 2);
    // 1001.1001 * 1001.1001 = 91.44140625 = 1011011.01110001b
    b *= b1;
	test(Decimal("91.44140625").toBin().getNum(), b.getNum(), 3);
    // 1011011.01110001 / 1101101010.011010001001 = 0.10457516339869281 = 0.00011010110001010111000000011010110001010111000000011011b
    b /= b1 * b1 * b1;
	test(Decimal("0.10457516339869281").toBin().getNum(), b.getNum(), 4);
    // 1001.1001 % 11.01 = 3.0625 = 11.0001b
    b = b1;
    b1 = Binary("11.01");
    b %= b1;
	test(Decimal("3.0625").toBin().getNum(), b.getNum(), 5);

	std::cout << std::endl << "Octal Assignment Tests" << std::endl;
	// 013.54
	o = o1;
	test(o1.getNum(), o.getNum(), 0);
	// 013.54 + 013.54 = 23.375d
	o += o;
	test(Decimal("23.375").toOct().getNum(), o.getNum(), 1);
	// 027.3 - 013.54 = 11.6875d
	o -= o1;
	test(Decimal("11.6875").toOct().getNum(), o.getNum(), 2);
	// 013.54 * 013.54 = 136.59765625d
	o *= o;
	test(Decimal("136.59765625").toOct().getNum(), o.getNum(), 3);
	// 0210.462 / 013.54 = 11.6875d
	o /= o1;
	test(Decimal("11.6875").toOct().getNum(), o.getNum(), 4);
	// 013.54 % 07.6 = 4.3125
	o %= Octal("7.6");
	test(Decimal("3.9375").toOct().getNum(), o.getNum(), 5);

	std::cout << std::endl << "Decimal Assignment Tests" << std::endl;
    // 157.55
    d = d1;
	test(d1.getNum(), d.getNum(), 0);
    // 157.55 + 157.55 = 315.10
    d += d;
	test(Decimal("315.10").getNum(), d.getNum(), 1);
    // 315.10 - 157.55 = 157.55
    d -= d1;
	test(Decimal("157.55").getNum(), d.getNum(), 2);
    // 157.55 * 157.55 = 24822.0025
    d *= d;
	test(Decimal("24822.0025").getNum(), d.getNum(), 3);
    // 24822.0025 / 157.55 = 157.55
    d /= d1;
	test(Decimal("157.55").getNum(), d.getNum(), 4);
	// 157.55 % 157.55 = 0
	d %= d1;
	test(Decimal("0").getNum(), d.getNum(), 5);

	std::cout << std::endl << "Hexadecimal Assignment Tests" << std::endl;
	// 1F.6C
	h = h1;
	test(h1.getNum(), h.getNum(), 0);
	// 1F.6C + 1F.6C = 62.84375d
	h += h;
	test(Decimal("62.84375").toHex().getNum(), h.getNum(), 1);
	// 62.84375d + 31.412875d = 94.265625d
	h -= h1 * Hexadecimal("-1");
	test(Decimal("94.265625").toHex().getNum(), h.getNum(), 2);
	// 94.265625d * -0.5d = -47.1328125d
	h *= Decimal("-0.5").toHex();
	test(Decimal("-47.1328125").toHex().getNum(), h.getNum(), 3);
	// -47.1328125d / -8.75d = 5.386607142857143d
	h /= Decimal("-8.75").toHex();
	test(Decimal("5.386607142857143").toHex().getNum(), h.getNum(), 4);
	// 5.386607142857143 % 0.386607142857143
	h %= Decimal("0.386607142857143").toHex();
	test(Decimal("0.36071428571428393").toHex().getNum(), h.getNum(), 5);
}

int main() {
//     testConstructors();
//     testConverters();
    // ostreamOverloadTest();
    // operator_plusOverloading();
    // operator_subtractOverloading();
    // operator_multiplyOverloading();
    // operator_divideOverloading();
    // operator_remainderOverloading();
    operator_assignmentsOverloading();
    // setting locale for qapplication changes(. might be , in region)
    return 0;
}
