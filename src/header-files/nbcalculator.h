//
// Created by "xaprier" on "10/8/22"
//

#ifndef QT_NBC_NBCALCULATOR_H
#define QT_NBC_NBCALCULATOR_H

#include <QDialog>
#include <QValidator>

#include "nbc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class NBCalculator;
}
QT_END_NAMESPACE

class NBCalculator : public QDialog, public nbc {
    Q_OBJECT

  public:
    explicit NBCalculator(QWidget *parent = nullptr);

    ~NBCalculator() override;

  private slots:
    void hasChanged();
    void calculate(std::string num1, std::string num2);
    void setNumbers(std::string numberToConvert, int indexing,
                    std::string *pointOfNumber);

  private:
    std::string num1, num2;
    Ui::NBCalculator *ui;
    QValidator *validator;
};

#endif  // QT_NBC_NBCALCULATOR_H
