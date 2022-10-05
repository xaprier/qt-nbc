//
// Created by xaprier on 8/23/22.
//
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>

#ifndef QT_NBC_NBC_H
#define QT_NBC_NBC_H

class nbc {
  private:

  public:
	static std::string binToOct( const std::basic_string<char> &number );

	static std::string binToDec( std::basic_string<char> number );

	static std::string binToHex( const std::basic_string<char> &number );

};

#endif //QT_NBC_NBC_H
