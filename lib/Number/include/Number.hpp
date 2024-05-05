//
// Created by xaprier on 2/13/23.
//

#ifndef NUMBER_H
#define NUMBER_H
#include <ostream>

template <class T>
class Number {
    T *number;

  public:
    /**
     * @brief Construct a new Number object with the template type and assign the std::string value to this type of number
     * @param num the number to be stored( std::string )
     * @example Number<Binary>( "0b1010.100001" )
     */
    explicit Number(const std::string &num = "0.0") { number = new T(num); };

    /**
     * @brief Construct a new Number object with the template type and convert to this type of number and assign it
     * @param num the number to be stored( int )( decimal based )
     * @example Number<Binary>( 23 )
     */
    explicit Number(const int num) { number = new T(num); };

    /**
     * @brief Construct a new Number object with the template type and convert to this type of number and assign it
     * @param num the number to be stored( double )( decimal based )
     * @example Number<Binary>( 23.5 )
     */
    explicit Number(const double num) { number = new T(num); };

    /**
     * @brief Construct a new Number object with the template type and assign the value of T to this template
     * @param num (same type as template)(copy constructor)
     * @example Number<Binary>( Binary )
     */
    explicit Number(const T &num) { number = new T(num); };

    /**
     * @brief Construct a new Number object with the template type and convert to this type of number and assign it
     * @param num the second type of number contrarily to the template type
     * @example Number<Binary>( Decimal )
     */
    template <class T2>
    explicit Number(const T2 &num) { number = new T(num); };

    /**
     * @brief Construct a new Number object with the same object type and assign the value of T to this template( copy constructor )
     * @param num the same type as template
     * @example Number<Binary>( Number<Binary> )
     */
    Number(const Number<T> &num) { number = new T(num.getNumber()); };

    /**
     * @brief Construct a new Number object with the contrarily object type and convert to this type of number and assign it
     * @param num the second type of number contrarily to the template type
     * @example Number<Binary>( Number<Octal> )
     */
    template <class T2>
    explicit Number(const Number<T2> &num) { number = new T(num.getNumber()); };

    /**
     * @brief Destroy the Number object
     */
    ~Number() { delete number; };

    /**
     * @brief Get the Number object
     * @return the number stored in the object
     */
    T getNumber() const { return *number; };

    /**
     * @brief Operator overloading of addition with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> + Number<Octal>
     */
    template <class T2>
    Number<T> operator+(const Number<T2> &num) { return Number<T>(*number + num.getNumber()); }

    /**
     * @brief Operator overloading of addition with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> + Decimal
     */
    template <class T2>
    Number<T> operator+(const T2 &num) { return Number<T>(*number + num); }

    /**
     * @brief Operator overloading of subtraction with the any type of Number( Number<Binary>... )
     * @param num the number to be subtracted( Number template )
     * @example Number<Binary> - Number<Octal>
     */
    template <class T2>
    Number<T> operator-(const Number<T2> &num) { return Number<T>(*number - num.getNumber()); }

    /**
     * @brief Operator overloading of subtraction with the any type of Number( Binary... )
     * @param num the number to be subtracted( Binary... )
     * @example Number<Binary> - Decimal
     */
    template <class T2>
    Number<T> operator-(const T2 &num) { return Number<T>(*number - num); }

    /**
     * @brief Operator overloading of multiplication with the any type of Number( Number<Binary>... )
     * @param num the number to be multiplied( Number template )
     * @example Number<Binary> * Number<Octal>
     */
    template <class T2>
    Number<T> operator*(const Number<T2> &num) { return Number<T>(*number * num.getNumber()); }

    /**
     * @brief Operator overloading of multiplication with the any type of Number( Binary... )
     * @param num the number to be multiplied( Binary... )
     * @example Number<Binary> * Decimal
     */
    template <class T2>
    Number<T> operator*(const T2 &num) { return Number<T>(*number * num); }

    /**
     * @brief Operator overloading of division with the any type of Number( Number<Binary>... )
     * @param num the number to be divided( Number template )
     * @example Number<Binary> / Number<Octal>
     */
    template <class T2>
    Number<T> operator/(const Number<T2> &num) { return Number<T>(*number / num.getNumber()); }

