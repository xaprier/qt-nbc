//
// Created by "xaprier" on "10/8/22"
//
#include <iostream>
#include <QMessageBox>
#include "header-files/choose.h"
#include "../design-files/ui_choose.h"

#include "header-files/nbcalculator.h"
#include "header-files/nbconverter.h"

choose::choose( QWidget *parent ) : QMainWindow(parent), ui(new Ui::choose) {
	QWidget::setFixedSize(481, 268);
	ui->setupUi(this);


	connect(ui->pushButton, &QPushButton::clicked, this, &choose::onPushButton_clicked);
}

choose::~choose() {
	delete ui;
}

void choose::onPushButton_clicked() {
	std::cout << ui->comboBox->currentIndex() << std::endl;
	if (ui->comboBox->currentIndex() == 0) {
		NBConverter *n = new NBConverter(this);
		n->exec();
	} else {
		NBCalculator *n = new NBCalculator(this);
		n->exec();
	}
}
