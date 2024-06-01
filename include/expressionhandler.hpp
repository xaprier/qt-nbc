#ifndef EXPRESSION_HANDLER_HPP
#define EXPRESSION_HANDLER_HPP

#include <qglobal.h>

#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QRegExpValidator>
#include <QTimer>
#include <QToolTip>

class ExpressionHandler : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(ExpressionHandler)
    Q_DISABLE_MOVE(ExpressionHandler)
  public:
    ExpressionHandler(QLineEdit *edit, QObject *parent = nullptr);
    ~ExpressionHandler();

  protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    virtual QStringList GetValidEntries(const QString &token, const QString &keyText);

  private:
    QRegExp m_rx;
    QRegExpValidator *m_validator;
    QLineEdit *m_edit;
};

#endif  // EXPRESSION_HANDLER_HPP