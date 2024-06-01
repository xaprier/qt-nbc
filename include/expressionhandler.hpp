#ifndef EXPRESSION_HANDLER_HPP
#define EXPRESSION_HANDLER_HPP

#include <QDebug>
#include <QLineEdit>
#include <QObject>
#include <QRegExpValidator>

class ExpressionHandler : public QObject {
    Q_OBJECT
  public:
    ExpressionHandler(QLineEdit *edit, QObject *parent = nullptr);
    ~ExpressionHandler();

  private:
    QRegExpValidator *m_validator;
    QLineEdit *m_edit;
};

#endif  // EXPRESSION_HANDLER_HPP