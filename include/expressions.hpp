#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP

#include <QRegularExpression>

QRegularExpression binExpression("^-?0?b?[0-1]{1,}\\.?[0-1]*$");
QRegularExpression octExpression("^-?0?o?[0-7]{1,}\\.?[0-7]*$");
QRegularExpression decExpression("^-?[0-9]{1,}\\.?[0-9]*$");
QRegularExpression hexExpression("^-?0?x?[0-9A-F]{1,}\\.?[0-9A-F]*$");

#endif  // EXPRESSIONS_HPP
