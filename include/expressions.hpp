#ifndef EXPRESSIONS_HPP
#define EXPRESSIONS_HPP

#include <QRegularExpression>

const QRegularExpression binExpression("^-?0?b?[0-1]{1,}\\.?[0-1]*$");
const QRegularExpression octExpression("^-?0?o?[0-7]{1,}\\.?[0-7]*$");
const QRegularExpression decExpression("^-?[0-9]{1,}\\.?[0-9]*$");
const QRegularExpression hexExpression("^-?0?x?[0-9A-F]{1,}\\.?[0-9A-F]*$");

#endif  // EXPRESSIONS_HPP
