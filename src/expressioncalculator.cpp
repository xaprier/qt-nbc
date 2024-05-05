#include "expressioncalculator.hpp"

#include <exception>

#include "BaseClass.hpp"
#include "Number.hpp"

ExpressionCalculator::ExpressionCalculator(const QString &expression) : m_expression(expression) {
    if (this->isExpressionValid()) this->doCalc();
}

bool ExpressionCalculator::isExpressionValid() {
    int countParentheses = 0;
    int countOperators = 0;
    int countOperands = 0;

    for (int i = 0; i < m_expression.length(); ++i) {
        QChar token = m_expression[i];
        if (token == '(') {
            countParentheses++;
        } else if (token == ')') {
            countParentheses--;
            if (countParentheses < 0) {
                return false;  // Unmatched closing parenthesis
            }
        } else if (isOperator(token)) {
            countOperators++;
        } else if (token.isDigit()) {
            QString number;
            while (i < m_expression.length() && m_expression[i].isDigit()) {
                number.append(m_expression[i]);
                ++i;
            }
            ++countOperands;
            --i;  // Decrement i to account for the last digit processed
        }
    }

    // Check if parentheses are balanced
    if (countParentheses != 0)
        return false;

    // Check if operators and operands counts are valid
    if (countOperands != countOperators + 1)
        return false;

    return true;
}

void ExpressionCalculator::doCalc() {
    QStack<double> values;
    QStack<QChar> operators;

    for (int i = 0; i < m_expression.length(); ++i) {
        QChar token = m_expression[i];
        bool isBased = false;
        try {
            isBased = this->isBase(token) || (this->isBase(token) && this->isBase(m_expression[i + 1]));
        } catch (const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }

        if (token.isDigit() && !isBased) {  // directly decimal number
            QString number;
            while (i < m_expression.length() && m_expression[i].isDigit()) {
                number.append(m_expression[i]);
                ++i;
            }
            std::cout << "number : " << number.toStdString() << std::endl;
            values.push(number.toDouble());
            --i;  // Decrement i to account for the last digit processed
        } else if (isBased) {
            QString number;
            if (this->isBase(token)) {  // starts with x1F.A3, token "x"
                number.append("0");
                number.append(token);
                i++;
            } else {  // starts with 0x1F.A3, token "0"
                number.append(token);
                number.append(m_expression[i + 1]);
                i += 2;
            }
            while (i < m_expression.length() && m_expression[i].isDigit()) {
                number.append(m_expression[i]);
                ++i;
            }
            std::cout << "isBased : " << number.toStdString() << std::endl;
            values.push_back(this->getConvertedNumber(number));
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                QChar op = operators.pop();
                double val2 = values.pop();
                double val1 = values.pop();
                values.push(applyOperation(val1, val2, op));
            }
            operators.pop();  // Pop '('
        } else if (isOperator(token)) {
            while (!operators.isEmpty() && precedence(operators.top()) >= precedence(token)) {
                QChar op = operators.pop();
                double val2 = values.pop();
                double val1 = values.pop();
                values.push(applyOperation(val1, val2, op));
            }
            operators.push(token);
        }
    }

    while (!operators.isEmpty()) {
        QChar op = operators.pop();
        double val2 = values.pop();
        double val1 = values.pop();
        values.push(applyOperation(val1, val2, op));
    }

    // set result
    this->m_res = values.top();
}

double ExpressionCalculator::applyOperation(const double &num1, const double &num2, const QChar &op) {
    bool ok = true;

    switch (op.toLatin1()) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return fmod(num1, num2);
        default:
            return .0;
    }
}

template <typename T>
double ExpressionCalculator::getConvertedNumber(const T &num) {
    auto result = (std::string)num.toDec();
    return std::stod(result);
}

double ExpressionCalculator::getConvertedNumber(const QString &num) {
    if (num.toLower().contains('b')) return this->getConvertedNumber<Binary>(Binary(num.toStdString()));
    if (num.toLower().contains('o')) return this->getConvertedNumber<Octal>(Octal(num.toStdString()));
    if (num.toLower().contains('d')) return this->getConvertedNumber<Decimal>(Decimal(num.toStdString()));
    if (num.toLower().contains('x')) return this->getConvertedNumber<Hexadecimal>(Hexadecimal(num.toStdString()));
    return this->getConvertedNumber<Decimal>(Decimal(num.toStdString()));
}

inline bool ExpressionCalculator::isOperator(QChar ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

inline bool ExpressionCalculator::isBase(QChar ch) {
    ch = ch.toLower();
    return ch == 'd' || ch == 'x' || ch == 'o' || ch == 'b';  //* decimal, hexadecimal, octal, binary
}

inline int ExpressionCalculator::precedence(QChar op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;  // parantheses
}
