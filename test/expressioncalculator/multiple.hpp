#include "astnode.hpp"
#include "numbers.hpp"
#include "parser.hpp"
#include "test.hpp"
#include "tokenizer.hpp"

void me_addition() {
    Tester tester;
    {
        Tokenizer lexer(d1 + op_addition + d1 + op_multiply + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_addition_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_addition + d1 + op_division + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_addition_divide);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_addition + d1 + op_remainder + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_addition_remainder);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_addition + d1 + op_subtraction + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_addition_subtraction);
        tester.addTestCase(expected, output);
    }
}

void me_subtraction() {
    Tester tester;
    {
        Tokenizer lexer(d1 + op_subtraction + d1 + op_multiply + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_subtraction_multiply);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_subtraction + d1 + op_division + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_subtraction_divide);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_subtraction + d1 + op_remainder + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_subtraction_remainder);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_subtraction + d1 + op_addition + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_subtraction_addition);
        tester.addTestCase(expected, output);
    }
}

void me_multiply() {
    Tester tester;
    {
        Tokenizer lexer(d1 + op_multiply + d1 + op_addition + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_multiply_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_multiply + d1 + op_subtraction + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_multiply_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_multiply + d1 + op_remainder + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_multiply_remainder);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_multiply + d1 + op_division + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_multiply_divide);
        tester.addTestCase(expected, output);
    }
}

void me_divide() {
    Tester tester;
    {
        Tokenizer lexer(d1 + op_division + d1 + op_addition + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_divide_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_division + d1 + op_subtraction + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_divide_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_division + d1 + op_remainder + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_divide_remainder);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_division + d1 + op_multiply + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_divide_multiply);
        tester.addTestCase(expected, output);
    }
}

void me_remainder() {
    Tester tester;
    {
        Tokenizer lexer(d1 + op_remainder + d1 + op_addition + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_remainder_addition);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_remainder + d1 + op_subtraction + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_remainder_subtraction);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_remainder + d1 + op_division + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_remainder_divide);
        tester.addTestCase(expected, output);
    }
    {
        Tokenizer lexer(d1 + op_remainder + d1 + op_multiply + d2);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        auto output = std::to_string(tree.evaluate());
        auto expected = std::to_string(res_me_remainder_multiply);
        tester.addTestCase(expected, output);
    }
}

void multiple_expression_tests() {
    Tester tester;
    tester.addTest("Multiple Expression Addition", me_addition);
    tester.addTest("Multiple Expression Subtraction", me_subtraction);
    tester.addTest("Multiple Expression Multiply", me_multiply);
    tester.addTest("Multiple Expression Division", me_divide);
    tester.addTest("Multiple Expression Remainder", me_remainder);
}