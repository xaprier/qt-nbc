//
// Created by "xaprier" on "10/8/22"
//
#include "NBCalculator.hpp"

#include <qcombobox.h>
#include <qlineedit.h>
#include <qvariant.h>
#include <qvector.h>

#include "ExpressionCalculator.hpp"
#include "ExpressionHandler.hpp"
#include "Expressions.hpp"

NBCalculator::NBCalculator(QWidget *parent) : QWidget(parent), m_ui(new Ui::NBCalculator) {
    // fixed size of window
    QWidget::setFixedSize(400, 200);
    m_ui->setupUi(this);

    // Ensure the exit button is not the default button for returnPressed connection

    connect(this->m_ui->txtBoxOperation, &QLineEdit::textChanged, this, &NBCalculator::sl_textChanged);
    connect(this->m_ui->txtBoxOperation, &QLineEdit::returnPressed, this, &NBCalculator::sl_returnPressed);
    connect(this->m_ui->cmbBoxResult, &QComboBox::currentTextChanged, this, &NBCalculator::sl_currentTextChanged);

    // exit button handler
    connect(m_ui->helpButton, &QToolButton::clicked, this, &NBCalculator::sl_help);

    this->m_handler = new ExpressionHandler(this->m_ui->txtBoxOperation);
}

NBCalculator::~NBCalculator() {
    delete m_ui;
    delete m_handler;
}

void NBCalculator::sl_returnPressed() {
    // disable signals
    this->m_ui->txtBoxOperation->blockSignals(true);

    this->m_ui->txtBoxOperation->setText(this->m_ui->cmbBoxResult->currentText() + this->m_ui->txtBoxResult->text());

    // enable signals
    this->m_ui->txtBoxOperation->blockSignals(false);
}

void NBCalculator::sl_help() {
    QMessageBox::about(
        this, tr("About Calculator"),
        tr(
            "Calculator usage is simple. Enter your number with base if you want different base than Decimal, insert operator like <b>+, -, *, /, %</b> then enter your second number.<br/><br/>"
            "The number of operations is no limited, so you can calculate complex operations like <b>0b111.101+0x17.FA*0o5.6</b>. Complex operations will be calculate with operator precedence.</br>"
            "There is a selection for what result base you want.<br/><br/>"
            "Supported operations: <b>+ - * / %</b><br/>"
            "Supported number bases: <b>Binary(0b) Octal(0o) Decimal(0d or nothing) Hexadecimal(0x)</b><br/>"
            "<br>You can define the entered number base with writing<br>"
            "<b>[-]0b1001.1001</b> for binary,<br>"
            "<b>[-]0o175.175</b> for octal,<br>"
            "<b>[-]0xA.F</b> for hexadecimal before the number.<br>"
            "If you don't define the base, the calculator will use the decimal base.<br><br>"
            "Example usages<br>"
            "<b>0b1001.11+0o15.75*0xA.F</b><br/>"
            "<b>15.35+0xA.B%0b101</b><br/><br/>"
            "If you want to exchange result with operation, press <b>Enter/Return</b>"));
}

void NBCalculator::sl_textChanged(const QString &text) {
    if (text.isEmpty()) return;
    bool isValid = false;
    auto res = this->m_evaluateExpression(text, isValid);
    this->m_cleanToString(res);
    if (isValid) {
        std::string convertedRes;
        Decimal number(res);
        switch (this->m_ui->cmbBoxResult->currentText().toLower().back().toLatin1()) {
            case 'b':
                convertedRes = number.toBin().getNum();
                break;
            case 'o':
                convertedRes = number.toOct().getNum();
                break;
            case 'd':
                convertedRes = res;
                break;
            case 'x':
                convertedRes = number.toHex().getNum();
                break;
        }
        this->m_ui->txtBoxResult->setText(QString::fromStdString(convertedRes));
    }
}

std::string NBCalculator::m_evaluateExpression(const QString &text, bool &valid) const {
    ExpressionCalculator calculator(text);
    valid = calculator;
    return calculator;
}

void NBCalculator::m_cleanToString(std::string &str) {
    // clean unneccessary 0's at the end
    while (!str.empty() && str.back() == '0') {
        str.pop_back();
    }

    // if last character remained ., add 1 zero
    if (!str.empty() && str.back() == '.') {
        str.append("0");
    }
}

void NBCalculator::sl_currentTextChanged(const QString &text) {
    this->sl_textChanged(this->m_ui->txtBoxOperation->text());
}