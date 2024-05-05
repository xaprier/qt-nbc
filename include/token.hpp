#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum class Type : char {
    Number = 'n',
    Addition = '+',
    Subtract = '-',
    Multiply = '*',
    Divide = '/',
    Remainder = '%',
    LeftParantheses = '(',
    RightParantheses = ')',
    Empty = 'e'
};

struct Token {
    Type type;
    std::string value;
    int precedence;
    Token(Type t, std::string v) : type(t), value(v), precedence(0) {
        if (t == Type::Divide || t == Type::Multiply || t == Type::Remainder) precedence = 2;
        if (t == Type::Addition || t == Type::Subtract) precedence = 1;
    }
    bool isOperator() {
        return (type != Type::Number && type != Type::RightParantheses && type != Type::LeftParantheses && type != Type::Empty);
    }
};

#endif