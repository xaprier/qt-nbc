#include "expressionhandler.hpp"

#include <qlineedit.h>
#include <qobject.h>
#include <qregexp.h>
#include <qregularexpression.h>
#include <qvalidator.h>

ExpressionHandler::ExpressionHandler(QLineEdit *edit, QObject *parent) : QObject(parent), m_edit(edit) {
    QString decimalPattern = "-?(?:0d|d)?[0-9]+(?:\\.[0-9]*)?";
    QString octalPattern = "-?(?:0o|o)?[0-7]+(?:\\.[0-7]*)?";
    QString binaryPattern = "-?(?:0b|b)?[01]+(?:\\.[01]*)?";
    QString hexadecimalPattern = "-?(?:0x|x)?[0-9A-F]+(?:\\.[0-9A-F]*)?";  // we cant let lowercase a-f because of 0b 0d
    QString operatorPattern = "[\\+\\-\\*\\/\\%]";
    QString fullPattern = QString(
                              "^(%1|%2|%3|%4)"
                              "(?:%5(%1|%2|%3|%4))*$")
                              .arg(decimalPattern, octalPattern, binaryPattern, hexadecimalPattern, operatorPattern);

    QRegExp rx(fullPattern);
    m_validator = new QRegExpValidator(rx, this);
    m_edit->setValidator(m_validator);
}

ExpressionHandler::~ExpressionHandler() {
    m_edit->setValidator(nullptr);
    delete m_validator;
}
