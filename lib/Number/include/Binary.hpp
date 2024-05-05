#ifndef BINARY_H
#define BINARY_H

#include <iostream>

#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "Octal.hpp"

class Binary : public BaseClass {
  public:
    /**
     * @brief Construct a new Binary object from a string(std::string must be formatted as "0b...")
     * @param num The number(std::string) with based Binary
     */
    explicit Binary(std::string num = "0b0.0");

    /**
     * @brief Construct a new Binary object from a integer(int must be represented as decimal value of binary)
     * @param num The number(int) with based decimal
     */
    explicit Binary(const int &num);

    /**
     * @brief Construct a new Binary object from a double(double must be represented as decimal value of binary)
     * @param num The number(double) with based decimal
     */
    explicit Binary(const double &num);

    /**
     * @brief Construct a new Binary object from an Octal object
     * @param o The number with Octal object
     */
    explicit Binary(const Octal &o);

    /**
     * @brief Construct a new Binary object from a Decimal object
     * @param d The number with Decimal object
     */
    explicit Binary(const Decimal &d);

    /**
     * @brief Construct a new Binary object from a Hexadecimal object
     * @param h The number with Hexadecimal object
     */
    explicit Binary(const Hexadecimal &h);

    /**
     * @brief Construct a new Binary object from another Binary object(copy constructor)
     * @param b The number with Binary object
     */
    Binary(const Binary &b);

    /**
     * @brief Returns the Octal object with converting the current based number to Octal
     * @return Octal
     */
    [[nodiscard]] Octal toOct() const override;

    /**
     * @brief Returns the Decimal object with converting the current based number to Decimal
     * @return Decimal
     */
    [[nodiscard]] Decimal toDec() const override;

    /**
     * @brief Returns the Binary object with converting the current based number to Binary
     * @return Binary
     */
    [[nodiscard]] Binary toBin() const override;

    /**
     * @brief Returns the Hexadecimal object with converting the current based number to Hexadecimal
     * @return Hexadecimal
     */
    [[nodiscard]] Hexadecimal toHex() const override;

    /**
     * @brief Returns the number as a string
     * @return std::string
     */
    explicit operator std::string() override;

    /**
     * @brief std::ostream operator overloading for printing the number
     * @return std::ostream
     */
    friend std::ostream &operator<<(std::ostream &output, const Binary &b);

    /**
     * @brief operator overloading of addition with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary operator+(const Binary &b);

    /**
     * @brief operator overloading of addition with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary operator+(const Octal &o);

    /**
     * @brief operator overloading of addition with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary operator+(const Decimal &second);

    /**
     * @brief operator overloading of addition with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary operator+(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary operator-(const Binary &b);

    /**
     * @brief operator overloading of subtraction with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary operator-(const Octal &o);

    /**
     * @brief operator overloading of subtraction with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary operator-(const Decimal &second);

    /**
     * @brief operator overloading of subtraction with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary operator-(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary operator*(const Binary &b);

    /**
     * @brief operator overloading of multiplication with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary operator*(const Octal &o);

    /**
     * @brief operator overloading of multiplication with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary operator*(const Decimal &second);

    /**
     * @brief operator overloading of multiplication with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary operator*(const Hexadecimal &h);

    /**
     * @brief operator overloading of division with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary operator/(const Binary &b);

    /**
     * @brief operator overloading of division with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary operator/(const Octal &o);

    /**
     * @brief operator overloading of division with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary operator/(const Decimal &second);

    /**
     * @brief operator overloading of division with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary operator/(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary operator%(const Binary &b);

    /**
     * @brief operator overloading of modulus with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary operator%(const Octal &o);

    /**
     * @brief operator overloading of modulus with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary operator%(const Decimal &second);

    /**
     * @brief operator overloading of modulus with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary operator%(const Hexadecimal &h);

    /**
     * @brief operator overloading of assignment with Binary object(copy assignment)
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator=(const Binary &b);

    /**
     * @brief operator overloading of assignment with Octal object with converting the Octal to Binary
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator=(const Octal &o);

    /**
     * @brief operator overloading of assignment with Decimal object with converting the Decimal to Binary
     * @param d The number with Decimal reference object
     * @return Binary
     */
    Binary &operator=(const Decimal &d);

    /**
     * @brief operator overloading of assignment with Hexadecimal object with converting the Hexadecimal to Binary
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator=(const Hexadecimal &h);

    /**
     * @brief operator overloading of addition assignment with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator+=(const Binary &b);

    /**
     * @brief operator overloading of addition assignment with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator+=(const Octal &o);

    /**
     * @brief operator overloading of addition assignment with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary &operator+=(const Decimal &second);

    /**
     * @brief operator overloading of addition assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator+=(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction assignment with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator-=(const Binary &b);

    /**
     * @brief operator overloading of subtraction assignment with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator-=(const Octal &o);

    /**
     * @brief operator overloading of subtraction assignment with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary &operator-=(const Decimal &d);

    /**
     * @brief operator overloading of subtraction assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator-=(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication assignment with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator*=(const Binary &b);

    /**
     * @brief operator overloading of multiplication assignment with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator*=(const Octal &o);

    /**
     * @brief operator overloading of multiplication assignment with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary &operator*=(const Decimal &d);

    /**
     * @brief operator overloading of multiplication assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator*=(const Hexadecimal &h);

    /**
     * @brief operator overloading of division assignment with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator/=(const Binary &b);

    /**
     * @brief operator overloading of division assignment with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator/=(const Octal &o);

    /**
     * @brief operator overloading of division assignment with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary &operator/=(const Decimal &d);

    /**
     * @brief operator overloading of division assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator/=(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus assignment with Binary object
     * @param b The number with Binary reference object
     * @return Binary
     */
    Binary &operator%=(const Binary &b);

    /**
     * @brief operator overloading of modulus assignment with Octal object
     * @param o The number with Octal reference object
     * @return Binary
     */
    Binary &operator%=(const Octal &o);

    /**
     * @brief operator overloading of modulus assignment with Decimal object
     * @param second The number with Decimal reference object
     * @return Binary
     */
    Binary &operator%=(const Decimal &d);

    /**
     * @brief operator overloading of modulus assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Binary
     */
    Binary &operator%=(const Hexadecimal &h);
};

#endif  // BINARY_H
