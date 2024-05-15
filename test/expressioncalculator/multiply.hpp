#include "test.hpp"

void mul_bin_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_bin_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_bin_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_bin_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void mul_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void mul_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void mul_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void mul_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void multiply_tests() {
    return;
    Tester tester;
    // Adding test functions
    tester.addTest("Multiply Binary to Binary", mul_bin_bin);
    tester.addTest("Multiply Binary to Octal", mul_bin_oct);
    tester.addTest("Multiply Binary to Decimal", mul_bin_dec);
    tester.addTest("Multiply Binary to Hexadecimal", mul_bin_hex);

    tester.addTest("Multiply Octal to Binary", mul_oct_bin);
    tester.addTest("Multiply Octal to Octal", mul_oct_oct);
    tester.addTest("Multiply Octal to Decimal", mul_oct_dec);
    tester.addTest("Multiply Octal to Hexadecimal", mul_oct_hex);

    tester.addTest("Multiply Decimal to Binary", mul_dec_bin);
    tester.addTest("Multiply Decimal to Octal", mul_dec_oct);
    tester.addTest("Multiply Decimal to Decimal", mul_dec_dec);
    tester.addTest("Multiply Decimal to Hexadecimal", mul_dec_hex);

    tester.addTest("Multiply Hexadecimal to Binary", mul_hex_bin);
    tester.addTest("Multiply Hexadecimal to Octal", mul_hex_oct);
    tester.addTest("Multiply Hexadecimal to Decimal", mul_hex_dec);
    tester.addTest("Multiply Hexadecimal to Hexadecimal", mul_hex_hex);
}
