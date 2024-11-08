#ifndef OCTAL_HPP
#define OCTAL_HPP

#include "NumberBase.hpp"

class Octal : public NumberBase {
  public:
    /**
     * @brief Construct a new Octal object from a string(std::string must be formatted as "0o0.0")
     * @param num The number(std::string) with based Octal
     */
    explicit Octal(std::string num = "0o0.0");

    /**
     * @brief Construct a new Octal object from a int data type (must be decimal based and it will be converted to Octal)
     * @param num The number(int) with based Decimal
     */
    explicit Octal(const int &num);

    /**
     * @brief Construct a new Octal object from a double data type (must be decimal based and it will be converted to Octal)
     * @param num The number(double) with based Decimal
     */
    explicit Octal(const double &num);

    /**
     * @brief Construct a new Octal object from a Binary object
     * @param b The Binary object
     */
    explicit Octal(const NumberBase &other);

    /**
     * @brief Construct a new Octal object from a Decimal object
     * @param d The Decimal object
     */
    explicit Octal(const Decimal &d);

    /**
     * @brief Construct a new Octal object from a Octal object(copy constructor)
     * @param o The Octal object
     */
    Octal(const Octal &o);

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
    friend std::ostream &operator<<(std::ostream &output, const Octal &o);

    /**
     * @brief operator overloading of addition with another NumberBase object
     * @param other The other NumberBase object
     * @return Octal object
     */
    Octal operator+(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction with another NumberBase object
     * @param other The other NumberBase object
     * @return Octal object
     */
    Octal operator-(const NumberBase &other);

    /**
     * @brief operator overloading of multiplication with another NumberBase object
     * @param other The other NumberBase object
     * @return Octal object
     */
    Octal operator*(const NumberBase &other);

    /**
     * @brief operator overloading of division with another NumberBase object
     * @param other The other NumberBase object
     * @return Octal object
     */
    Octal operator/(const NumberBase &other);

    /**
     * @brief operator overloading of modulo with another NumberBase object
     * @param other The other NumberBase object
     * @return Octal object
     */
    Octal operator%(const NumberBase &other);

    /**
     * @brief operator overloading of assignment with another NumberBase object(Base will be converted to Octal)
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator=(const NumberBase &other);

    /**
     * @brief operator overloading of addition assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator+=(const NumberBase &other);

    /**
     * @brief operator overloading of subtraction assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator-=(const NumberBase &other);

    /**
     * @brief operator overloading of multiplication assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator*=(const NumberBase &other);

    /**
     * @brief operator overloading of division assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator/=(const NumberBase &other);

    /**
     * @brief operator overloading of modulo assignment with another NumberBase object
     * @param other The other NumberBase object
     * @return reference of Octal object
     */
    Octal &operator%=(const NumberBase &other);
};

#endif  // OCTAL_HPP