    /**
     * @brief Operator overloading of division with the any type of Number( Binary... )
     * @param num the number to be divided( Binary... )
     * @example Number<Binary> / Decimal
     */
    template <class T2>
    Number<T> operator/(const T2 &num) { return Number<T>(*number / num); }

    /**
     * @brief Operator overloading of modulo with the any type of Number( Number<Binary>... )
     * @param num the number to be modulo( Number template )
     * @example Number<Binary> % Number<Octal>
     */
    template <class T2>
    Number<T> operator%(const Number<T2> &num) { return Number<T>(*number % num.getNumber()); }

    /**
     * @brief Operator overloading of modulo with the any type of Number( Binary... )
     * @param num the number to be modulo( Binary... )
     * @example Number<Binary> % Decimal
     */
    template <class T2>
    Number<T> operator%(const T2 &num) { return Number<T>(*number % num); }

    /**
     * @brief Operator overloading of addition assignment with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> += Number<Octal>
     */
    template <class T2>
    Number<T> operator+=(const Number<T2> &num) { return Number<T>(*number += num.getNumber()); }

    /**
     * @brief Operator overloading of addition assignment with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> += Decimal
     */
    template <class T2>
    Number<T> operator+=(const T2 &num) { return Number<T>(*number += num); }

    /**
     * @brief Operator overloading of subtraction assignment with the any type of Number( Number<Binary>... )
     * @param num the number to be subtracted( Number template )
     * @example Number<Binary> -= Number<Octal>
     */
    template <class T2>
    Number<T> operator-=(const Number<T2> &num) { return Number<T>(*number -= num.getNumber()); }

    /**
     * @brief Operator overloading of subtraction assignment with the any type of Number( Binary... )
     * @param num the number to be subtracted( Binary... )
     * @example Number<Binary> -= Decimal
     */
    template <class T2>
    Number<T> operator-=(const T2 &num) { return Number<T>(*number -= num); }

    /**
     * @brief Operator overloading of multiplication assignment with the any type of Number( Number<Binary>... )
     * @param num the number to be multiplied( Number template )
     * @example Number<Binary> *= Number<Octal>
     */
    template <class T2>
    Number<T> operator*=(const Number<T2> &num) { return Number<T>(*number *= num.getNumber()); }

    /**
     * @brief Operator overloading of multiplication assignment with the any type of Number( Binary... )
     * @param num the number to be multiplied( Binary... )
     * @example Number<Binary> *= Decimal
     */
    template <class T2>
    Number<T> operator*=(const T2 &num) { return Number<T>(*number *= num); }

    /**
     * @brief Operator overloading of division assignment with the any type of Number( Number<Binary>... )
     * @param num the number to be divided( Number template )
     * @example Number<Binary> /= Number<Octal>
     */
    template <class T2>
    Number<T> operator/=(const Number<T2> &num) { return Number<T>(*number /= num.getNumber()); }

    /**
     * @brief Operator overloading of division assignment with the any type of Number( Binary... )
     * @param num the number to be divided( Binary... )
     * @example Number<Binary> /= Decimal
     */
    template <class T2>
    Number<T> operator/=(const T2 &num) { return Number<T>(*number /= num); }

    /**
     * @brief Operator overloading of modulo assignment with the any type of Number( Number<Binary>... )
     * @param num the number to be modulo( Number template )
     * @example Number<Binary> %= Number<Octal>
     */
    template <class T2>
    Number<T> operator%=(const Number<T2> &num) { return Number<T>(*number %= num.getNumber()); }

    /**
     * @brief Operator overloading of modulo assignment with the any type of Number( Binary... )
     * @param num the number to be modulo( Binary... )
     * @example Number<Binary> %= Decimal
     */
    template <class T2>
    Number<T> operator%=(const T2 &num) { return Number<T>(*number %= num); }

    /**
     * @brief Operator overloading of equality with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> == Number<Octal>
     * @return true if equal
     */
    template <class T2>
    bool operator==(const Number<T2> &num) { return *number == num.getNumber(); }

