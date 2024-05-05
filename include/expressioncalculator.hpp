#ifndef EXPRESSION_CALCULATOR_HPP
#define EXPRESSION_CALCULATOR_HPP

#include <QDebug>
#include <QStack>
#include <QString>
#include <cmath>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

class ExpressionCalculator {
  public:
    explicit ExpressionCalculator(const QString &expression);

    operator double() const { return m_res; }
    bool isExpressionValid();

  private:
    void doCalc();
    double applyOperation(const double &num1, const double &num2, const QChar &op);
    template <typename T>
    double getConvertedNumber(const T &num);
    double getConvertedNumber(const QString &num);

    inline bool isOperator(QChar ch);
    inline bool isBase(QChar ch);
    inline int precedence(QChar op);

    double m_res = 0.0;
    QString m_expression;
};

#endif  // EXPRESSION_CALCULATOR_HPP