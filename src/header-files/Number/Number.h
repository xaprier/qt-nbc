#ifndef NUMBER_H
#define NUMBER_H
#include <string>
#include <iostream>
class Binary;
class Decimal;
class Hexadecimal;
class Octal;

class Number {
  protected:
    std::string num;

  public:
    friend class Binary;
    friend class Decimal;
    friend class Hexadecimal;
    friend class Octal;
    explicit Number(std::string = "0.0");
	explicit Number(const Octal& o);
	explicit Number(const Hexadecimal& h);
	Number(const Binary& b);
	explicit Number(const Decimal& d);

    virtual Octal toOct() = 0;
    virtual Decimal toDec() = 0;
    virtual Binary toBin() = 0;
    virtual Hexadecimal toHex() = 0;

    static void clean_number(std::string &num);

	std::string getNum() const {
		return this->num;
	}

    // cout operator overloading
    friend std::ostream &operator<<(std::ostream &output, const Number &n);
	friend void test(const std::string &expected, const std::string &output, int test_case);
    std::string to_string_with_precision(const long double value, int precision);
    std::string sum(std::string val1, std::string val2);
    std::string sub(std::string val1, std::string val2);
    std::string mul(std::string val1, std::string val2);
    std::string div(std::string val1, std::string val2);
};

#endif  // NUMBER_H
