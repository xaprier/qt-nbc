#ifndef BINARY_HPP
#define BINARY_HPP

#include <iostream>

#include "NumberBase.hpp"

class Binary : public NumberBase {
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
     * @brief Construct a new Binary object from another NumberBase object
     * @param other The other NumberBase
     */
    explicit Binary(const NumberBase &other);

    /**
     * @brief Construct a new Binary object from a Decimal object
     * @param d The number with Decimal object
     */
    explicit Binary(const Decimal &d);

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
     * @brief operator overloading of addition with another number base
     *
     * @param other another number base
     * @return Binary
     */
    Binary operator+(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction with another number base
     *
     * @param other another number base
     * @return Binary
     */
    Binary operator-(const NumberBase &other);

    /**
     * @brief operator overloading of multiply with another number base
     *
     * @param other another number base
     * @return Binary
     */
    Binary operator*(const NumberBase &other);

    /**
     * @brief operator overloading of divide with another number base
     *
     * @param other another number base
     * @return Binary
     */
    Binary operator/(const NumberBase &other);

    /**
     * @brief operator overloading of modulo with another number base
     *
     * @param other another number base
     * @return Binary
     */
    Binary operator%(const NumberBase &other);

    /**
     * @brief operator overloading of assignment with another number base
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator=(const NumberBase &other);

    /**
     * @brief operator overloading of addition assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator+=(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator-=(const NumberBase &other);

    /**
     * @brief operator overloading of multiply assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator*=(const NumberBase &other);

    /**
     * @brief operator overloading of divide assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator/=(const NumberBase &other);

    /**
     * @brief operator overloading of modulo assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Binary
     */
    Binary &operator%=(const NumberBase &other);
};

#endif  // BINARY_HPP
