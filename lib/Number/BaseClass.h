#ifndef BASECLASS_H
#define BASECLASS_H
#include <iostream>
#include <string>

class Binary;
class Decimal;
class Octal;
class Hexadecimal;

class BaseClass {
  protected:
    std::string num;

  public:
    friend class Binary;
    friend class Decimal;
    friend class Hexadecimal;
    friend class Octal;

    /**
     * @brief Construct a new Base Class object
     * @param num The number with based Decimal
     */
    explicit BaseClass(std::string = "0.0");

    /**
     * @brief Construct a new Base Class object
     * @param o The number with Octal object
     */
    explicit BaseClass(const Octal &o);

    /**
     * @brief Construct a new Base Class object
     * @param h The number with Hexadecimal object
     */
    explicit BaseClass(const Hexadecimal &h);

    /**
     * @brief Construct a new Base Class object
     * @param b The number with Binary object
     */
    explicit BaseClass(const Binary &b);

    /**
     * @brief Construct a new Base Class object
     * @param d The number with Decimal object
     */
    explicit BaseClass(const Decimal &d);

    /**
     * @brief Returns the Octal object with converting the current based number(Raw Virtual Function)
     * @return Octal
     */
    virtual Octal toOct() const = 0;

    /**
     * @brief Returns the Decimal object with converting the current based number(Raw Virtual Function)
     * @return Decimal
     */
    virtual Decimal toDec() const = 0;

    /**
     * @brief Returns the Binary object with converting the current based number(Raw Virtual Function)
     * @return Binary
     */
    virtual Binary toBin() const = 0;

    /**
     * @brief Returns the Hexadecimal object with converting the current based number(Raw Virtual Function)
     * @return Hexadecimal
     */
    virtual Hexadecimal toHex() const = 0;

    /**
     * @brief Returns the string with it's own based number(Raw Virtual Function)
     * @return std::string
     */
    virtual explicit operator std::string() = 0;

    /**
     * @brief If the object value is less than the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator<(const Binary &b);

    /**
     * @brief If the object value is less than the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator<(const Octal &o);

    /**
     * @brief If the object value is less than the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator<(const Decimal &second);

    /**
     * @brief If the object value is less than the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator<(const Hexadecimal &h);

    /**
     * @brief If the object value is less than or equal to the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator<=(const Binary &b);

    /**
     * @brief If the object value is less than or equal to the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator<=(const Octal &o);

    /**
     * @brief If the object value is less than or equal to the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator<=(const Decimal &second);

    /**
     * @brief If the object value is less than or equal to the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator<=(const Hexadecimal &h);

    /**
     * @brief If the object value is greater than the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator>(const Binary &b);

    /**
     * @brief If the object value is greater than the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator>(const Octal &o);

    /**
     * @brief If the object value is greater than the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator>(const Decimal &sec);

    /**
     * @brief If the object value is greater than the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator>(const Hexadecimal &h);

    /**
     * @brief If the object value is greater than or equal to the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator>=(const Binary &b);

    /**
     * @brief If the object value is greater than or equal to the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator>=(const Octal &o);

    /**
     * @brief If the object value is greater than or equal to the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator>=(const Decimal &sec);

    /**
     * @brief If the object value is greater than or equal to the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator>=(const Hexadecimal &h);

    /**
     * @brief If the object value is equal to the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator==(const Binary &b);

    /**
     * @brief If the object value is equal to the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator==(const Octal &o);

    /**
     * @brief If the object value is equal to the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator==(const Decimal &second);

    /**
     * @brief If the object value is equal to the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator==(const Hexadecimal &h);

    /**
     * @brief If the object value is not equal to the given value
     * @param b Binary object
     * @return Polymorphic operator
     */
    bool operator!=(const Binary &b);

    /**
     * @brief If the object value is not equal to the given value
     * @param o Octal object
     * @return Polymorphic operator
     */
    bool operator!=(const Octal &o);

    /**
     * @brief If the object value is not equal to the given value
     * @param second Decimal object
     * @return Polymorphic operator
     */
    bool operator!=(const Decimal &second);

    /**
     * @brief If the object value is not equal to the given value
     * @param h Hexadecimal object
     * @return Polymorphic operator
     */
    bool operator!=(const Hexadecimal &h);

    /**
     * @brief Clears the unnecessary zeros from the number and the other number cleaning stuffs
     * @param num Number string
     */
    static void clean_number(std::string &num);

    /**
     * @brief Returns the number string
     * @return std::string
     */
    [[nodiscard]] std::string getNum() const {
        return this->num;
    }

    /**
     * @brief std::cout << operator overloading for BaseClass based objects
     * @param output std::ostream
     * @param n BaseClass
     * @return std::ostream
     */
    friend std::ostream &operator<<(std::ostream &output, const BaseClass &n);

    /**
     * @brief Making function as friend for Unit Testing and accessing private/protected members
     * @param expected Expected output
     * @param output Actual output
     * @param test_case Test case number
     */
    friend void test(const std::string &expected, const std::string &output, int test_case);

    /**
     * @brief to_string() function with the given precision
     * @param value Value to be converted to string
     * @param precision Precision
     * @return std::string
     */
    static std::string to_string_with_precision(const long double &value, int precision);

    /**
     * @brief Summing of two long double numbers with std::string
     * @param val1 First value
     * @param val2 Second value
     * @return std::string as result
     */
    std::string sum(std::string val1, std::string val2);

    /**
     * @brief Subtraction of two long double numbers with std::string
     * @param val1 First value
     * @param val2 Second value
     * @return std::string as result
     */
    std::string sub(std::string val1, std::string val2);

    /**
     * @brief Multiplication of two long double numbers with std::string
     * @param val1 First value
     * @param val2 Second value
     * @return std::string as result
     */
    std::string mul(std::string val1, std::string val2);

    /**
     * @brief Division of two long double numbers with std::string
     * @param val1 First value
     * @param val2 Second value
     * @return std::string as result
     */
    std::string div(std::string val1, std::string val2);
};

#endif  // BASECLASS_H
