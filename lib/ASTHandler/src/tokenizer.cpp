#include "tokenizer.hpp"

#include <algorithm>
#include <cctype>
#include <stdexcept>

bool Tokenizer::validOperator(char c) {
    std::string operators = "+-*/%()";
    return std::find(operators.begin(), operators.end(), c) != operators.end();
}

bool Tokenizer::validBase(char c) {
    std::string bases = "bodx";
    return std::find(bases.begin(), bases.end(), std::tolower(c)) != bases.end();
}

std::string Tokenizer::getNumber() {
    std::string rv;
    bool decimal = false;
    bool base = false;      // Flag to detect base prefix
    bool negative = false;  // Flag to detect negative numbers
    char base_c = '0';
    char c;
    while (stream.good()) {
        c = stream.peek();
        if (c != '.' && !isdigit(c) && !validBase(c) && c != '-') break;
        c = stream.get();
        if (c == '.') {
            if (decimal)
                throw std::runtime_error("Multiple dots on number");
            else
                decimal = true;
            rv += c;
        } else if (validBase(c)) {
            if (base && std::tolower(c) == std::tolower(base_c))
                throw std::runtime_error("Multiple base prefixes on number");
            else {
                base_c = c;
                base = true;
            }
            rv += c;
        } else if (c == '-') {
            if (negative)
                throw std::runtime_error("Multiple negative signs on number");
            else {
                negative = true;
                rv += c;
            }
        } else {
            rv += c;
        }
    }
    return rv;
}

void Tokenizer::tokenize() {
    char c = stream.peek();  // This is important ( check note at the bottom)
    while (stream.good()) {
        if (isdigit(c) || c == '.' || this->validBase(c) || c == '-') {
            std::string num = this->getNumber();
            if (!num.empty()) {
                tokens.push_back(Token(Type::Number, num));
            } else {
                throw std::runtime_error("Invalid number format");
            }
        } else {
            stream.get(c);
            if (isspace(c))
                while (stream.good() && isspace(stream.peek())) stream.get();
            else if (this->validOperator(c))
                tokens.push_back(Token(static_cast<Type>(c), {c}));
            else
                throw std::runtime_error("Invalid character");
        }
        c = stream.peek();  // Important!
        // from cppreference: std::basic_ios::good: Returns true if the THE MOST recent I/O operation on the stream completed successfully.
        // Thus if peek() fails the loop will stop. If I didn't have peek() at the end then the last operation would be a successful get()
        // as a result good() would return true despite now being at eof().
    }
}