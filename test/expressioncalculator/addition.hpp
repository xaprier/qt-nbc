#include <string>

#include "astnode.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void add_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b11101.001 + b11.0101");  // 29.125 + 3.3125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        auto res = parser.getPostfix();
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(32.4375);
        tester.addTestCase(expected, output, 1);
    }
}
void add_bin_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_bin_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_bin_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void add_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void add_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void add_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}
void add_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1", 1);
}

void addition_tests() {
    Tester tester;
    // Adding test functions
    tester.addTest("Addition Binary to Binary", add_bin_bin);
    tester.addTest("Addition Binary to Octal", add_bin_oct);
    tester.addTest("Addition Binary to Decimal", add_bin_dec);
    tester.addTest("Addition Binary to Hexadecimal", add_bin_hex);

    tester.addTest("Addition Octal to Binary", add_oct_bin);
    tester.addTest("Addition Octal to Octal", add_oct_oct);
    tester.addTest("Addition Octal to Decimal", add_oct_dec);
    tester.addTest("Addition Octal to Hexadecimal", add_oct_hex);

    tester.addTest("Addition Decimal to Binary", add_dec_bin);
    tester.addTest("Addition Decimal to Octal", add_dec_oct);
    tester.addTest("Addition Decimal to Decimal", add_dec_dec);
    tester.addTest("Addition Decimal to Hexadecimal", add_dec_hex);

    tester.addTest("Addition Hexadecimal to Binary", add_hex_bin);
    tester.addTest("Addition Hexadecimal to Octal", add_hex_oct);
    tester.addTest("Addition Hexadecimal to Decimal", add_hex_dec);
    tester.addTest("Addition Hexadecimal to Hexadecimal", add_hex_hex);
}