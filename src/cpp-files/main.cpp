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
    test(Decimal("-1324.59062500000004547474").toBin().getNum(), res1.getNum(), 0);
    // 1100111011.110111101 / -0.5 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Octal("-0000.50000");
    test(Decimal("-1324.59062500000004547474").toBin().getNum(), res1.getNum(), 1);
    // 1100111011.110111101 / -0.625 = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Decimal("-0000.625000");
    test(Decimal("-1324.59062500000004547474").toBin().getNum(), res1.getNum(), 2);
    // 1100111011.110111101 / -0.A = -10100101100.100101110011001100110011001100110011001101
    res1 = b / Hexadecimal("-000.A000");
    test(Decimal("-1324.59062500000004547474").toBin().getNum(), res1.getNum(), 3);

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
    Binary b1("1001.1001");  // 9.5625
    Octal o1("13.54");
    Decimal d1("157.55");
    Hexadecimal h1("1F.6C");

	std::cout << "\nBinary Assignment Tests" << std::endl;
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
    testConstructors();
    testConverters();
    ostreamOverloadTest();
    operator_plusOverloading();
    operator_subtractOverloading();
    operator_multiplyOverloading();
    operator_divideOverloading();
    operator_remainderOverloading();
    operator_assignmentsOverloading();

    return 0;
}
