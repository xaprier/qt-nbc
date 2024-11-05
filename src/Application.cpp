#include "Application.hpp"

#include <qtranslator.h>

QTranslator Application::translator = QTranslator();

Application::Application(int &argc, char **argv, const QString &appName, const QString &appVersion, const QString &appOrg, const QString &appStyle)
    : QApplication(argc, argv) {
    this->SetApplicationName(appName);
    this->SetApplicationVersion(appVersion);
    this->SetOrganizationName(appOrg);
    this->SetStyleSheet(appStyle);
    this->_SetAppIcon();
}

Application::~Application() {
}

void Application::SetApplicationName(const QString &name) {
    m_applicationName = name;
    QApplication::setApplicationName(name);
}

void Application::SetApplicationVersion(const QString &version) {
    m_applicationVersion = version;
    QApplication::setApplicationVersion(version);
}

void Application::SetOrganizationName(const QString &name) {
    m_organizationName = name;
    QApplication::setOrganizationName(name);
}

void Application::SetStyleSheet(const QString &sheet) {
    m_styleSheet = sheet;
    QApplication::setStyleSheet(sheet);
}

void Application::_SetAppIcon() {
    setWindowIcon(QIcon(":/icons/XNBC.svg"));
}