#include <QApplication>

#include "astnode.hpp"
#include "choose.hpp"
#include "expressioncalculator.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"

int main(int argc, char* argv[]) {
    Tokenizer lexer("0o13.5 + 23.73");  // 11.625
    lexer.tokenize();
    Parser parser(lexer.getTokens());
    auto res = parser.getPostfix();
    AST<double> tree;
    tree.build(parser.getPostfix());
    std::cout << "res : " << tree.evaluate() << std::endl;
    return 0;
    ExpressionCalculator c("o125 + 0d13 * b1000111.1001");
    std::cout << "valid: " << c.isExpressionValid() << '\n';
    std::cout << "result: " << (double)c << std::endl;
    // QApplication a(argc, argv);
    // choose c;
    // c.show();
    // return QApplication::exec();
}
