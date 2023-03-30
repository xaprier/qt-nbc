#include "../header-files/nbconverter.h"

#include <QComboBox>
#include <QMessageBox>
#include <QString>

#include "../design-files/ui_nbconverter.h"
#include "inc/Number.h"

QRegularExpression binExpression("^-?0?b?[0-1]{1,}\\.?[0-1]*$");
QRegularExpression octExpression("^-?0?o?[0-7]{1,}\\.?[0-7]*$");
QRegularExpression decExpression("^-?[0-9]{1,}\\.?[0-9]*$");
QRegularExpression hexExpression("^-?0?x?[0-9A-F]{1,}\\.?[0-9A-F]*$");

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

    validator = new QRegularExpressionValidator(binExpression, this);
    ui->binLine->setValidator(validator);
    validator = new QRegularExpressionValidator(octExpression, this);
    ui->octLine->setValidator(validator);
    validator = new QRegularExpressionValidator(decExpression, this);
    ui->decLine->setValidator(validator);
    validator = new QRegularExpressionValidator(hexExpression, this);
    ui->hexaLine->setValidator(validator);
}

NBConverter::~NBConverter() { delete ui; }

void NBConverter::textChanged() {
    QString bin = ui->binLine->text(), oct = ui->octLine->text(), dec = ui->decLine->text(), hex = ui->hexaLine->text();

    if (QObject::sender() == ui->binLine) {  // completed
        b = new Number<Binary>(ui->binLine->text().toStdString());
        oct = QString::fromStdString(b->getNumber().toOct().getNum());
        dec = QString::fromStdString(b->getNumber().toDec().getNum());
        hex = QString::fromStdString(b->getNumber().toHex().getNum());
        delete b;
    } else if (QObject::sender() == ui->decLine) {  // completed
        d = new Number<Decimal>(ui->decLine->text().toStdString());
        bin = QString::fromStdString(d->getNumber().toBin().getNum());
        oct = QString::fromStdString(d->getNumber().toOct().getNum());
        hex = QString::fromStdString(d->getNumber().toHex().getNum());
        delete d;
    } else if (QObject::sender() == ui->octLine) {  // completed
        o = new Number<Octal>(ui->octLine->text().toStdString());
        bin = QString::fromStdString(o->getNumber().toBin().getNum());
        dec = QString::fromStdString(o->getNumber().toDec().getNum());
        hex = QString::fromStdString(o->getNumber().toHex().getNum());
        delete o;
    } else {  // completed
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
