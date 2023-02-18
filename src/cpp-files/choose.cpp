//
// Created by "xaprier" on "10/8/22"
//
#include "src/header-files/choose.h"

#include <QMessageBox>

#include "../design-files/ui_choose.h"
#include "src/header-files/nbcalculator.h"
#include "src/header-files/nbconverter.h"

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
