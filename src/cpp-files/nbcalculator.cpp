//
// Created by "xaprier" on "10/8/22"
//

#include "../header-files/nbcalculator.h"
#include "../design-files/ui_nbcalculator.h"


NBCalculator::NBCalculator( QWidget *parent ) : QDialog(parent), ui(new Ui::NBCalculator) {
	QWidget::setFixedSize(504, 371);
	ui->setupUi(this);
}

NBCalculator::~NBCalculator() {
	delete ui;
}
