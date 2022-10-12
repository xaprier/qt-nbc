#include "../header-files/nbconverter.h"
#include "../header-files/nbc.h"

#include <QComboBox>
#include <QMessageBox>
#include <QString>

#include "../design-files/ui_nbconverter.h"

QRegularExpression binExpression("^-?[0-1]{1,}\\.?[0-1]*$");
QRegularExpression octExpression("^-?[0-7]{1,}\\.?[0-7]*$");
QRegularExpression decExpression("^-?[0-9]{1,}\\.?[0-9]*$");
QRegularExpression hexExpression("^-?[0-9A-F]{1,}\\.?[0-9A-F]*$");

NBConverter::NBConverter( QWidget *parent ) : QDialog(parent), ui(new Ui::NBConverter) {
	QWidget::setFixedSize(800, 600);

	ui->setupUi(this);

	// adding the options to the comboBox
	QStringList list = {"Binary", "Decimal", "Octal", "Hexadecimal"};
	ui->comboBox->addItems(list);
	ui->lconvert1->setText("Decimal");
	ui->lconvert2->setText("Octal");
	ui->lconvert3->setText("Hexadecimal");

	connect(ui->comboBox, &QComboBox::currentTextChanged, this, &NBConverter::comboChanged);
	connect(ui->convertBase, &QLineEdit::textChanged, this, &NBConverter::baseChanged);

	validator = new QRegularExpressionValidator(binExpression, this);
	ui->convertBase->setValidator(validator);
}

NBConverter::~NBConverter() {
	delete ui;
}

void NBConverter::comboChanged() {
	ui->convert1->setText("0.0");
	ui->convert2->setText("0.0");
	ui->convert3->setText("0.0");
	ui->convertBase->setText("");
	if (ui->comboBox->currentText() == "Binary") {

		validator = new QRegularExpressionValidator(binExpression, this);
		ui->convertBase->setValidator(validator);

		ui->lconvert1->setText("Decimal");
		ui->lconvert2->setText("Octal");
		ui->lconvert3->setText("Hexadecimal");

	} else if (ui->comboBox->currentText() == "Decimal") {
		validator = new QRegularExpressionValidator(decExpression, this);
		ui->convertBase->setValidator(validator);

		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Octal");
		ui->lconvert3->setText("Hexadecimal");

	} else if (ui->comboBox->currentText() == "Octal") {
		validator = new QRegularExpressionValidator(octExpression, this);
		ui->convertBase->setValidator(validator);

		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Decimal");
		ui->lconvert3->setText("Hexadecimal");

	} else {
		validator = new QRegularExpressionValidator(hexExpression, this);
		ui->convertBase->setValidator(validator);

		ui->lconvert1->setText("Binary");
		ui->lconvert2->setText("Decimal");
		ui->lconvert3->setText("Octal");

	}
}

void NBConverter::baseChanged() {
	if (ui->comboBox->currentText() == "Binary") { // completed
		ui->convert1->setText(QString::fromStdString(nbc::binToDec(ui->convertBase->text().toStdString())));
		ui->convert2->setText(QString::fromStdString(nbc::binToOct(ui->convertBase->text().toStdString())));
		ui->convert3->setText(QString::fromStdString(nbc::binToHex(ui->convertBase->text().toStdString())));
	} else if (ui->comboBox->currentText() == "Decimal") { // completed
		ui->convert1->setText(QString::fromStdString(nbc::decToBin(ui->convertBase->text().toStdString())));
		ui->convert2->setText(QString::fromStdString(nbc::decToOct(ui->convertBase->text().toStdString())));
		ui->convert3->setText(QString::fromStdString(nbc::decToHex(ui->convertBase->text().toStdString())));
	} else if (ui->comboBox->currentText() == "Octal") { // completed
		ui->convert1->setText(QString::fromStdString(nbc::octToBin(ui->convertBase->text().toStdString())));
		ui->convert2->setText(QString::fromStdString(nbc::octToDec(ui->convertBase->text().toStdString())));
		ui->convert3->setText(QString::fromStdString(nbc::octToHex(ui->convertBase->text().toStdString())));
	} else { // completed
		ui->convert1->setText(QString::fromStdString(nbc::hexToBin(ui->convertBase->text().toStdString())));
		ui->convert2->setText(QString::fromStdString(nbc::hexToDec(ui->convertBase->text().toStdString())));
		ui->convert3->setText(QString::fromStdString(nbc::hexToOct(ui->convertBase->text().toStdString())));
	}
}
