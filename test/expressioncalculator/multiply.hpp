#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void mul_bin_bin() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_multiply + "b" + b1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_bin_oct() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "0o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_bin_dec() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_bin_hex() {
    Tester tester;
    {
        Tokenizer lexer("b" + b1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0b" + b2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}

void mul_oct_bin() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_multiply + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_oct_oct() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_multiply + "o" + o1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_oct_dec() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_multiply + "0d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_oct_hex() {
    Tester tester;
    {
        Tokenizer lexer("o" + o1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_multiply + "0x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0o" + o2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}

void mul_dec_bin() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_dec_oct() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_dec_dec() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_dec_hex() {
    Tester tester;
    {
        Tokenizer lexer("d" + d1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0d" + d1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_multiply + "d" + d1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}

void mul_hex_bin() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "0b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "b" + b2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("b" + b2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_hex_oct() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "0o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "o" + o2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("o" + o2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_hex_dec() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "0d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "d" + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("d" + d2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}
void mul_hex_hex() {
    Tester tester;
    {
        Tokenizer lexer("x" + x1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x1 + op_multiply + "0x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("0x" + x1 + op_multiply + "x" + x2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer("x" + x2 + op_multiply + "x" + x1);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_multiply);
        tester.addTestCase(expected, output);
    }
}

void multiply_tests() {
    Tester tester;
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
