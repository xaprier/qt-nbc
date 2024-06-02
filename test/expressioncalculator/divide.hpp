#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void div_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_division + "b" + b1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_bin_oct() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
}
void div_bin_dec() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
}
void div_bin_hex() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
}

void div_oct_bin() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_division + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_oct_oct() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_division + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_oct_dec() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_division + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
}
void div_oct_hex() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_division + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
}

void div_dec_bin() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_dec_oct() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_dec_dec() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_dec_hex() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_division + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}

void div_hex_bin() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_hex_oct() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_hex_dec() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}
void div_hex_hex() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_division + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_division + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_division);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_division + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(1 / res_division);
        tester.addTestCase(expected, output);
    }
}

void division_tests() {
    Tester tester;
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
