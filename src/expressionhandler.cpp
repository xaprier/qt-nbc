#include "expressionhandler.hpp"

#include <qcoreevent.h>
#include <qnamespace.h>
#include <qtooltip.h>
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

    this->m_rx = QRegExp(fullPattern);
    this->m_validator = new QRegExpValidator(m_rx, this);
    this->m_edit->setValidator(this->m_validator);
    this->m_edit->installEventFilter(this);
}

ExpressionHandler::~ExpressionHandler() {
    this->m_edit->setValidator(nullptr);
    this->m_edit->removeEventFilter(this);
    delete this->m_validator;
}

bool ExpressionHandler::eventFilter(QObject *obj, QEvent *event) {
    if (obj == this->m_edit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);

        QString keyText = keyEvent->text();
        QString currentText = this->m_edit->text();
        int cursorPos = this->m_edit->cursorPosition();

        if (keyEvent->key() != Qt::Key_Backspace && keyEvent->key() != Qt::Key_Shift) {
            currentText = this->m_edit->text();
            currentText.insert(cursorPos, keyText);
        }

        int lastIndex = currentText.lastIndexOf(QRegExp("[\\+\\-\\*\\/\\%]"), cursorPos);
        QString lastToken;
        if (lastIndex == -1)
            lastToken = currentText.mid(0, 2).toUpper();
        else
            lastToken = currentText.mid(lastIndex + 1, cursorPos - lastIndex - 1).toUpper();

        auto validEntryList = this->GetValidEntries(lastToken, keyText);

        bool notValid = this->m_rx.indexIn(currentText) > -1;
        if (!notValid) {
            QString list = validEntryList.join(", ");
            list.chop(1);
            QString message = "Invalid Entry!<br/>Valid entries are: <b>" + list + "</b><br/>Valid operators are: <b>+, -, *, /, %</b>";
            QToolTip::showText(this->m_edit->mapToGlobal(QPoint(0, 0)), message, this->m_edit);

            // after a while, hide text
            QTimer::singleShot(3000, []() {
                QToolTip::hideText();
            });
        } else
            QToolTip::hideText();
    }
    return QObject::eventFilter(obj, event);
}

QStringList ExpressionHandler::GetValidEntries(const QString &token, const QString &keyText) {
    QStringList validEntryList;
    if (token.startsWith("0B")) {
        QString chars = ".01";
        validEntryList = chars.split("");  // split each character
    } else if (token.startsWith("0X")) {
        QString chars = ".0123456789ABCDEF";
        validEntryList = chars.split("");  // split each character
    } else if (token.startsWith("0O")) {
        QString chars = ".01234567";
        validEntryList = chars.split("");  // split each character
    } else if (QString("+-*/%").contains(keyText)) {
        QString chars = ".0123456789";
        QString tokens = "0b,0o,0d,0x";
        validEntryList = tokens.split(",");
        validEntryList += chars.split("");  // split each character
    } else {
        QString chars = ".0123456789";
        validEntryList = chars.split("");  // split each character
    }
    validEntryList.erase(validEntryList.begin());

    return validEntryList;
}