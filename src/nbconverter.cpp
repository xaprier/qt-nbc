#include "nbconverter.hpp"

#include <qobject.h>

#include <memory>

#include "../design/ui_nbconverter.h"
#include "NumberBase.hpp"
#include "expressions.hpp"

NBConverter::NBConverter(QWidget *parent) : QDialog(parent), m_ui(new Ui::NBConverter) {  // NOLINT
    QWidget::setFixedSize(400, 200);                                                      // NOLINT

    this->m_ui->setupUi(this);

    connect(this->m_ui->binLine, &QLineEdit::textEdited, this,
            &NBConverter::sl_textChanged);
    connect(this->m_ui->octLine, &QLineEdit::textEdited, this,
            &NBConverter::sl_textChanged);
    connect(this->m_ui->decLine, &QLineEdit::textEdited, this,
            &NBConverter::sl_textChanged);
    connect(this->m_ui->hexaLine, &QLineEdit::textEdited, this,
            &NBConverter::sl_textChanged);
    connect(this->m_ui->exitBut, &QPushButton::clicked, this, &NBConverter::close);

    m_lineEdits.push_back(this->m_ui->binLine);
    m_lineEdits.push_back(this->m_ui->decLine);
    m_lineEdits.push_back(this->m_ui->octLine);
    m_lineEdits.push_back(this->m_ui->hexaLine);

    this->m_setupValidator();
}

NBConverter::~NBConverter() {
    delete m_ui;
}

void NBConverter::sl_textChanged() {
    // disable signals
    for (auto *line : this->m_lineEdits) {
        line->blockSignals(true);
    }

    QString bin = this->m_ui->binLine->text(), oct = this->m_ui->octLine->text(), dec = this->m_ui->decLine->text(), hex = this->m_ui->hexaLine->text();
    std::shared_ptr<NumberBase> number;
    auto sender = QObject::sender();
    if (sender == this->m_ui->binLine) {
        number = std::make_shared<Binary>(bin.toStdString());
    } else if (sender == this->m_ui->octLine) {
        number = std::make_shared<Octal>(oct.toStdString());
    } else if (sender == this->m_ui->decLine) {
        number = std::make_shared<Decimal>(dec.toStdString());
    } else if (sender == this->m_ui->hexaLine) {
        number = std::make_shared<Hexadecimal>(hex.toStdString());
    }

    // we shall not set the sender text.
    if (sender != this->m_ui->binLine) {
        this->m_ui->binLine->setText(QString::fromStdString(number->toBin().getNum()));
    }
    if (sender != this->m_ui->octLine) {
        this->m_ui->octLine->setText(QString::fromStdString(number->toOct().getNum()));
    }
    if (sender != this->m_ui->decLine) {
        this->m_ui->decLine->setText(QString::fromStdString(number->toDec().getNum()));
    }
    if (sender != this->m_ui->hexaLine) {
        this->m_ui->hexaLine->setText(QString::fromStdString(number->toHex().getNum()));
    }

    // enable signals back
    for (auto *line : this->m_lineEdits) {
        line->blockSignals(false);
    }
}

void NBConverter::m_setupValidator() {
    this->m_ui->binLine->setValidator(new QRegularExpressionValidator(binExpression));   // NOLINT
    this->m_ui->octLine->setValidator(new QRegularExpressionValidator(octExpression));   // NOLINT
    this->m_ui->decLine->setValidator(new QRegularExpressionValidator(decExpression));   // NOLINT
    this->m_ui->hexaLine->setValidator(new QRegularExpressionValidator(hexExpression));  // NOLINT
}
