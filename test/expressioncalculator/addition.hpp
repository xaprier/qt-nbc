#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void add_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_addition + "b" + b1);
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
        Tokenizer lexer("b" + b1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_addition + "b" + b2);
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
        Tokenizer lexer("b" + b1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "b" + b2);
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
        Tokenizer lexer("b" + b1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_addition + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "b" + b2);
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
        Tokenizer lexer("o" + o1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_addition + "o" + o1);
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
        Tokenizer lexer("o" + o1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_addition + "o" + o1);
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
        Tokenizer lexer("o" + o1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_addition + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_addition + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "o" + o2);
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
        Tokenizer lexer("o" + o1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_addition + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_addition + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "o" + o2);
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
        Tokenizer lexer("d" + d1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_addition + "d" + d1);
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
        Tokenizer lexer("d" + d1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_addition + "d" + d1);
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
        Tokenizer lexer("d" + d1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_addition + "d" + d1);
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
        Tokenizer lexer("d" + d1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_addition + "d" + d1);
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
        Tokenizer lexer("x" + x1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_addition + "x" + x1);
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
        Tokenizer lexer("x" + x1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_addition + "x" + x1);
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
        Tokenizer lexer("x" + x1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_addition + "x" + x1);
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
        Tokenizer lexer("x" + x1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_addition + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_addition + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_addition + "x" + x1);
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