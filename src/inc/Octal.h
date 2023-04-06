#ifndef OCTAL_H
#define OCTAL_H

#include "BaseClass.h"
#include "Binary.h"
#include "Decimal.h"
#include "Hexadecimal.h"

class Octal : public BaseClass {
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
     * @brief Construct a new Octal object from a Hexadecimal object
     * @param h The Hexadecimal object
     */
    explicit Octal(const Hexadecimal &h);

    /**
     * @brief Construct a new Octal object from a Decimal object
     * @param d The Decimal object
     */
    explicit Octal(const Decimal &d);

    /**
     * @brief Construct a new Octal object from a Binary object
     * @param b The Binary object
     */
    explicit Octal(const Binary &b);

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
     * @brief operator overloading of addition with Octal object
     * @param o The Octal object
     * @return Octal object
     */
    Octal operator+(const Octal &o);

    /**
     * @brief operator overloading of addition with Binary object
     * @param b The Binary object
     * @return Octal object
     */
    Octal operator+(const Binary &b);

    /**
     * @brief operator overloading of addition with Decimal object
     * @param second The Decimal object
     * @return Octal object
     */
    Octal operator+(const Decimal &second);

    /**
     * @brief operator overloading of addition with Hexadecimal object
     * @param h The Hexadecimal object
     * @return Octal object
     */
    Octal operator+(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction with Octal object
     * @param o The Octal object
     * @return Octal object
     */
    Octal operator-(const Octal &o);

    /**
     * @brief operator overloading of subtraction with Binary object
     * @param b The Binary object
     * 	* @return Octal object
     */
    Octal operator-(const Binary &b);

    /**
     * @brief operator overloading of subtraction with Decimal object
     * @param second The Decimal object
     * @return Octal object
     */
    Octal operator-(const Decimal &second);

    /**
     * @brief operator overloading of subtraction with Hexadecimal object
     * @param h The Hexadecimal object
     * @return Octal object
     */
    Octal operator-(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication with Octal object
     * @param o The Octal object
     * @return Octal object
     */
    Octal operator*(const Octal &o);

    /**
     * @brief operator overloading of multiplication with Binary object
     * @param b The Binary object
     * @return Octal object
     */
    Octal operator*(const Binary &b);

    /**
     * @brief operator overloading of multiplication with Decimal object
     * @param second The Decimal object
     * @return Octal object
     */
    Octal operator*(const Decimal &second);

    /**
     * @brief operator overloading of multiplication with Hexadecimal object
     * @param h The Hexadecimal object
     * @return Octal object
     */
    Octal operator*(const Hexadecimal &h);

    /**
     * @brief operator overloading of division with Octal object
     * @param o The Octal object
     * @return Octal object
     */
    Octal operator/(const Octal &o);

    /**
     * @brief operator overloading of division with Binary object
     * @param b The Binary object
     * @return Octal object
     */
    Octal operator/(const Binary &b);

    /**
     * @brief operator overloading of division with Decimal object
     * @param second The Decimal object
     * @return Octal object
     */
    Octal operator/(const Decimal &second);

    /**
     * @brief operator overloading of division with Hexadecimal object
     * @param h The Hexadecimal object
     * @return Octal object
     */
    Octal operator/(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus with Octal object
     * @param o The Octal object
     * @return Octal object
     */
    Octal operator%(const Octal &o);

    /**
     * @brief operator overloading of modulus with Binary object
     * @param b The Binary object
     * @return Octal object
     */
    Octal operator%(const Binary &b);

    /**
     * @brief operator overloading of modulus with Decimal object
     * @param second The Decimal object
     * @return Octal object
     */
    Octal operator%(const Decimal &second);

    /**
     * @brief operator overloading of modulus with Hexadecimal object
     * @param h The Hexadecimal object
     * @return Octal object
     */
    Octal operator%(const Hexadecimal &h);

    /**
     * @brief operator overloading of assignment with Octal object(Base will be converted to Octal)
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator=(const Octal &o);

    /**
     * @brief operator overloading of assignment with Binary object(Base will be converted to Octal)
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator=(const Binary &b);

    /**
     * @brief operator overloading of assignment with Decimal object(Base will be converted to Octal)
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator=(const Decimal &d);

    /**
     * @brief operator overloading of assignment with Hexadecimal object(Base will be converted to Octal)
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator=(const Hexadecimal &h);

    /**
     * @brief operator overloading of addition assignment with Octal object
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator+=(const Octal &o);

    /**
     * @brief operator overloading of addition assignment with Binary object
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator+=(const Binary &b);

    /**
     * @brief operator overloading of addition assignment with Decimal object
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator+=(const Decimal &d);

    /**
     * @brief operator overloading of addition assignment with Hexadecimal object
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator+=(const Hexadecimal &h);

    /**
     * @brief operator overloading of subtraction assignment with Octal object
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator-=(const Octal &o);

    /**
     * @brief operator overloading of subtraction assignment with Binary object
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator-=(const Binary &b);

    /**
     * @brief operator overloading of subtraction assignment with Decimal object
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator-=(const Decimal &d);

    /**
     * @brief operator overloading of subtraction assignment with Hexadecimal object
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator-=(const Hexadecimal &h);

    /**
     * @brief operator overloading of multiplication assignment with Octal object
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator*=(const Octal &o);

    /**
     * @brief operator overloading of multiplication assignment with Binary object
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator*=(const Binary &b);

    /**
     * @brief operator overloading of multiplication assignment with Decimal object
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator*=(const Decimal &d);

    /**
     * @brief operator overloading of multiplication assignment with Hexadecimal object
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator*=(const Hexadecimal &h);

    /**
     * @brief operator overloading of division assignment with Octal object
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator/=(const Octal &o);

    /**
     * @brief operator overloading of division assignment with Binary object
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator/=(const Binary &b);

    /**
     * @brief operator overloading of division assignment with Decimal object
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator/=(const Decimal &d);

    /**
     * @brief operator overloading of division assignment with Hexadecimal object
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator/=(const Hexadecimal &h);

    /**
     * @brief operator overloading of modulus assignment with Octal object
     * @param o The Octal object
     * @return reference of Octal object
     */
    Octal &operator%=(const Octal &o);

    /**
     * @brief operator overloading of modulus assignment with Binary object
     * @param b The Binary object
     * @return reference of Octal object
     */
    Octal &operator%=(const Binary &b);

    /**
     * @brief operator overloading of modulus assignment with Decimal object
     * @param d The Decimal object
     * @return reference of Octal object
     */
    Octal &operator%=(const Decimal &d);

    /**
     * @brief operator overloading of modulus assignment with Hexadecimal object
     * @param h The Hexadecimal object
     * @return reference of Octal object
     */
    Octal &operator%=(const Hexadecimal &h);
};

#endif  // OCTAL_H
