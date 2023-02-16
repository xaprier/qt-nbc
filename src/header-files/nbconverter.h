#include <QDialog>
#include <QValidator>

#include "nbc.h"
#include "header-files/Number/Number.h"

#ifndef QT_NBC_NBCONVERTER_H
#define QT_NBC_NBCONVERTER_H
QT_BEGIN_NAMESPACE
namespace Ui {
class NBConverter;
}
QT_END_NAMESPACE

class NBConverter : public QDialog, public nbc {
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
