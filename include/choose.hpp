//
// Created by "xaprier" on "10/8/22"
//

#ifndef QT_NBC_CHOOSE_H
#define QT_NBC_CHOOSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class choose;
}
QT_END_NAMESPACE

class choose : public QMainWindow {
    Q_OBJECT

  public:
    explicit choose(QWidget *parent = nullptr);

    ~choose() override;

  private slots:

    void onPushButton_clicked();

  private:
    Ui::choose *ui;
};

#endif  // QT_NBC_CHOOSE_H
