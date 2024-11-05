#ifndef NUMBERBASE_H
#define NUMBERBASE_H
#include <iostream>
#include <string>

class Binary;
class Decimal;
class Octal;
class Hexadecimal;

class NumberBase {
  public:
    friend class Binary;
    friend class Decimal;
    friend class Hexadecimal;
    friend class Octal;

    /**
     * @brief Construct a new Base Class object(can be usable with PolyMorphism)
     * @param num The number with based Decimal
     */
    explicit NumberBase(std::string = "0.0");

    /**
     * @brief Construct a new Base Class object(can be usable with PolyMorphism)
     * @param o The number with Octal object
     */
    explicit NumberBase(const Octal &o);

    /**
     * @brief Construct a new Base Class object(can be usable with PolyMorphism)
     * @param h The number with Hexadecimal object
     */
    explicit NumberBase(const Hexadecimal &h);

    /**
     * @brief Construct a new Base Class object(can be usable with PolyMorphism)
     * @param b The number with Binary object
     */
    explicit NumberBase(const Binary &b);

    /**
     * @brief Construct a new Base Class object(can be usable with PolyMorphism)
     * @param d The number with Decimal object
     */
    explicit NumberBase(const Decimal &d);

    /**
     * @brief Destroy the Base Class object
     */
    virtual ~NumberBase() = default;

    /**
     * @brief Returns the Octal object with converting the current based number(Raw Virtual Function)
     * @return Octal
     */
    [[nodiscard]] virtual Octal toOct() const = 0;

    /**
     * @brief Returns the Decimal object with converting the current based number(Raw Virtual Function)
     * @return Decimal
     */
    [[nodiscard]] virtual Decimal toDec() const = 0;

    /**
     * @brief Returns the Binary object with converting the current based number(Raw Virtual Function)
     * @return Binary
     */
    [[nodiscard]] virtual Binary toBin() const = 0;

    /**
     * @brief Returns the Hexadecimal object with converting the current based number(Raw Virtual Function)
     * @return Hexadecimal
     */
    [[nodiscard]] virtual Hexadecimal toHex() const = 0;

    /**
     * @brief Returns the string with it's own based number(Raw Virtual Function)
     * @return std::string
     */
    virtual explicit operator std::string() = 0;

    /**
     * @brief Checks if this number is less than the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is less than the given number, false otherwise.
     */
    bool operator<(const NumberBase &base) const;

    /**
     * @brief Checks if this number is greater than the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is greater than the given number, false otherwise.
     */
    bool operator>(const NumberBase &base) const;

    /**
     * @brief Checks if this number is equal to the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is equal to the given number, false otherwise.
     */
    bool operator==(const NumberBase &base) const;

    /**
     * @brief Checks if this number is not equal to the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is not equal to the given number, false otherwise.
     */
    bool operator!=(const NumberBase &base) const;

    /**
     * @brief Checks if this number is less than or equal to the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is less than or equal to the given number, false otherwise.
     */
    bool operator<=(const NumberBase &base) const;

    /**
     * @brief Checks if this number is greater than or equal to the given number.
     *
     * Compares this number to another NumberBase object after converting both to Decimal.
     *
     * @param base The number to compare against.
     * @return true if this number is greater than or equal to the given number, false otherwise.
     */
    bool operator>=(const NumberBase &base) const;

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
     * @brief std::cout << operator overloading for NumberBase based objects
     * @param output std::ostream
     * @param n NumberBase
     * @return std::ostream
     */
    friend std::ostream &operator<<(std::ostream &output, const NumberBase &n);

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

  protected:
    std::string num;
};

#endif  // NUMBERBASE_H
