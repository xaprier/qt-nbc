//
// Created by "xaprier" on "10/8/22"
//
#include "choose.hpp"

#include "../design/ui_choose.h"
#include "nbcalculator.hpp"
#include "nbconverter.hpp"

choose::choose(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::choose) {
    QWidget::setFixedSize(400, 200);
    this->m_ui->setupUi(this);

    connect(this->m_ui->pushButton, &QPushButton::clicked, this,
            &choose::sl_onPushButton_clicked);

    this->m_ui->comboBox->focusWidget();
}

choose::~choose() { delete this->m_ui; }

void choose::sl_onPushButton_clicked() {
    if (this->m_ui->comboBox->currentIndex() == 0) {
        auto *n = new NBConverter(this);
        n->exec();
        delete n;
    } else {
        auto *n = new NBCalculator(this);
        n->exec();
        delete n;
    }
}
