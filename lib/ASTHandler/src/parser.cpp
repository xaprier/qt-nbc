#include "parser.hpp"

#include <cctype>
#include <stdexcept>

#include "Hexadecimal.hpp"

bool Parser::validBase(char c) {
    std::string bases = "bodx";
    for (char i : bases)
        if (std::tolower(i) == std::tolower(c)) return true;
    return false;
}

bool Parser::validOperator(char c) {
    std::string operators = "+-*/%()";
    for (char i : operators)
        if (i == c) return true;
    return false;
}

bool Parser::isBased(const std::string& num) {
    bool firstToken = validBase(num[0]);
    bool secondToken = validBase(num[1]);
    return firstToken || secondToken;
}

char Parser::getBaseToken(Token& token) {
    const std::string num = token.value;
    bool firstToken = validBase(num[0]);
    bool secondToken = validBase(num[1]);
    if (firstToken) return char(std::tolower(num[0]));
    if (secondToken) return char(std::tolower(num[1]));
    return 'd';
}

// There is probably a better way to check the syntax but I am not aware of it.
bool Parser::validSyntax() {
    int openPar = 0;
    bool operation = false;
    if (tokens.size() > 0 && tokens[0].isOperator()) return false;
    for (unsigned i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == Type::Empty) continue;
        if (tokens[i].isOperator())
            if (operation)
                return false;
            else
                operation = true;
        else if (tokens[i].type != Type::RightParantheses)
            operation = false;
        if (i > 0 && tokens[i].type == Type::Number && tokens[i - 1].type == Type::Number) return false;
        if (tokens[i].type == Type::LeftParantheses && i > 0 && tokens[i - 1].type == Type::Number) return false;  // e.g 5(2 * 3)
        if (tokens[i].type == Type::LeftParantheses) openPar++;
        if (tokens[i].type == Type::RightParantheses) openPar--;
        if (openPar < 0) return false;
    }
    return (openPar == 0 && operation == false);
}

Token Parser::getConvertedBase(Token& token) {
    // get base token
    char base = getBaseToken(token);
    switch (base) {
        case 'b':
            return Token(Type::Number, std::string(Decimal(Binary(token.value))));
        case 'o':
            return Token(Type::Number, std::string(Decimal(Octal(token.value))));
        case 'd':
            return Token(Type::Number, std::string(Decimal(Decimal(token.value))));
        case 'x':
            return Token(Type::Number, std::string(Decimal(Hexadecimal(token.value))));
    }

    return Token(Type::Number, "0.0");
}

std::vector<Token> Parser::getPostfix() {
    if (!validSyntax())
        throw std::runtime_error("Invalid Syntax");
    // The following code assumes valid syntax
    std::vector<Token> rv;
    std::stack<Token> ops;
    for (unsigned i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == Type::Empty) continue;
        if (tokens[i].type == Type::Number) {
            if (this->isBased(tokens[i].value))
                rv.push_back(getConvertedBase(tokens[i]));
            else
                rv.push_back(tokens[i]);
        } else if (tokens[i].type == Type::LeftParantheses) {
            ops.push(tokens[i]);
            if (i < tokens.size() - 1 && (tokens[i + 1].type == Type::Addition || tokens[i + 1].type == Type::Subtract)) rv.push_back(Token(Type::Number, "0"));  // Allow for negative numbers ( eg. 8*(-1) )
        } else if (tokens[i].type == Type::RightParantheses) {
            while (ops.top().type != Type::LeftParantheses)
                rv.push_back(extract(ops));
            ops.pop();
        } else {
            while (!ops.empty() && ops.top().precedence >= tokens[i].precedence)
                rv.push_back(extract(ops));
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty())
        rv.push_back(extract(ops));
    return rv;
}