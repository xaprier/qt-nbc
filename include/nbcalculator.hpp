//
// Created by "xaprier" on "10/8/22"
//

#ifndef nbcalculator_h
#define nbcalculator_h

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QValidator>

#include "expressionhandler.hpp"

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
    void sl_help();
    // void sl_operationChanged();
    void sl_returnPressed();
    void sl_wrongCharClicked();

  signals:
    void si_returnPressed();     // todo: if enter clicked last result will be in operation
    void si_wrongCharClicked();  // todo: if wrong characted clicked, there will be popup.

  private:
    void updateResult();
    Ui::NBCalculator *ui;
    QRegularExpressionValidator *validator;
    ExpressionHandler *handler;
};

#endif  // nbcalculator_h