    /**
     * @brief Operator overloading of equality with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> == Decimal
     * @return true if equal
     */
    template <class T2>
    bool operator==(const T2 &num) { return *number == num; }

    /**
     * @brief Operator overloading of inequality with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> != Number<Octal>
     * @return true if not equal
     */
    template <class T2>
    bool operator!=(const Number<T2> &num) { return *number != num.getNumber(); }

    /**
     * @brief Operator overloading of inequality with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> != Decimal
     * @return true if not equal
     */
    template <class T2>
    bool operator!=(const T2 &num) { return *number != num; }

    /**
     * @brief Operator overloading of greater than with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> > Number<Octal>
     * @return true if greater than
     */
    template <class T2>
    bool operator>(const Number<T2> &num) { return *number > num.getNumber(); }

    /**
     * @brief Operator overloading of greater than with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> < Decimal
     * @return true if greater than
     */
    template <class T2>
    bool operator>(const T2 &num) { return *number > num; }

    /**
     * @brief Operator overloading of less than with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> < Number<Octal>
     * @return true if less than
     */
    template <class T2>
    bool operator<(const Number<T2> &num) { return *number < num.getNumber(); }

    /**
     * @brief Operator overloading of less than with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> < Decimal
     * @return true if less than
     */
    template <class T2>
    bool operator<(const T2 &num) { return *number < num; }

    /**
     * @brief Operator overloading of greater than or equal to with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> >= Number<Octal>
     * @return true if greater than or equal to
     */
    template <class T2>
    bool operator>=(const Number<T2> &num) { return *number >= num.getNumber(); }

    /**
     * @brief Operator overloading of greater than or equal to with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> >= Decimal
     * @return true if greater than or equal to
     */
    template <class T2>
    bool operator>=(const T2 &num) { return *number >= num; }

    /**
     * @brief Operator overloading of less than or equal to with the any type of Number( Number<Binary>... )
     * @param num the number to be added( Number template )
     * @example Number<Binary> <= Number<Octal>
     * @return true if less than or equal to
     */
    template <class T2>
    bool operator<=(const Number<T2> &num) { return *number <= num.getNumber(); }

    /**
     * @brief Operator overloading of less than or equal to with the any type of Number( Binary... )
     * @param num the number to be added( Binary... )
     * @example Number<Binary> <= Decimal
     * @return true if less than or equal to
     */
    template <class T2>
    bool operator<=(const T2 &num) { return *number <= num; }

    /**
     * @brief Operator overloading of assignment with the same type of Number
     * @return the reference of the number
     * @example Number<Binary> = Number<Binary>
     */
    Number<T> &operator=(const Number<T> &num) {
        if (this == &num) return *this;
        delete number;
        this->number = new T(num.number);
        return *this;
    }

    /**
     * @brief Operator overloading of assignment with the same type of Number's Type
     * @return the reference of the number
     * @example Number<Binary> = Binary
     */
    Number<T> &operator=(const T &num) {
        delete number;
        this->number = new T(num);
        return *this;
    }

    /**
     * @brief Operator overloading of assignment with the any type of Number
     * @return the reference of the number
     * @example Number<Binary> = Number<Octal>
     */
    template <class T2>
    Number<T> &operator=(const Number<T2> &num) {
        delete number;
        this->number = new T(num.getNumber());
        return *this;
    }

    /**
     * @brief Operator overloading of assignment with the any type of Number
     * @return the reference of the number
     * @example Number<Binary> = Octal
     */
    template <class T2>
    Number<T> &operator=(const T2 &num) {
        delete number;
        this->number = new T(num);
        return *this;
    }

    /**
     * @brief Operator overloading of std::ostream with the any type of Number for printing the number value
     * @return std::ostream
     * @example std::cout << Number<Binary>
     */
    friend std::ostream &operator<<(std::ostream &os, const Number<T> &num) { return os << num.getNumber(); }

    /**
     * @brief Operator overloading of std::string for returning the number value
     * @return std::string
     */
    explicit operator std::string() { return std::string(*number); }
};
#endif  // NUMBER_H
