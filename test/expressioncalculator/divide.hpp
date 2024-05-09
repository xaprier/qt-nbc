#include "test.hpp"

void div_bin_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_bin_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_bin_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_bin_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void div_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void div_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void div_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void div_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void division_tests() {
    Tester tester;
    // Adding test functions
    tester.addTest("Division Binary to Binary", div_bin_bin);
    tester.addTest("Division Binary to Octal", div_bin_oct);
    tester.addTest("Division Binary to Decimal", div_bin_dec);
    tester.addTest("Division Binary to Hexadecimal", div_bin_hex);

    tester.addTest("Division Octal to Binary", div_oct_bin);
    tester.addTest("Division Octal to Octal", div_oct_oct);
    tester.addTest("Division Octal to Decimal", div_oct_dec);
    tester.addTest("Division Octal to Hexadecimal", div_oct_hex);

    tester.addTest("Division Decimal to Binary", div_dec_bin);
    tester.addTest("Division Decimal to Octal", div_dec_oct);
    tester.addTest("Division Decimal to Decimal", div_dec_dec);
    tester.addTest("Division Decimal to Hexadecimal", div_dec_hex);

    tester.addTest("Division Hexadecimal to Binary", div_hex_bin);
    tester.addTest("Division Hexadecimal to Octal", div_hex_oct);
    tester.addTest("Division Hexadecimal to Decimal", div_hex_dec);
    tester.addTest("Division Hexadecimal to Hexadecimal", div_hex_hex);
}
