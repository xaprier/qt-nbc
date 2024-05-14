#ifndef ASTNODE_HPP
#define ASTNODE_HPP

#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "token.hpp"

template <class T>
class AST {
  public:
    AST() : token(Token(Type::Empty, "")), value(0), left(nullptr), right(nullptr) {}
    AST(Token t) : token(t), value(0), left(nullptr), right(nullptr) {}
    void print() {
        printAST(std::shared_ptr<AST<T>>(this));
        std::cout << std::endl;
    }
    void build(std::vector<Token> postfix);  // Notice how I make a copy of tokens and then pass that copy by reference. This way the original vector<Token> stays unchanged while the
                                             // algorithm proceeds normally.
    T evaluate();

  private:
    Token token;
    T value;
    std::shared_ptr<AST<T>> left;
    std::shared_ptr<AST<T>> right;

    bool isFull() { return (left != nullptr && right != nullptr); }
    void populate(std::shared_ptr<AST<T>> n, std::shared_ptr<AST<T>> m);
    void printAST(std::shared_ptr<AST<T>> n);
    T toNumber(std::string str);
    std::shared_ptr<AST<T>> buildAST(std::vector<Token> &postfix);
};

template <class T>
void AST<T>::populate(std::shared_ptr<AST<T>> n, std::shared_ptr<AST<T>> m) {
    if (n->right == nullptr)
        n->right = m;
    else if (n->left == nullptr)
        n->left = m;
    else
        throw std::runtime_error("Node is full. Cannot add child");  // Hopefully this should never happen
}

template <class T>
void AST<T>::printAST(std::shared_ptr<AST<T>> n) {
    if (n->left != nullptr && n->right != nullptr) std::cout << '(';
    if (n->left != nullptr) printAST(n->left);
    std::cout << n->token.value;
    if (n->right != nullptr) printAST(n->right);
    if (n->left != nullptr && n->right != nullptr) std::cout << ')';
}

template <class T>
void AST<T>::build(std::vector<Token> postfix) {
    std::shared_ptr<AST<T>> n = buildAST(postfix);
    this->token = n->token;
    this->right = n->right;
    this->left = n->left;
}

template <class T>
std::shared_ptr<AST<T>> AST<T>::buildAST(std::vector<Token> &postfix) {
    std::shared_ptr<AST<T>> root(new AST<T>(postfix.back()));
    postfix.pop_back();
    while (!postfix.empty()) {
        if (postfix.back().isOperator())
            populate(root, buildAST(postfix));
        else {
            populate(root, std::shared_ptr<AST<T>>(new AST<T>(postfix.back())));
            postfix.pop_back();
        }
        if (root->isFull())
            return root;
    }
    return root;
}

template <class T>
T AST<T>::toNumber(std::string str) {
    std::stringstream ss(str);
    T rv;
    ss >> rv;
    if (ss.fail())
        throw std::runtime_error("Conversion from string to number failed. Check the data type of the AST.");
    return rv;
}

template <class T>
T AST<T>::evaluate() {
    if (token.type == Type::Number) return toNumber(token.value);
    if (token.type == Type::Empty) return 0;
    switch (token.type) {
        // Order is important; left->eval() - right->eval != right->eval() - left->eval()
        case Type::Addition:
            return left->evaluate() + right->evaluate();
        case Type::Subtract:
            return left->evaluate() - right->evaluate();
        case Type::Multiply:
            return left->evaluate() * right->evaluate();
        case Type::Divide:
            return left->evaluate() / right->evaluate();
        case Type::Remainder:
            if constexpr (std::is_same_v<T, double>)
                return fmod(left->evaluate(), right->evaluate());
            else
                return static_cast<int>(left->evaluate()) % static_cast<int>(right->evaluate());
        default:
            throw std::runtime_error("A node with children can only be an operator");
    }
    return 0;  // is either an empty node or paretheses ( although it this should never be the case if the syntax is correct )
}

#endif