#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void sub_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_subtraction + "b" + b1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_bin_oct() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_bin_dec() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_bin_hex() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
}

void sub_oct_bin() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_subtraction + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_oct_oct() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_subtraction + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_oct_dec() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_subtraction + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_oct_hex() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_subtraction + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
}

void sub_dec_bin() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_dec_oct() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_dec_dec() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_dec_hex() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_subtraction + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}

void sub_hex_bin() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_hex_oct() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_hex_dec() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}
void sub_hex_hex() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_subtraction + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_subtraction + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_subtraction + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(-res_subtraction);
        tester.addTestCase(expected, output);
    }
}

void subtraction_tests() {
    Tester tester;
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
