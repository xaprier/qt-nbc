#include <string>

#include "astnode.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

const std::string b1 = "11101.001";
const std::string b2 = "11.0101";
const std::string o1 = "35.1";
const std::string o2 = "3.24";
const std::string d1 = "29.125";
const std::string d2 = "3.3125";
const std::string h1 = "1D.2";
const std::string h2 = "3.5";
const double res_addition = 32.4375;

void add_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + " + b" + b2);  // 29.125 + 3.3125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + " + 0b" + b2);  // 29.125 + 3.3125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0b" + b2);  // 29.125 + 3.3125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + " + b" + b2);  // 29.125 + 3.3125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + " + b" + b1);  // 3.3125 + 29.125 = 32.4375
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_bin_oct() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + 0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_bin_dec() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + " + x" + h2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + 0x" + h1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0x" + h2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + x" + h1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + h1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_bin_hex() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + " + x" + h2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + 0x" + h1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0x" + h2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + x" + h1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + h1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}

void add_oct_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_oct_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_oct_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_oct_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void add_dec_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_dec_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_dec_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_dec_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void add_hex_bin() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_hex_oct() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_hex_dec() {
    Tester tester;
    tester.addTestCase("1", "1");
}
void add_hex_hex() {
    Tester tester;
    tester.addTestCase("1", "1");
}

void addition_tests() {
    Tester tester;
    // Adding test functions
    tester.addTest("Addition Binary to Binary", add_bin_bin);
    tester.addTest("Addition Binary to Octal", add_bin_oct);
    tester.addTest("Addition Binary to Decimal", add_bin_dec);
    tester.addTest("Addition Binary to Hexadecimal", add_bin_hex);
    return;

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