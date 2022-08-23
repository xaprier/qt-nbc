//
// Created by xaprier on 8/23/22.
//
#include <string>

#ifndef QT_NBC_NBC_H
#define QT_NBC_NBC_H


class nbc {
  private:

  public:

	static std::string binToOct( const std::string &number );

	static std::string binToDec( const std::string &number );

	static std::string binToHex( const std::string &number );

	static std::string decToOct( const std::string &number );

	static std::string decToBin( const std::string &number );

	static std::string decToHex( const std::string &number );

	static std::string octToBin( const std::string &number );

	static std::string octToDec( const std::string &number );

	static std::string octToHex( const std::string &number );

	static std::string hexToBin( const std::string &number );

	static std::string hexToOct( const std::string &number );

	static std::string hexToDec( const std::string &number );
};


#endif //QT_NBC_NBC_H
