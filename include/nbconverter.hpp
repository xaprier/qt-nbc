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

  public:
    explicit NBConverter(QWidget *parent = nullptr);

    ~NBConverter() override;

  private slots:

    void textChanged();

  private:
    Ui::NBConverter *ui;
    QValidator *validator;
    Number<Binary> *b;
    Number<Octal> *o;
    Number<Decimal> *d;
    Number<Hexadecimal> *h;
};

#endif  // QT_NBC_NBCONVERTER_H
