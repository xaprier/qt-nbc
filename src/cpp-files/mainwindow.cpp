#include "../header-files/mainwindow.h"
#include "../header-files/nbc.h"

#include <QComboBox>
#include <QMessageBox>

#include "../design-files/ui_mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent), ui(new Ui::MainWindow) {

	ui->setupUi(this);

	// adding the options to the comboBox
	QStringList list = {"Binary", "Decimal", "Octal", "Hexadecimal"};
	ui->comboBox->addItems(list);
	ui->lconvert1->setText("Decimal");
	ui->lconvert2->setText("Octal");
	ui->lconvert3->setText("Hexadecimal");

	connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::comboChanged);
	connect(ui->convertBase, &QLineEdit::textChanged, this, &MainWindow::baseChanged);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::comboChanged() {
	ui->convert1->setText("");
	ui->convert2->setText("");
	ui->convert3->setText("");
	ui->convertBase->setText("");
	if (ui->comboBox->currentText() == "Binary") {
		ui->lconvert1->setText("Decimal");
		ui->lconvert2->setText("Octal");
		ui->lconvert3->setText("Hexadecimal");
	} else if (ui->comboBox->currentText() == "Decimal") {
		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Octal");
		ui->lconvert3->setText("Hexadecimal");
	} else if (ui->comboBox->currentText() == "Octal") {
		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Decimal");
		ui->lconvert3->setText("Hexadecimal");
	} else {
		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Decimal");
		ui->lconvert3->setText("Octal");
	}
}

void MainWindow::baseChanged() {
	if (ui->comboBox->currentText() == "Binary") {
		ui->convert1->setText(QString::fromStdString(nbc::binToDec(ui->convertBase->text().toStdString())));
		ui->convert2->setText(QString::fromStdString(nbc::binToOct(ui->convertBase->text().toStdString())));
		ui->convert3->setText("Hexadecimal");
	} else if (ui->comboBox->currentText() == "Decimal") {
		ui->convert1->setText("Binary");
		ui->convert2->setText(QString::fromStdString(nbc::decToOct(ui->convertBase->text().toStdString())));
		ui->convert3->setText("Hexadecimal");
	} else if (ui->comboBox->currentText() == "Octal") {
		ui->convert1->setText("Binary");
		ui->convert2->setText("Decimal");
		ui->convert3->setText("Hexadecimal");
	} else {
		ui->convert1->setText("Binary");
		ui->convert2->setText("Decimal");
		ui->convert3->setText("Octal");
	}
}
