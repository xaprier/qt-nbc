#include "test.hpp"

void rem_bin_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_bin_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_bin_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_bin_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void rem_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void rem_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void rem_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void rem_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void remainder_tests() {
    Tester tester;
    // Adding test functions
    tester.addTest("Remainder Binary to Binary", rem_bin_bin);
    tester.addTest("Remainder Binary to Octal", rem_bin_oct);
    tester.addTest("Remainder Binary to Decimal", rem_bin_dec);
    tester.addTest("Remainder Binary to Hexadecimal", rem_bin_hex);

    tester.addTest("Remainder Octal to Binary", rem_oct_bin);
    tester.addTest("Remainder Octal to Octal", rem_oct_oct);
    tester.addTest("Remainder Octal to Decimal", rem_oct_dec);
    tester.addTest("Remainder Octal to Hexadecimal", rem_oct_hex);

    tester.addTest("Remainder Decimal to Binary", rem_dec_bin);
    tester.addTest("Remainder Decimal to Octal", rem_dec_oct);
    tester.addTest("Remainder Decimal to Decimal", rem_dec_dec);
    tester.addTest("Remainder Decimal to Hexadecimal", rem_dec_hex);

    tester.addTest("Remainder Hexadecimal to Binary", rem_hex_bin);
    tester.addTest("Remainder Hexadecimal to Octal", rem_hex_oct);
    tester.addTest("Remainder Hexadecimal to Decimal", rem_hex_dec);
    tester.addTest("Remainder Hexadecimal to Hexadecimal", rem_hex_hex);
}
