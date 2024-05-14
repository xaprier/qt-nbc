#ifndef PARSER_HPP
#define PARSER_HPP

#include <stack>
#include <vector>

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"
#include "token.hpp"

class Parser {
  public:
    Parser(std::vector<Token> const &v) : tokens(v) {}
    std::vector<Token> getPostfix();  // Dijkstra's Shunting Yard
  private:
    std::vector<Token> tokens;

    bool validSyntax();
    bool isBased(const std::string &num);
    bool validOperator(char c);
    bool validBase(char c);
    Token getConvertedBase(Token &token);
    char getBaseToken(Token &token);
    Token extract(std::stack<Token> &s) {
        Token rv = s.top();
        s.pop();
        return rv;
    }
};

#endif  // PARSER_HPP