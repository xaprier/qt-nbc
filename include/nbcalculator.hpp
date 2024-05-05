//
// Created by "xaprier" on "10/8/22"
//

#ifndef nbcalculator_h
#define nbcalculator_h

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QValidator>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Number.hpp"
#include "Octal.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class NBCalculator;
}
QT_END_NAMESPACE

class NBCalculator : public QDialog {
    Q_OBJECT

  public:
    explicit NBCalculator(QWidget *parent = nullptr);

    ~NBCalculator() override;

  private slots:
    void hasChanged();
    void calculate();
    void setNumbers(const std::string &numberToConvert, int indexing,
                    std::string *pointOfNumber);
    void help();

  private:
    std::string num1, num2;
    Ui::NBCalculator *ui;
    QRegularExpressionValidator *validator;
    Number<Binary> *binaryNumber;
    Number<Octal> *octalNumber;
    Number<Decimal> *decimalNumber;
    Number<Hexadecimal> *hexadecimalNumber;
};

#endif  // nbcalculator_h
