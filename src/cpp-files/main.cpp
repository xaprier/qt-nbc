#include <QApplication>

#include "../header-files/choose.h"
#include "../header-files/nbconverter.h"
#include "../header-files/nbcalculator.h"

int main( int argc, char *argv[] ) {
	QApplication a(argc, argv);
	/*
NBCalculator n;
	n.show();
	NBConverter n;
	n.show();
	 */
	choose c;
	c.show();
	return QApplication::exec();
}
