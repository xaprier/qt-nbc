#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "token.hpp"

class Tokenizer {
  public:
    Tokenizer(std::string const &str) : stream(str) {}
    void tokenize();
    std::vector<Token> getTokens() { return tokens; }

  private:
    std::istringstream stream;
    std::vector<Token> tokens;

    std::string getNumber();
    bool validOperator(char c);
    bool validBase(char c);
    bool validHexaNum(char c);
};

#endif  // TOKENIZER_HPP