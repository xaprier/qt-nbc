//
// Created by "xaprier" on "10/8/22"
//
#include "../header-files/nbcalculator.h"

#include <QRegularExpression>
extern QRegularExpression binExpression;
extern QRegularExpression octExpression;
extern QRegularExpression decExpression;
extern QRegularExpression hexExpression;

#include "../design-files/ui_nbcalculator.h"
#include "../header-files/nbconverter.h"

NBCalculator::NBCalculator( QWidget *parent )
    : QDialog( parent ), ui( new Ui::NBCalculator ) {
    // fixed size of window
    QWidget::setFixedSize( 596, 275 );
    ui->setupUi( this );
    // starting values
    this->num1 = "0.0", this->num2 = "0.0";

    // catch the signals of combo box changes
    connect( ui->num1Combo, &QComboBox::currentTextChanged, this,
             &NBCalculator::hasChanged );
    connect( ui->num2Combo, &QComboBox::currentTextChanged, this,
             &NBCalculator::hasChanged );
    connect( ui->resCombo, &QComboBox::currentTextChanged, this,
             &NBCalculator::hasChanged );
    connect( ui->operationCombo, &QComboBox::currentTextChanged, this,
             &NBCalculator::hasChanged );

    // catch the signals of line changes
    connect( ui->num1Line, &QLineEdit::textChanged, this,
             &NBCalculator::hasChanged );
    connect( ui->num2Line, &QLineEdit::textChanged, this,
             &NBCalculator::hasChanged );

    // exit button handler
    connect( ui->exitButton, &QPushButton::clicked, this,
             &NBCalculator::close );
    // validation for first start(from binary)
    validator = new QRegularExpressionValidator( binExpression, this );
    ui->num1Line->setValidator( validator );
    ui->num2Line->setValidator( validator );
}

NBCalculator::~NBCalculator() { delete ui; }

void NBCalculator::hasChanged() {
    // number 1
    setNumbers( ( ui->num1Line->text().toStdString().length() != 0 )
                    ? ui->num1Line->text().toStdString()
                    : "0.0",
                ui->num1Combo->currentIndex(), this->num1 );

    // number 2
    setNumbers( ( ui->num2Line->text().toStdString().length() != 0 )
                    ? ui->num2Line->text().toStdString()
                    : "0.0",
                ui->num2Combo->currentIndex(), this->num2 );

    calculate( this->num1, this->num2 );
}

void NBCalculator::setNumbers( std::string numberToConvert, int indexing,
                               std::string &pointOfNumber ) {
    switch ( indexing ) {
        case 0: {
            validator = new QRegularExpressionValidator( binExpression, this );
            ( &pointOfNumber == &this->num1 )
                ? ui->num1Line->setValidator( validator )
                : ui->num2Line->setValidator( validator );
            pointOfNumber = binToDec( numberToConvert );
            break;
        }
        // octal
        case 1: {
            validator = new QRegularExpressionValidator( octExpression, this );
            ( &pointOfNumber == &this->num1 )
                ? ui->num1Line->setValidator( validator )
                : ui->num2Line->setValidator( validator );
            pointOfNumber = octToDec( numberToConvert );
            break;
        }
        // decimal
        case 2: {
            validator = new QRegularExpressionValidator( decExpression, this );
            ( &pointOfNumber == &this->num1 )
                ? ui->num1Line->setValidator( validator )
                : ui->num2Line->setValidator( validator );
            pointOfNumber = numberToConvert;
            break;
        }
        // hexadecimal
        default: {
            validator = new QRegularExpressionValidator( hexExpression, this );
            ( &pointOfNumber == &this->num1 )
                ? ui->num1Line->setValidator( validator )
                : ui->num2Line->setValidator( validator );
            pointOfNumber = hexToDec( numberToConvert );
        }
    }
}

void NBCalculator::calculate( std::string num1, std::string num2 ) {
    // maybe there is a easier way...
    switch ( ui->resCombo->currentIndex() ) {
        // binary
        case 0: {
            switch ( ui->operationCombo->currentIndex() ) {
                // addition
                case 0: {
                    ui->resLine->setText( QString::fromStdString( decToBin(
                        QString::number( std::stod( num1 ) + std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // subtraction
                case 1: {
                    ui->resLine->setText( QString::fromStdString( decToBin(
                        QString::number( std::stod( num1 ) - std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // multiplication
                case 2: {
                    ui->resLine->setText( QString::fromStdString( decToBin(
                        QString::number( std::stod( num1 ) * std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // dividing
                default: {
                    // exception handling for divide by 0
                    if ( std::stod( num2 ) == 0.0 ) {
                        ui->resLine->setText( "NaN" );
                        break;
                    }
                    ui->resLine->setText( QString::fromStdString( decToBin(
                        QString::number( std::stod( num1 ) / std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
            }
            break;
        }
        // octal
        case 1: {
            switch ( ui->operationCombo->currentIndex() ) {
                // addition
                case 0: {
                    ui->resLine->setText( QString::fromStdString( decToOct(
                        QString::number( std::stod( num1 ) + std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // subtraction
                case 1: {
                    ui->resLine->setText( QString::fromStdString( decToOct(
                        QString::number( std::stod( num1 ) - std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // multiplication
                case 2: {
                    ui->resLine->setText( QString::fromStdString( decToOct(
                        QString::number( std::stod( num1 ) * std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // dividing
                default: {
                    // exception handling for divide by 0
                    if ( std::stod( num2 ) == 0.0 ) {
                        ui->resLine->setText( "NaN" );
                        break;
                    }
                    ui->resLine->setText( QString::fromStdString( decToOct(
                        QString::number( std::stod( num1 ) / std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
            }
            break;
        }
        // decimal
        case 2: {
            switch ( ui->operationCombo->currentIndex() ) {
                // addition
                case 0: {
                    ui->resLine->setText( QString::fromStdString(
                        QString::number( std::stod( num1 ) + std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) );
                    break;
                }
                // subtraction
                case 1: {
                    ui->resLine->setText( QString::fromStdString(
                        QString::number( std::stod( num1 ) - std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) );
                    break;
                }
                // multiplication
                case 2: {
                    ui->resLine->setText( QString::fromStdString(
                        QString::number( std::stod( num1 ) * std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) );
                    break;
                }
                // dividing
                default: {
                    // exception handling for divide by 0
                    if ( std::stod( num2 ) == 0.0 ) {
                        ui->resLine->setText( "NaN" );
                        break;
                    }
                    ui->resLine->setText( QString::fromStdString(
                        QString::number( std::stod( num1 ) / std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) );
                    break;
                }
            }
            break;
        }
            // hexadecimal
        default: {
            switch ( ui->operationCombo->currentIndex() ) {
                // addition
                case 0: {
                    ui->resLine->setText( QString::fromStdString( decToHex(
                        QString::number( std::stod( num1 ) + std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // subtraction
                case 1: {
                    ui->resLine->setText( QString::fromStdString( decToHex(
                        QString::number( std::stod( num1 ) - std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // multiplication
                case 2: {
                    ui->resLine->setText( QString::fromStdString( decToHex(
                        QString::number( std::stod( num1 ) * std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
                // dividing
                default: {
                    // exception handling for divide by 0
                    if ( std::stod( num2 ) == 0.0 ) {
                        ui->resLine->setText( "NaN" );
                        break;
                    }
                    ui->resLine->setText( QString::fromStdString( decToHex(
                        QString::number( std::stod( num1 ) / std::stod( num2 ),
                                         'f', 14 )
                            .toStdString() ) ) );
                    break;
                }
            }
            break;
        }
    }
}
