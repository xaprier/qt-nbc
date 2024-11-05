

#ifndef NBCONVERTER_HPP
#define NBCONVERTER_HPP

#include <qglobal.h>

#include <QComboBox>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QValidator>

#include "../design/ui_NBConverter.h"
#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Number.hpp"
#include "Octal.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class NBConverter;
}
QT_END_NAMESPACE

class NBConverter : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(NBConverter)

  public:
    explicit NBConverter(QWidget *parent = nullptr);
    ~NBConverter() override;

  private slots:
    void sl_textChanged();

  private:
    void m_setupValidator();

  private:
    Ui::NBConverter *m_ui;
    QList<QLineEdit *> m_lineEdits;
    QValidator *m_validator;
};

#endif  // NBCONVERTER_HPP
