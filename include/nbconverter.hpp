#include <qglobal.h>

#include <QComboBox>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QValidator>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Number.hpp"
#include "Octal.hpp"

#ifndef QT_NBC_NBCONVERTER_H
#define QT_NBC_NBCONVERTER_H
QT_BEGIN_NAMESPACE
namespace Ui {
class NBConverter;
}
QT_END_NAMESPACE

class NBConverter : public QDialog {
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

#endif  // QT_NBC_NBCONVERTER_H
