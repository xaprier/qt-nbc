#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void rem_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_remainder + "b" + b1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_bin_oct() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
}
void rem_bin_dec() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
}
void rem_bin_hex() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
}

void rem_oct_bin() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_remainder + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_oct_oct() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_remainder + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_oct_dec() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_remainder + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
}
void rem_oct_hex() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_remainder + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
}

void rem_dec_bin() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_dec_oct() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_dec_dec() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_dec_hex() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_remainder + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}

void rem_hex_bin() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_hex_oct() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_hex_dec() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}
void rem_hex_hex() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_remainder + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_remainder + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder1);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_remainder + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_remainder2);
        tester.addTestCase(expected, output);
    }
}

void remainder_tests() {
    Tester tester;
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
