#include "Application.hpp"
#include "Config.hpp"
#include "MainWindow.hpp"

QString getQSS() {
    QFile styleFile(":/qss/style.qss");
    if (!styleFile.open(QFile::ReadOnly)) {
        return QString();
    }

    QString style(styleFile.readAll());
    return style;
}

int main(int argc, char* argv[]) {
    Application app(argc, argv, PROJECT_NAME, PROJECT_VERSION, PROJECT_ORGANIZATION, getQSS());
    MainWindow c;
    c.show();
    return app.exec();
}
