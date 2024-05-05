#include "nbconverter.hpp"

#include <qobject.h>

#include "../design/ui_nbconverter.h"

extern QRegularExpression binExpression;
extern QRegularExpression octExpression;
extern QRegularExpression decExpression;
extern QRegularExpression hexExpression;

NBConverter::NBConverter(QWidget *parent) : QDialog(parent), ui(new Ui::NBConverter) {
    QWidget::setFixedSize(800, 209);

    ui->setupUi(this);

    connect(ui->binLine, &QLineEdit::textEdited, this,
            &NBConverter::textChanged);
    connect(ui->octLine, &QLineEdit::textEdited, this,
            &NBConverter::textChanged);
    connect(ui->decLine, &QLineEdit::textEdited, this,
            &NBConverter::textChanged);
    connect(ui->hexaLine, &QLineEdit::textEdited, this,
            &NBConverter::textChanged);
    connect(ui->exitBut, &QPushButton::clicked, this, &NBConverter::close);

    this->setupValidator();
}

NBConverter::~NBConverter() {
    delete ui;
}

void NBConverter::textChanged() {
    QString bin = ui->binLine->text(), oct = ui->octLine->text(), dec = ui->decLine->text(), hex = ui->hexaLine->text();

    if (QObject::sender() == ui->binLine) {
        b = new Number<Binary>(ui->binLine->text().toStdString());
        oct = QString::fromStdString(b->getNumber().toOct().getNum());
        dec = QString::fromStdString(b->getNumber().toDec().getNum());
        hex = QString::fromStdString(b->getNumber().toHex().getNum());
        delete b;
    } else if (QObject::sender() == ui->decLine) {
        d = new Number<Decimal>(ui->decLine->text().toStdString());
        bin = QString::fromStdString(d->getNumber().toBin().getNum());
        oct = QString::fromStdString(d->getNumber().toOct().getNum());
        hex = QString::fromStdString(d->getNumber().toHex().getNum());
        delete d;
    } else if (QObject::sender() == ui->octLine) {
        o = new Number<Octal>(ui->octLine->text().toStdString());
        bin = QString::fromStdString(o->getNumber().toBin().getNum());
        dec = QString::fromStdString(o->getNumber().toDec().getNum());
        hex = QString::fromStdString(o->getNumber().toHex().getNum());
        delete o;
    } else {
        h = new Number<Hexadecimal>(ui->hexaLine->text().toStdString());
        bin = QString::fromStdString(h->getNumber().toBin().getNum());
        oct = QString::fromStdString(h->getNumber().toOct().getNum());
        dec = QString::fromStdString(h->getNumber().toDec().getNum());
        delete h;
    }
    ui->binLine->setText(bin);
    ui->octLine->setText(oct);
    ui->decLine->setText(dec);
    ui->hexaLine->setText(hex);
}

void NBConverter::setupValidator() {
    ui->binLine->setValidator(new QRegularExpressionValidator(binExpression));
    ui->octLine->setValidator(new QRegularExpressionValidator(octExpression));
    ui->decLine->setValidator(new QRegularExpressionValidator(decExpression));
    ui->hexaLine->setValidator(new QRegularExpressionValidator(hexExpression));
}
