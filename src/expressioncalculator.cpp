#include "expressioncalculator.hpp"

#include <cctype>

ExpressionCalculator::ExpressionCalculator(const std::string &expression) : m_expression(expression), m_result(0), m_valid(false) {
    m_valid = valid();  // NOLINT
    if (m_valid) {
        Tokenizer lexer(expression);
        lexer.tokenize();
        Parser parser(lexer.getTokens());
        AST<double> tree;
        tree.build(parser.getPostfix());
        m_result = tree.evaluate();
    }
}

bool ExpressionCalculator::valid() {
    int countParentheses = 0;
    int countDots = 0;
    int countBases = 0;
    bool lastWasOperator = true;

    // clear whitespaces in string
    m_expression.erase(std::remove_if(m_expression.begin(), m_expression.end(), ::isspace), m_expression.end());

    auto isOperator = [](char token) -> bool {
        return token == '+' || token == '-' || token == '*' || token == '/' || token == '%';
    };

    auto isDigit = [](char token) -> bool {
        return static_cast<int>(token) >= 48 && static_cast<int>(token) <= 57;
    };

    auto isBase = [](char token) -> bool {
        token = static_cast<char>(std::tolower(token));
        return token == 'd' || token == 'x' || token == 'o' || token == 'b';
    };

    auto isDot = [](char token) -> bool {
        return token == '.';
    };

    for (int i = 0; i < m_expression.length(); ++i) {
        char token = m_expression[i];
        if (token == '(') {
            if (!lastWasOperator && i > 0) return false;  // begin or there is no operator behind of (
            countParentheses++;
            lastWasOperator = true;
        } else if (token == ')') {
            if (lastWasOperator) return false;  // there cant be any operator behind of )
            countParentheses--;
            countDots = 0;
            countBases = 0;
            if (countParentheses < 0) return false;  // there cant be close paranthesis before open paranthesis
        } else if (isOperator(token)) {
            lastWasOperator = true;
            countDots = 0;
            countBases = 0;
        } else if (isBase(token)) {
            if (i > 0 && m_expression[i - 1] != '0' && !lastWasOperator) return false;  // there cant be base after number
            lastWasOperator = false;
            countBases++;
            if (countBases > 1) return false;
        } else if (isDigit(token)) {
            lastWasOperator = false;
            while (isDigit(m_expression[i])) i++;
            i--;
        } else if (isDot(token)) {
            countDots++;
            if (countDots > 1) return false;
        } else
            return false;
    }

    if (countParentheses != 0) return false;
    if (countDots != 0) return false;
    if (countBases != 0) return false;
    if (lastWasOperator) return false;

    return true;
}