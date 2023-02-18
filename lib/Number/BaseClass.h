#ifndef BASECLASS_H
#define BASECLASS_H
#include <string>
#include <iostream>


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
	explicit BaseClass(std::string = "0.0");
	explicit BaseClass(const Octal& o);
	explicit BaseClass(const Hexadecimal& h);
	explicit BaseClass(const Binary& b);
	explicit BaseClass(const Decimal& d);

	virtual Octal toOct() const = 0;
	virtual Decimal toDec() const = 0;
	virtual Binary toBin() const = 0;
	virtual Hexadecimal toHex() const = 0;

	virtual explicit operator std::string() = 0;

	bool operator<(const Binary &b);
	bool operator<(const Octal &o);
	bool operator<(const Decimal &second);
	bool operator<(const Hexadecimal &h);
	bool operator<=(const Binary &b);
	bool operator<=(const Octal &o);
	bool operator<=(const Decimal &second);
	bool operator<=(const Hexadecimal &h);
	bool operator>(const Binary &b);
	bool operator>(const Octal &o);
	bool operator>(const Decimal &sec);
	bool operator>(const Hexadecimal &h);
	bool operator>=(const Binary &b);
	bool operator>=(const Octal &o);
	bool operator>=(const Decimal &sec);
	bool operator>=(const Hexadecimal &h);
	bool operator==(const Binary &b);
	bool operator==(const Octal &o);
	bool operator==(const Decimal &second);
	bool operator==(const Hexadecimal &h);
	bool operator!=(const Binary &b);
	bool operator!=(const Octal &o);
	bool operator!=(const Decimal &second);
	bool operator!=(const Hexadecimal &h);

	static void clean_number(std::string &num);

	[[nodiscard]] std::string getNum() const {
		return this->num;
	}

	// cout operator overloading
	friend std::ostream &operator<<(std::ostream &output, const BaseClass &n);
	friend void test(const std::string &expected, const std::string &output, int test_case);
	static std::string to_string_with_precision(const long double &value, int precision);
	std::string sum(std::string val1, std::string val2);
	std::string sub(std::string val1, std::string val2);
	std::string mul(std::string val1, std::string val2);
	std::string div(std::string val1, std::string val2);
};

#endif  // NUMBER_H
