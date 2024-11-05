#include "MainWindow.hpp"

#include <qaction.h>
#include <qboxlayout.h>
#include <qgroupbox.h>

#include "AboutDialog.hpp"
#include "NBCalculator.hpp"
#include "NBConverter.hpp"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), m_ui(new Ui::MainWindow), m_Converter(new NBConverter), m_Calculator(new NBCalculator) {
    m_ui->setupUi(this);
    auto* layout = new QHBoxLayout;  // Create the horizontal layout

    auto* boxCalculator = new QGroupBox("Number Based Calculator");
    auto* boxConverter = new QGroupBox("Number Based Converter");

    auto* calculatorLayout = new QVBoxLayout;
    calculatorLayout->addWidget(m_Calculator);
    calculatorLayout->addStretch(1);
    boxCalculator->setLayout(calculatorLayout);
    auto* converterLayout = new QVBoxLayout;
    converterLayout->addWidget(m_Converter);
    converterLayout->addStretch(1);
    boxConverter->setLayout(converterLayout);

    // Set minimum sizes for the calculator and converter widgets
    boxCalculator->setMinimumSize(420, 250);  // Minimum width: 300px, Minimum height: 200px
    boxConverter->setMinimumSize(420, 250);   // Minimum width: 300px, Minimum height: 200px

    layout->addWidget(boxCalculator);  // Add the calculator box
    layout->addWidget(boxConverter);   // Add the converter box

    auto* centralWidget = new QWidget(this);  // Create a central widget
    centralWidget->setLayout(layout);         // Set the layout on the central widget
    setCentralWidget(centralWidget);          // Set the central widget for QMainWindow

    connect(this->m_ui->actionAbout, &QAction::triggered, this, &MainWindow::sl_ActionAboutTriggered);
}

MainWindow::~MainWindow() {
    delete m_ui;
}

void MainWindow::sl_ActionAboutTriggered(bool checked) {
    AboutDialog dialog;
    dialog.exec();
}
