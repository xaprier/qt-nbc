#ifndef HEXADECIMAL_HPP
#define HEXADECIMAL_HPP

#include "NumberBase.hpp"

class Hexadecimal : public NumberBase {
  public:
    /**
     * @brief Construct a new Hexadecimal object from a string(std::string must be formatted as "0x0.0")
     * @param num The number(std::string) with based Hexadecimal
     */
    explicit Hexadecimal(std::string num = "0x0.0");

    /**
     * @brief Construct a new Hexadecimal object from int data type (must be decimal based and it will be converted to Hexadecimal)
     * @param num The number(int) with based decimal
     */
    explicit Hexadecimal(const int &num);

    /**
     * @brief Construct a new Hexadecimal object from double data type (must be decimal based and it will be converted to Hexadecimal)
     * @param num The number(double) with based decimal
     */
    explicit Hexadecimal(const double &num);

    /**
     * @brief Construct a new Binary object from another NumberBase object
     * @param other The other NumberBase
     */
    explicit Hexadecimal(const NumberBase &other);

    /**
     * @brief Construct a new Hexadecimal object from a Decimal object
     * @param d The Decimal object
     */
    explicit Hexadecimal(const Decimal &d);

    /**
     * @brief Construct a new Hexadecimal object from a Hexadecimal object(Copy constructor)
     * @param other The other NumberBase object
     */
    Hexadecimal(const Hexadecimal &h);

    /**
     * @brief Returns the Octal object with converting the current based number to Octal
     * @return The Octal object
     */
    [[nodiscard]] Octal toOct() const override;

    /**
     * @brief Returns the Decimal object with converting the current based number to Decimal
     * @return The Decimal object
     */
    [[nodiscard]] Decimal toDec() const override;

    /**
     * @brief Returns the Binary object with converting the current based number to Binary
     * @return The Binary object
     */
    [[nodiscard]] Binary toBin() const override;

    /**
     * @brief Returns the Hexadecimal object with converting the current based number to Hexadecimal
     * @return The Hexadecimal object
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
    friend std::ostream &operator<<(std::ostream &output, const Hexadecimal &h);

    /**
     * @brief operator overloading of addition with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal operator+(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal operator-(const NumberBase &other);

    /**
     * @brief operator overloading of multiplication with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal operator*(const NumberBase &other);

    /**
     * @brief operator overloading of division with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal operator/(const NumberBase &other);

    /**
     * @brief operator overloading of modulo with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal operator%(const NumberBase &other);

    /**
     * @brief operator overloading of assignment with another NumberBase object(Base will be converted)
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator=(const NumberBase &other);

    /**
     * @brief operator overloading of addition assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator+=(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator-=(const NumberBase &other);

    /**
     * @brief operator overloading of multiplication assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator*=(const NumberBase &other);

    /**
     * @brief operator overloading of division assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator/=(const NumberBase &other);

    /**
     * @brief operator overloading of modulo assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return Hexadecimal
     */
    Hexadecimal &operator%=(const NumberBase &other);
};

#endif  // HEXADECIMAL_HPP
