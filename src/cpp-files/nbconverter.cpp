#include "../header-files/nbconverter.h"

#include <QComboBox>
#include <QMessageBox>
#include <QString>

#include "../design-files/ui_nbconverter.h"

QRegularExpression binExpression( "^-?[0-1]{1,}\\.?[0-1]*$" );
QRegularExpression octExpression( "^-?[0-7]{1,}\\.?[0-7]*$" );
QRegularExpression decExpression( "^-?[0-9]{1,}\\.?[0-9]*$" );
QRegularExpression hexExpression( "^-?[0-9A-F]{1,}\\.?[0-9A-F]*$" );

NBConverter::NBConverter( QWidget *parent )
    : QDialog( parent ), ui( new Ui::NBConverter ) {
    QWidget::setFixedSize( 800, 209 );

    ui->setupUi( this );

    connect( ui->binLine, &QLineEdit::textEdited, this,
             &NBConverter::textChanged );
    connect( ui->octLine, &QLineEdit::textEdited, this,
             &NBConverter::textChanged );
    connect( ui->decLine, &QLineEdit::textEdited, this,
             &NBConverter::textChanged );
    connect( ui->hexaLine, &QLineEdit::textEdited, this,
             &NBConverter::textChanged );
    connect( ui->exitBut, &QPushButton::clicked, this, &NBConverter::close );

    validator = new QRegularExpressionValidator( binExpression, this );
    ui->binLine->setValidator( validator );
    validator = new QRegularExpressionValidator( octExpression, this );
    ui->octLine->setValidator( validator );
    validator = new QRegularExpressionValidator( decExpression, this );
    ui->decLine->setValidator( validator );
    validator = new QRegularExpressionValidator( hexExpression, this );
    ui->hexaLine->setValidator( validator );
}

NBConverter::~NBConverter() { delete ui; }

void NBConverter::textChanged() {
    if ( QObject::sender() == ui->binLine ) {  // completed
        ui->octLine->setText( QString::fromStdString(
            binToDec( ui->binLine->text().toStdString() ) ) );
        ui->decLine->setText( QString::fromStdString(
            binToOct( ui->binLine->text().toStdString() ) ) );
        ui->hexaLine->setText( QString::fromStdString(
            binToHex( ui->binLine->text().toStdString() ) ) );
    } else if ( QObject::sender() == ui->decLine ) {  // completed
        ui->binLine->setText( QString::fromStdString(
            decToBin( ui->decLine->text().toStdString() ) ) );
        ui->octLine->setText( QString::fromStdString(
            decToOct( ui->decLine->text().toStdString() ) ) );
        ui->hexaLine->setText( QString::fromStdString(
            decToHex( ui->decLine->text().toStdString() ) ) );
    } else if ( QObject::sender() == ui->octLine ) {  // completed
        ui->binLine->setText( QString::fromStdString(
            octToBin( ui->octLine->text().toStdString() ) ) );
        ui->decLine->setText( QString::fromStdString(
            octToDec( ui->octLine->text().toStdString() ) ) );
        ui->hexaLine->setText( QString::fromStdString(
            octToHex( ui->octLine->text().toStdString() ) ) );
    } else {  // completed
        ui->binLine->setText( QString::fromStdString(
            hexToBin( ui->hexaLine->text().toStdString() ) ) );
        ui->decLine->setText( QString::fromStdString(
            hexToDec( ui->hexaLine->text().toStdString() ) ) );
        ui->octLine->setText( QString::fromStdString(
            hexToOct( ui->hexaLine->text().toStdString() ) ) );
    }
}
