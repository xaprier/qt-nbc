#include <QCoreApplication>
#include <QDebug>
#include <QStack>
#include <QString>
#include <cmath>

bool isOperator(QChar ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(QChar op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;  // parantheses
}

double applyOperation(double a, double b, QChar op) {
    switch (op.toLatin1()) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return fmod(a, b);
        default:
            return 0.0;
    }
}

double evaluateExpression(const QString &expression) {
    QStack<double> values;
    QStack<QChar> operators;

    for (int i = 0; i < expression.length(); ++i) {
        QChar token = expression[i];
        if (token.isDigit()) {
            QString number;
            while (i < expression.length() && expression[i].isDigit()) {
                number.append(expression[i]);
                ++i;
            }
            values.push(number.toDouble());
            --i;  // Decrement i to account for the last digit processed
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

    return values.top();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString expression = "23 + 49 * (53 + 5)";
    double result = evaluateExpression(expression);
    qDebug() << "Result:" << result;

    return a.exec();
}
