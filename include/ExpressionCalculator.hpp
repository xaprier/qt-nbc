#ifndef EXPRESSION_CALCULATOR_HPP
#define EXPRESSION_CALCULATOR_HPP

#include <QString>
#include <string>

#include "astnode.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"

class ExpressionCalculator {
  public:
    ExpressionCalculator(const QString &expression) : ExpressionCalculator(expression.toStdString()) {}
    ExpressionCalculator(const char *expression) : ExpressionCalculator(std::string(expression)) {}
    ExpressionCalculator(const std::string &expression);

    double result() { return m_result; }
    inline double getResult() { return result(); }
    inline double calculate() { return result(); }

    inline bool valid() { return m_valid; };
    inline bool isValid() { return m_valid; }

    operator double() const { return m_result; }
    operator std::string() const { return std::to_string(m_result); }
    operator QString() const { return QString::number(m_result); }
    operator bool() const { return m_valid; }

  private:
    double m_result;
    bool m_valid;
    std::string m_expression;
};

#endif  // EXPRESSION_CALCULATOR_HPP