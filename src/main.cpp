#include <QApplication>

#include "choose.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    choose c;
    c.show();
    return QApplication::exec();
}
