#ifndef DECIMAL_HPP
#define DECIMAL_HPP

#include <iostream>

#include "NumberBase.hpp"

class Decimal : public NumberBase {
  public:
    /**
     * @brief Construct a new Decimal object from a string(std::string must be formatted as "0.0")
     * @param num The number(std::string) with based Decimal
     */
    explicit Decimal(std::string num = "0.0");

    /**
     * @brief Construct a new Decimal object from integer number
     * @param num The number(int) with based Decimal
     */
    explicit Decimal(const int &num);

    /**
     * @brief Construct a new Decimal object from double number
     * @param num The number(double) with based Decimal
     */
    explicit Decimal(const double &num);

    /**
     * @brief Construct a new Decimal object from a Octal object
     * @param o The Octal object
     */
    explicit Decimal(const Octal &o);

    /**
     * @brief Construct a new Decimal object from a Binary object
     * @param b The Binary object
     */
    explicit Decimal(const Binary &b);

    /**
     * @brief Construct a new Decimal object from a Hexadecimal object
     * @param h The Hexadecimal object
     */
    explicit Decimal(const Hexadecimal &h);

    /**
     * @brief Construct a new Decimal object from another Decimal object(copy constructor)
     * @param d The number with Decimal object
     */
    Decimal(const Decimal &d);

    /**
     * @brief Returns the Octal object with converting the current based number to Octal
     * @return Octal object
     */
    [[nodiscard]] Octal toOct() const override;

    /**
     * @brief Returns the Decimal object with converting the current based number to Decimal
     * @return Decimal object
     */
    [[nodiscard]] Decimal toDec() const override;

    /**
     * @brief Returns the Binary object with converting the current based number to Binary
     * @return Decimal object
     */
    [[nodiscard]] Binary toBin() const override;

    /**
     * @brief Returns the Hexadecimal object with converting the current based number to Hexadecimal
     * @return Hexadecimal object
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
    friend std::ostream &operator<<(std::ostream &output, const Decimal &d);

    /**
     * @brief operator overloading of addition with another number base
     *
     * @param other another number base
     * @return Decimal
     */
    Decimal operator+(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction with another number base
     *
     * @param other another number base
     * @return Decimal
     */
    Decimal operator-(const NumberBase &other);

    /**
     * @brief operator overloading of multiply with another number base
     *
     * @param other another number base
     * @return Decimal
     */
    Decimal operator*(const NumberBase &other);

    /**
     * @brief operator overloading of divide with another number base
     *
     * @param other another number base
     * @return Decimal
     */
    Decimal operator/(const NumberBase &other);

    /**
     * @brief operator overloading of modulo with another number base
     *
     * @param other another number base
     * @return Decimal
     */
    Decimal operator%(const NumberBase &other);

    /**
     * @brief operator overloading of assignment with another number base
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator=(const NumberBase &other);

    /**
     * @brief operator overloading of addition assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator+=(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator-=(const NumberBase &other);

    /**
     * @brief operator overloading of multiply assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator*=(const NumberBase &other);

    /**
     * @brief operator overloading of divide assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator/=(const NumberBase &other);

    /**
     * @brief operator overloading of modulo assignment with another number base object
     * @param other The number with another NumberBase reference object
     * @return Decimal
     */
    Decimal &operator%=(const NumberBase &other);
};

#endif  // DECIMAL_HPP
