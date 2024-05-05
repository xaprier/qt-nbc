//
// Created by "xaprier" on "10/8/22"
//
#include "choose.hpp"

#include <QMessageBox>

#include "../design/ui_choose.h"
#include "nbcalculator.hpp"
#include "nbconverter.hpp"

choose::choose(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::choose) {
    QWidget::setFixedSize(481, 268);
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this,
            &choose::onPushButton_clicked);

    ui->comboBox->focusWidget();
}

choose::~choose() { delete ui; }

void choose::onPushButton_clicked() {
    if (ui->comboBox->currentIndex() == 0) {
        auto *n = new NBConverter(this);
        n->exec();
        delete n;
    } else {
        auto *n = new NBCalculator(this);
        n->exec();
        delete n;
    }
}
