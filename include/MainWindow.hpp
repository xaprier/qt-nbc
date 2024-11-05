#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QGroupBox>
#include <QHBoxLayout>
#include <QMainWindow>

#include "../design/ui_MainWindow.h"
#include "NBCalculator.hpp"
#include "NBConverter.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private slots:
    void sl_ActionAboutTriggered(bool checked);

  private:
    Ui::MainWindow* m_ui;
    NBCalculator* m_Calculator;
    NBConverter* m_Converter;
};

#endif  // MAINWINDOW_HPP
