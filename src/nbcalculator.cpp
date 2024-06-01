//
// Created by "xaprier" on "10/8/22"
//
#include "nbcalculator.hpp"

#include <qvariant.h>
#include <qvector.h>

#include "../design/ui_nbcalculator.h"
#include "expressionhandler.hpp"
#include "expressions.hpp"

NBCalculator::NBCalculator(QWidget *parent) : QDialog(parent), ui(new Ui::NBCalculator) {
    // fixed size of window
    QWidget::setFixedSize(400, 200);
    ui->setupUi(this);

    connect(this->ui->txtBoxOperation, &QLineEdit::textChanged, this, &NBCalculator::sl_operationChanged);

    // exit button handler
    connect(ui->exitButton, &QPushButton::clicked, this,
            &NBCalculator::close);
    connect(ui->helpButton, &QToolButton::clicked, this, &NBCalculator::sl_help);
    connect(ui->exitButton, &QPushButton::clicked, this, &NBCalculator::close);

    this->handler = new ExpressionHandler(this->ui->txtBoxOperation);
}

NBCalculator::~NBCalculator() {
    delete validator;
    delete ui;
}

// void NBCalculator::calculate() {
//     // maybe there is an easier way...
//     // setting locale for QApplication changes(. might be , in region)
//     const std::string oldLocale = std::setlocale(LC_NUMERIC, nullptr);
//     std::setlocale(LC_NUMERIC, "C");

//     // setting the locale to old
//     std::setlocale(LC_NUMERIC, oldLocale.c_str());
// }

void NBCalculator::sl_operationChanged() {
}

void NBCalculator::sl_enterClicked() {}
void NBCalculator::sl_wrongCharClicked() {}

void NBCalculator::sl_help() {
    QMessageBox::about(
        this, tr("About Calculator"),
        tr("If you want to use the calculator, you have to enter two numbers and choose the operation you want to do. Then you can choose the base of the result. The calculator supports the following operations: addition, subtraction, multiplication, division and modulo. The calculator supports the following bases: binary, octal, decimal and hexadecimal."
           "<br><br>You can define the entered number base with writing<br> <b>[-]0b1001.1001</b> for binary, <br><b>[-]0o175.175</b> for octal, <br><b>[-]0xA.F</b> for hexadecimal before the number. <br>If you don't define the base, the calculator will use the decimal base."));
}

void NBCalculator::updateResult() {}
