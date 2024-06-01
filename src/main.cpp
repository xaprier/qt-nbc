#include <QApplication>
#include <ios>

#include "choose.hpp"
#include "expressioncalculator.hpp"
#include "nbcalculator.hpp"

int main(int argc, char* argv[]) {
    // Tokenizer lexer("o13.5 + 23.73");  // 11.625
    // lexer.tokenize();
    // Parser parser(lexer.getTokens());
    // auto res = parser.getPostfix();
    // AST<double> tree;
    // tree.build(parser.getPostfix());
    // std::cout << "result : " << tree.evaluate() << std::endl;
    // ExpressionCalculator c("0d125 * -1 + (0d13. * b1000111.1001)");  // -125 + (13 * 71.5625)
    // std::cout << std::boolalpha;
    // std::string result = c;
    // bool valid = c;
    // std::cout << "result : " << result << std::endl;
    // std::cout << "valid : " << valid << std::endl;

    QApplication a(argc, argv);
    NBCalculator calc;
    calc.show();
    // choose c;
    // c.show();
    return QApplication::exec();
}
