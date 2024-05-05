//
// Created by "xaprier" on "10/8/22"
//
#include "nbcalculator.hpp"

#include "../design/ui_nbcalculator.h"
#include "expressions.hpp"

NBCalculator::NBCalculator(QWidget *parent) : QDialog(parent), ui(new Ui::NBCalculator) {
    // fixed size of window
    QWidget::setFixedSize(400, 200);
    ui->setupUi(this);
    // starting values
    this->num1 = "0.0", this->num2 = "0.0";

    // catch the signals of combo box changes
    connect(ui->resCombo, &QComboBox::currentTextChanged, this,
            &NBCalculator::hasChanged);

    // catch the signals of line changes
    connect(ui->num1LE, &QLineEdit::textChanged, this, &NBCalculator::hasChanged);
    connect(ui->num2LE, &QLineEdit::textChanged, this, &NBCalculator::hasChanged);
    connect(ui->operation, &QComboBox::currentTextChanged, this, &NBCalculator::hasChanged);

    // exit button handler
    connect(ui->exitButton, &QPushButton::clicked, this,
            &NBCalculator::close);
    connect(ui->helpButton, &QToolButton::clicked, this, &NBCalculator::help);
    connect(ui->exitButton, &QPushButton::clicked, this, &NBCalculator::close);
    binaryNumber = new Number<Binary>("0.0");
    octalNumber = new Number<Octal>("0.0");
    decimalNumber = new Number<Decimal>("0.0");
    hexadecimalNumber = new Number<Hexadecimal>("0.0");
    validator = new QRegularExpressionValidator(QRegularExpression("^[0-9bBxXoO-]*"), this);
}

NBCalculator::~NBCalculator() {
    delete binaryNumber;
    delete octalNumber;
    delete decimalNumber;
    delete hexadecimalNumber;
    delete validator;
    delete ui;
}

void NBCalculator::hasChanged() {
    if (QObject::sender() == ui->num1LE) {
        QString temp = ui->num1LE->text();
        temp = temp.toLower();
        if (temp.isEmpty() || temp == "-") {
            this->num1 = "0.0";
            validator = new QRegularExpressionValidator(QRegularExpression("^[0-9bBxXoO-]*"), this);
        } else {
            int index = temp.contains("0b") ? 0 : temp.contains("0o") ? 1
                                              : temp.contains("0x")   ? 3
                                                                      : 2;
            if ((temp[0] == '-' && temp.length() == 3) || (temp.length() == 2 && temp[0] != '-')) {
                if (index == 0) {
                    validator = new QRegularExpressionValidator(binExpression, this);
                } else if (index == 1) {
                    validator = new QRegularExpressionValidator(octExpression, this);
                } else if (index == 2) {
                    validator = new QRegularExpressionValidator(decExpression, this);
                } else if (index == 3) {
                    validator = new QRegularExpressionValidator(hexExpression, this);
                }
            } else if ((temp.length() < 2 && temp[0] != '-') || (temp.length() < 3 && temp[0] == '-'))
                validator = new QRegularExpressionValidator(QRegularExpression("^[0-9bBxXoO-]*"), this);
            setNumbers(temp.toStdString(),
                       index,
                       &this->num1);
        }
        ui->num1LE->setValidator(validator);
    } else if (QObject::sender() == ui->num2LE) {
        QString temp = ui->num2LE->text();
        temp = temp.toLower();
        if (temp.isEmpty() || temp == "-") {
            this->num2 = "0.0";
            validator = new QRegularExpressionValidator(QRegularExpression("^[0-9bBxXoO-]*"), this);
        } else {
            int index = temp.startsWith("0b") ? 0 : temp.startsWith("0o") ? 1
                                                : temp.startsWith("0x")   ? 3
                                                                          : 2;
            if (temp.length() > 2) {
                if (index == 0) {
                    validator = new QRegularExpressionValidator(binExpression, this);
                } else if (index == 1) {
                    validator = new QRegularExpressionValidator(octExpression, this);
                } else if (index == 2) {
                    validator = new QRegularExpressionValidator(decExpression, this);
                } else if (index == 3) {
                    validator = new QRegularExpressionValidator(hexExpression, this);
                }
            } else if ((temp.length() < 2 && temp[0] != '-') || (temp.length() < 3 && temp[0] == '-'))
                validator = new QRegularExpressionValidator(QRegularExpression("^[0-9bBxXoO-]*"), this);

            setNumbers(temp.toStdString(),
                       index,
                       &this->num2);
        }
        ui->num1LE->setValidator(validator);
    }
    calculate();
}

