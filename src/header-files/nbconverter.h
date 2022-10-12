#include <QDialog>
#include <QValidator>

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

	explicit NBConverter( QWidget *parent = nullptr );

	~NBConverter() override;

  private slots:

	void comboChanged();

	void baseChanged();

  private:
	Ui::NBConverter *ui;

	QValidator *validator;
};

#endif  // QT_NBC_NBCONVERTER_H
