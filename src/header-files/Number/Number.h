#ifndef NUMBER_H
#define NUMBER_H
#include <string>
class Binary;
class Decimal;
class Hexadecimal;
class Octal;

class Number {
  protected:
    std::string num;

  public:
    explicit Number(std::string = "0.0");
	explicit Number(const Octal& o);
	explicit Number(const Hexadecimal& h);
	explicit Number(const Binary& b);
	explicit Number(const Decimal& d);

    virtual Octal toOct() = 0;
    virtual Decimal toDec() = 0;
    virtual Binary toBin() = 0;
    virtual Hexadecimal toHex() = 0;
};

#endif  // NUMBER_H