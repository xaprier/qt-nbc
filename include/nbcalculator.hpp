//
// Created by "xaprier" on "10/8/22"
//

#ifndef nbcalculator_h
#define nbcalculator_h

#include <qglobal.h>

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QValidator>

#include "Number.hpp"
#include "NumberBase.hpp"
#include "expressionhandler.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class NBCalculator;
}
QT_END_NAMESPACE

class NBCalculator : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(NBCalculator)
  public:
    explicit NBCalculator(QWidget *parent = nullptr);
    ~NBCalculator() override;

  private slots:
    void sl_help();
    void sl_returnPressed();
    void sl_textChanged(const QString &text);
    void sl_currentTextChanged(const QString &text);

  private:
    std::string m_evaluateExpression(const QString &text, bool &valid) const;
    void m_cleanToString(std::string &str);

  private:
    Ui::NBCalculator *m_ui;
    QRegularExpressionValidator *m_validator;
    Number<Decimal> m_number;
    ExpressionHandler *m_handler;
};

#endif  // nbcalculator_h
