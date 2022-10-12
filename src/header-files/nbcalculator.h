//
// Created by "xaprier" on "10/8/22"
//

#ifndef QT_NBC_NBCALCULATOR_H
#define QT_NBC_NBCALCULATOR_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class NBCalculator; }
QT_END_NAMESPACE

class NBCalculator : public QDialog {
  Q_OBJECT

  public:
	explicit NBCalculator( QWidget *parent = nullptr );

	~NBCalculator() override;

  private:
	Ui::NBCalculator *ui;
};


#endif //QT_NBC_NBCALCULATOR_H
