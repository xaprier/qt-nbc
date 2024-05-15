#include "test.hpp"

void sub_bin_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_bin_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_bin_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_bin_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void sub_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void sub_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void sub_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void sub_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void subtraction_tests() {
    return;
    Tester tester;
    // Adding test functions
    tester.addTest("Subtraction Binary to Binary", sub_bin_bin);
    tester.addTest("Subtraction Binary to Octal", sub_bin_oct);
    tester.addTest("Subtraction Binary to Decimal", sub_bin_dec);
    tester.addTest("Subtraction Binary to Hexadecimal", sub_bin_hex);

    tester.addTest("Subtraction Octal to Binary", sub_oct_bin);
    tester.addTest("Subtraction Octal to Octal", sub_oct_oct);
    tester.addTest("Subtraction Octal to Decimal", sub_oct_dec);
    tester.addTest("Subtraction Octal to Hexadecimal", sub_oct_hex);

    tester.addTest("Subtraction Decimal to Binary", sub_dec_bin);
    tester.addTest("Subtraction Decimal to Octal", sub_dec_oct);
    tester.addTest("Subtraction Decimal to Decimal", sub_dec_dec);
    tester.addTest("Subtraction Decimal to Hexadecimal", sub_dec_hex);

    tester.addTest("Subtraction Hexadecimal to Binary", sub_hex_bin);
    tester.addTest("Subtraction Hexadecimal to Octal", sub_hex_oct);
    tester.addTest("Subtraction Hexadecimal to Decimal", sub_hex_dec);
    tester.addTest("Subtraction Hexadecimal to Hexadecimal", sub_hex_hex);
}
