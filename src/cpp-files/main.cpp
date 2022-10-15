#include <QApplication>

#include "../header-files/choose.h"
#include "../header-files/nbcalculator.h"
#include "../header-files/nbconverter.h"

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );
    choose c;
    c.show();
    return QApplication::exec();
}
