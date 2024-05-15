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
const std::string x1 = "1D.2";
const std::string x2 = "3.5";
const double res_addition = 32.4375;

void add_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + " + b" + b1);
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
        Tokenizer lexer("b" + b1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + 0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + b" + b2);
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
        Tokenizer lexer("b" + b1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + 0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + b" + b2);
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
    {
        Tokenizer lexer("0o" + o1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + " + o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_oct_oct() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + " + o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_oct_dec() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + " + 0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_oct_hex() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + " + 0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}

void add_dec_bin() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_dec_oct() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_dec_dec() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_dec_hex() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + " + d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}

void add_hex_bin() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + 0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_hex_oct() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + 0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_hex_dec() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + 0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
}
void add_hex_hex() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + " + 0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + " + x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + " + x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
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