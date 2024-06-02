#include "expressioncalculator.hpp"

#include <cctype>
#include <exception>
#include <stdexcept>

ExpressionCalculator::ExpressionCalculator(const std::string &expression) : m_expression(expression), m_result(0), m_valid(false) {
    try {
        if (m_expression.empty()) throw std::runtime_error("Expression cannot be empty");
        Tokenizer lexer(m_expression);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        m_result = tree.evaluate();
        m_valid = true;
    } catch (const std::exception &e) {
        std::cerr << "Exception occured: " << e.what() << std::endl;
        m_valid = false;
    }
}