void NBCalculator::setNumbers(const std::string &numberToConvert, int indexing,
                              std::string *pointOfNumber) {
    // clear whitespaces in numberToConvert
    std::string numberToConvertCleared = numberToConvert;
    numberToConvertCleared = numberToConvertCleared.empty() ? "0" : numberToConvertCleared;

    // clear the whitespaces if exists
    numberToConvertCleared.erase(std::remove(numberToConvertCleared.begin(), numberToConvertCleared.end(), ' '), numberToConvertCleared.end());
    switch (indexing) {
        // binary
        case 0: {
            binaryNumber = new Number<Binary>(numberToConvertCleared);
            *pointOfNumber = binaryNumber->getNumber().toDec().getNum();
            break;
        }
        // octal
        case 1: {
            octalNumber = new Number<Octal>(numberToConvertCleared);
            *pointOfNumber = octalNumber->getNumber().toDec().getNum();
            break;
        }
        // decimal
        case 2: {
            *pointOfNumber = numberToConvertCleared;
            break;
        }
        // hexadecimal
        case 3: {
            hexadecimalNumber = new Number<Hexadecimal>(numberToConvertCleared);
            *pointOfNumber = hexadecimalNumber->getNumber().toDec().getNum();
            break;
        }
    }
}

void NBCalculator::calculate() {
    // maybe there is an easier way...
    // setting locale for QApplication changes(. might be , in region)
    const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
    std::setlocale(LC_NUMERIC, "C");

    if (ui->operation->currentText().isEmpty())
        return;

    /*
     * Number<Decimal> mulRes = Number<Decimal>(num1) * Number<Decimal>(num2);...
     */

    switch (ui->resCombo->currentIndex()) {
        // binary
        case 0: {
            switch (ui->operation->currentText().toStdString().at(0)) {
                // addition
                case '+': {
                    binaryNumber = new Number<Binary>(Number<Decimal>(num1) + Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(binaryNumber->getNumber().getNum()));
                    break;
                }
                // subtraction
                case '-': {
                    binaryNumber = new Number<Binary>(Number<Decimal>(num1) - Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(binaryNumber->getNumber().getNum()));
                    break;
                }
                // multiplication
                case '*': {
                    binaryNumber = new Number<Binary>(Number<Decimal>(num1) * Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(binaryNumber->getNumber().getNum()));
                    break;
                }
                // dividing
                case '/': {
                    // exception handling for divide by 0
                    try {
                        binaryNumber = new Number<Binary>(Number<Decimal>(num1) / Number<Decimal>(num2));
                    } catch (const std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(binaryNumber->getNumber().getNum()));
                    break;
                }
                // modulo
                case '%': {
                    try {
                        binaryNumber = new Number<Binary>(Number<Decimal>(num1) % Number<Decimal>(num2));
                    } catch (std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(binaryNumber->getNumber().getNum()));
                    break;
                }
            }
            break;
        }
        // octal
        case 1: {
            switch (ui->operation->currentText().toStdString().at(0)) {
                // addition
                case '+': {
                    octalNumber = new Number<Octal>(Number<Decimal>(num1) + Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(octalNumber->getNumber().getNum()));
                    break;
                }
                // subtraction
                case '-': {
                    octalNumber = new Number<Octal>(Number<Decimal>(num1) - Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(octalNumber->getNumber().getNum()));
                    break;
                }
                // multiplication
                case '*': {
                    octalNumber = new Number<Octal>(Number<Decimal>(num1) * Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(octalNumber->getNumber().getNum()));
                    break;
                }
                // dividing
                case '/': {
                    // exception handling for divide by 0
                    try {
                        octalNumber = new Number<Octal>(Number<Decimal>(num1) / Number<Decimal>(num2));
                    } catch (const std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(octalNumber->getNumber().getNum()));
                    break;
                }
                // modulo
                case '%': {
                    try {
                        octalNumber = new Number<Octal>(Number<Decimal>(num1) % Number<Decimal>(num2));
                    } catch (std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(octalNumber->getNumber().getNum()));
                    break;
                }
            }
            break;
        }
        // decimal
        case 2: {
            switch (ui->operation->currentText().toStdString().at(0)) {
                // addition
                case '+': {
                    decimalNumber = new Number<Decimal>(Number<Decimal>(num1) + Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(decimalNumber->getNumber().getNum()));
                    break;
                }
                // subtraction
                case '-': {
                    decimalNumber = new Number<Decimal>(Number<Decimal>(num1) - Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(decimalNumber->getNumber().getNum()));
                    break;
                }
                // multiplication
                case '*': {
                    decimalNumber = new Number<Decimal>(Number<Decimal>(num1) * Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(decimalNumber->getNumber().getNum()));
                    break;
                }
                // dividing
                case '/': {
                    // exception handling for divide by 0
                    try {
                        decimalNumber = new Number<Decimal>(Number<Decimal>(num1) / Number<Decimal>(num2));
                    } catch (const std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(decimalNumber->getNumber().getNum()));
                    break;
                }
                // modulo
                case '%': {
                    try {
                        decimalNumber = new Number<Decimal>(Number<Decimal>(num1) % Number<Decimal>(num2));
                    } catch (std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(decimalNumber->getNumber().getNum()));
                    break;
                }
            }
            break;
        }
        // hexadecimal
        case 3: {
            switch (ui->operation->currentText().toStdString().at(0)) {
                // addition
                case '+': {
                    hexadecimalNumber = new Number<Hexadecimal>(Number<Decimal>(num1) + Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(hexadecimalNumber->getNumber().getNum()));
                    break;
                }
                // subtraction
                case '-': {
                    hexadecimalNumber = new Number<Hexadecimal>(Number<Decimal>(num1) - Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(hexadecimalNumber->getNumber().getNum()));
                    break;
                }
                // multiplication
                case '*': {
                    hexadecimalNumber = new Number<Hexadecimal>(Number<Decimal>(num1) * Number<Decimal>(num2));
                    ui->resLine->setText(QString::fromStdString(hexadecimalNumber->getNumber().getNum()));
                    break;
                }
                // dividing
                case '/': {
                    // exception handling for divide by 0
                    try {
                        hexadecimalNumber = new Number<Hexadecimal>(Number<Decimal>(num1) / Number<Decimal>(num2));
                    } catch (const std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(hexadecimalNumber->getNumber().getNum()));
                    break;
                }
                // modulo
                case '%': {
                    try {
                        hexadecimalNumber = new Number<Hexadecimal>(Number<Decimal>(num1) % Number<Decimal>(num2));
                    } catch (std::runtime_error &a) {
                        ui->resLine->setText(a.what());
                        return;
                    }
                    ui->resLine->setText(QString::fromStdString(hexadecimalNumber->getNumber().getNum()));
                    break;
                }
            }
            break;
        }
    }
    // setting the locale to old
    std::setlocale(LC_NUMERIC, oldLocale.c_str());
}

void NBCalculator::help() {
    QMessageBox::about(
        this, tr("About Calculator"),
        tr("If you want to use the calculator, you have to enter two numbers and choose the operation you want to do. Then you can choose the base of the result. The calculator supports the following operations: addition, subtraction, multiplication, division and modulo. The calculator supports the following bases: binary, octal, decimal and hexadecimal."
           "<br><br>You can define the entered number base with writing<br> <b>[-]0b1001.1001</b> for binary, <br><b>[-]0o175.175</b> for octal, <br><b>[-]0xA.F</b> for hexadecimal before the number. <br>If you don't define the base, the calculator will use the decimal base."));
}
