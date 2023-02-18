//
// Created by xaprier on 2/13/23.
//

#ifndef NUMBER_H
#define NUMBER_H
#include <ostream>

#include "Binary.h"

template <class T>
class Number {
    T *number;

  public:
    explicit Number(const std::string &num = "0.0") { number = new T(num); };
    explicit Number(const int num) { number = new T(num); };
    explicit Number(const double num) { number = new T(num); };
    explicit Number(const T &num) { number = new T(num); };
    template <class T2>
    explicit Number(const T2 &num) { number = new T(num); };
    Number(const Number<T> &num) { number = new T(num.getNumber()); };  // copy constructor
    template <class T2>
    explicit Number(const Number<T2> &num) { number = new T(num.getNumber()); };  // copy constructor
    ~Number() { delete number; };
    T getNumber() const { return *number; };
    template <class T2>
    Number<T> operator+(const Number<T2> &num) { return Number<T>(*number + num.getNumber()); }
    template <class T2>
    Number<T> operator+(const T2 &num) { return Number<T>(*number - num); }
    template <class T2>
    Number<T> operator-(const Number<T2> &num) { return Number<T>(*number - num.getNumber()); }
    template <class T2>
    Number<T> operator-(const T2 &num) { return Number<T>(*number - num); }
    template <class T2>
    Number<T> operator*(const Number<T2> &num) { return Number<T>(*number * num.getNumber()); }
    template <class T2>
    Number<T> operator*(const T2 &num) { return Number<T>(*number * num); }
    template <class T2>
    Number<T> operator/(const Number<T2> &num) { return Number<T>(*number / num.getNumber()); }
    template <class T2>
    Number<T> operator/(const T2 &num) { return Number<T>(*number / num); }
    template <class T2>
    Number<T> operator%(const Number<T2> &num) { return Number<T>(*number % num.getNumber()); }
    template <class T2>
    Number<T> operator%(const T2 &num) { return Number<T>(*number % num); }
    template <class T2>
    Number<T> operator+=(const Number<T2> &num) { return Number<T>(*number += num.getNumber()); }
    template <class T2>
    Number<T> operator+=(const T2 &num) { return Number<T>(*number += num); }
    template <class T2>
    Number<T> operator-=(const Number<T2> &num) { return Number<T>(*number -= num.getNumber()); }
    template <class T2>
    Number<T> operator-=(const T2 &num) { return Number<T>(*number -= num); }
    template <class T2>
    Number<T> operator*=(const Number<T2> &num) { return Number<T>(*number *= num.getNumber()); }
    template <class T2>
    Number<T> operator*=(const T2 &num) { return Number<T>(*number *= num); }
    template <class T2>
    Number<T> operator/=(const Number<T2> &num) { return Number<T>(*number /= num.getNumber()); }
    template <class T2>
    Number<T> operator/=(const T2 &num) { return Number<T>(*number /= num); }
    template <class T2>
    Number<T> operator%=(const Number<T2> &num) { return Number<T>(*number %= num.getNumber()); }
    template <class T2>
    Number<T> operator%=(const T2 &num) { return Number<T>(*number %= num); }
    template <class T2>
    bool operator==(const Number<T2> &num) { return *number == num.getNumber(); }
    template <class T2>
    bool operator==(const T2 &num) { return *number == num; }
    template <class T2>
    bool operator!=(const Number<T2> &num) { return *number != num.getNumber(); }
    template <class T2>
    bool operator!=(const T2 &num) { return *number != num; }
    template <class T2>
    bool operator>(const Number<T2> &num) { return *number > num.getNumber(); }
    template <class T2>
    bool operator<(const T2 &num) { return *number < num; }
    template <class T2>
    bool operator<(const Number<T2> &num) { return *number < num.getNumber(); }
    template <class T2>
    bool operator>(const T2 &num) { return *number > num; }
    template <class T2>
    bool operator>=(const Number<T2> &num) { return *number >= num.getNumber(); }
    template <class T2>
    bool operator>=(const T2 &num) { return *number >= num; }
    template <class T2>
    bool operator<=(const Number<T2> &num) { return *number <= num.getNumber(); }
    template <class T2>
    bool operator<=(const T2 &num) { return *number <= num; }

    Number<T> &operator=(const Number<T> &num) {
        if (this == &num) return *this;
        delete number;
        this->number = new T(num.number);
        return *this;
    }
    Number<T> &operator=(const T &num) {
        delete number;
        this->number = new T(num);
        return *this;
    }
    template <class T2>
    Number<T> &operator=(const Number<T2> &num) {
        delete number;
        this->number = new T(num.getNumber());
        return *this;
    }
    template <class T2>
    Number<T> &operator=(const T2 &num) {
        delete number;
        this->number = new T(num);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Number<T> &num) { return os << num.getNumber(); }
    explicit operator std::string() { return std::string(*number); }
};
#endif
