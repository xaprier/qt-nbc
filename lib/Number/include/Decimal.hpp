#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>

#include "BaseClass.hpp"

class Decimal : public BaseClass {
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
     * @brief Construct a new Decimal object from a Decimal object(Copy constructor)
     * @param d The Decimal object
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
     * @return Binary object
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
     * @brief operator overloading of addition with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal operator+(const Decimal &d);

    /**
     * @brief operator overloading of addition with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal operator+(const Binary &b);

    /**
     * @brief operator overloading of addition with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal operator+(const Octal &o);

    /**
     * @brief operator overloading of addition with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal operator+(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction with Decimal object
     * @param second The number with Decimal reference object
     * @return Decimal object
     */
    Decimal operator-(const Decimal &second);

    /**
     * @brief operator overloading of subtraction with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal operator-(const Binary &b);

    /**
     * @brief operator overloading of subtraction with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal operator-(const Octal &o);

    /**
     * @brief operator overloading of subtraction with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal operator-(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication with Decimal object
     * @param second The number with Decimal reference object
     * @return Decimal object
     */
    Decimal operator*(const Decimal &second);

    /**
     * @brief operator overloading of multiplication with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal operator*(const Binary &b);

    /**
     * @brief operator overloading of multiplication with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal operator*(const Octal &o);

    /**
     * @brief operator overloading of multiplication with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal operator*(const Hexadecimal &h);

    /**
     * @brief operator overloading of division with Decimal object
     * @param second The number with Decimal reference object
     * @return Decimal object
     */
    Decimal operator/(const Decimal &second);

    /**
     * @brief operator overloading of division with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal operator/(const Binary &b);

    /**
     * @brief operator overloading of division with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal operator/(const Octal &o);

    /**
     * @brief operator overloading of division with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal operator/(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus with Decimal object
     * @param second The number with Decimal reference object
     * @return Decimal object
     */
    Decimal operator%(const Decimal &second);

    /**
     * @brief operator overloading of modulus with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal operator%(const Binary &b);

    /**
     * @brief operator overloading of modulus with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal operator%(const Octal &o);

    /**
     * @brief operator overloading of modulus with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal operator%(const Hexadecimal &h);

    /**
     * @brief operator overloading of assignement with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator=(const Decimal &d);

    /**
     * @brief operator overloading of assignement with Binary object(Converts the Base to the Decimal)
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator=(const Binary &b);

    /**
     * @brief operator overloading of assignement with Octal object(Converts the Base to the Decimal)
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator=(const Octal &o);

    /**
     * @brief operator overloading of assignement with Hexadecimal object(Converts the Base to the Decimal)
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator=(const Hexadecimal &h);

    /**
     * @brief operator overloading of addition assignment with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator+=(const Decimal &d);

    /**
     * @brief operator overloading of addition assignment with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator+=(const Binary &b);

    /**
     * @brief operator overloading of addition assignment with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator+=(const Octal &o);

    /**
     * @brief operator overloading of addition assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator+=(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction assignment with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator-=(const Decimal &d);

    /**
     * @brief operator overloading of subtraction assignment with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator-=(const Binary &b);

    /**
     * @brief operator overloading of subtraction assignment with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator-=(const Octal &o);

    /**
     * @brief operator overloading of subtraction assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator-=(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication assignment with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator*=(const Decimal &d);

    /**
     * @brief operator overloading of multiplication assignment with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator*=(const Binary &b);

    /**
     * @brief operator overloading of multiplication assignment with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator*=(const Octal &o);

    /**
     * @brief operator overloading of multiplication assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator*=(const Hexadecimal &h);

    /**
     * @brief operator overloading of division assignment with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator/=(const Decimal &d);

    /**
     * @brief operator overloading of division assignment with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator/=(const Binary &b);

    /**
     * @brief operator overloading of division assignment with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator/=(const Octal &o);

    /**
     * @brief operator overloading of division assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator/=(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus assignment with Decimal object
     * @param d The number with Decimal reference object
     * @return Decimal object
     */
    Decimal &operator%=(const Decimal &d);

    /**
     * @brief operator overloading of modulus assignment with Binary object
     * @param b The number with Binary reference object
     * @return Decimal object
     */
    Decimal &operator%=(const Binary &b);

    /**
     * @brief operator overloading of modulus assignment with Octal object
     * @param o The number with Octal reference object
     * @return Decimal object
     */
    Decimal &operator%=(const Octal &o);

    /**
     * @brief operator overloading of modulus assignment with Hexadecimal object
     * @param h The number with Hexadecimal reference object
     * @return Decimal object
     */
    Decimal &operator%=(const Hexadecimal &h);
};

#endif  // DECIMAL_H
