//
// Created by xaprier on 8/23/22.
//
#include "../header-files/nbc.h"

std::string nbc::binToOct( const std::basic_string<char> &number ) {
    return number.length() == 0 || number == "0.0"
               ? "0.0"
               : nbc::decToOct( binToDec( number ) );
}

std::string nbc::binToDec( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    std::string result;

    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        result += "-";
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;

    if ( number.length() != 0 ) {
        intPoint = std::stoull( number.substr( 0, ( number.find( '.' ) != -1 )
                                                      ? number.length()
                                                      : number.find( '.' ) ) );
    }
    unsigned long long decPoint = 0;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = std::stoull(
            number.substr( number.find( '.' ) + 1, number.length() ) );
    }

    // calculate the decimal number from binary
    unsigned long long integer = 0;
    for ( int i = 0; intPoint > 0; i++ ) {
        integer += intPoint % 10 * pow( 2, i );
        intPoint /= 10;
    }

    // add calculated integer value of decimal to result string
    result += std::to_string( integer );
    // add a '.' to the end
    result.push_back( '.' );
    // if there is an entered decimal point or not
    if ( decPoint != 0 ) {
        // calculate the decimal point of binary to decimal
        double decimal = 0;
        for ( int i =
                  -1 * number.substr( number.find( '.' ) + 1, number.length() )
                           .length();
              decPoint > 0; i++ ) {
            decimal += decPoint % 10 * pow( 2, i );
            decPoint /= 10;
        }

        // check the decimal point and add to end of string the char of number
        // if decimal not fully 0
        while ( true ) {
            decimal *= 10;
            if ( fmodl( decimal, 1.0 ) == 0 ) {
                result.push_back( static_cast<char>( decimal ) + '0' );
                break;
            } else {
                result.push_back( static_cast<char>(
                    ( (unsigned long long)decimal ) + '0' ) );
                decimal -= (unsigned long long)decimal;
            }
        }
    } else {
        // if there isn't entered a decimal point enter .0
        result.push_back( '0' );
    }

    return result;
}

std::string nbc::binToHex( const std::basic_string<char> &number ) {
    return number.length() == 0 || number == "0.0"
               ? "0.0"
               : nbc::decToHex( binToDec( number ) );
}

std::string nbc::octToBin( const std::basic_string<char> &number ) {
    return number.length() == 0 || number == "0.0"
               ? "0.0"
               : nbc::decToBin( octToDec( number ) );
}

std::string nbc::octToDec( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    std::string result;

    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        result += "-";
    }
    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if ( number.length() != 0 ) {
        intPoint = std::stoull( number.substr( 0, number.find( '.' ) ) );
    }

    unsigned long long decPoint = 0;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = std::stoull(
            number.substr( number.find( '.' ) + 1, number.length() ) );
    }

    // calculate the integer decimal number from octal
    unsigned long long integer = 0;
    for ( int i = 0; intPoint > 0; i++ ) {
        integer += intPoint % 10 * pow( 8, i );
        intPoint /= 10;
    }

    // add calculated integer value of decimal to result string
    result += std::to_string( integer );
    // add a '.' to the end
    result.push_back( '.' );
    // if there is an entered decimal point or not
    if ( decPoint != 0 ) {
        // calculate the decimal point of octal to decimal
        double decimal = 0;
        for ( int i =
                  -1 * number.substr( number.find( '.' ) + 1, number.length() )
                           .length();
              decPoint > 0; i++ ) {
            decimal += decPoint % 10 * pow( 8, i );
            decPoint /= 10;
        }

        // check the decimal point and add to end of string the char of number
        // if decimal not fully 0
        while ( true ) {
            decimal *= 10;
            if ( fmodl( decimal, 1.0 ) == 0 ) {
                result.push_back( static_cast<char>( decimal ) + '0' );
                break;
            } else {
                result.push_back( static_cast<char>(
                    ( (unsigned long long)decimal ) + '0' ) );
                decimal -= (unsigned long long)decimal;
            }
        }
    } else {
        // if there isn't entered a decimal point enter .0
        result.push_back( '0' );
    }

    return result;
}

std::string nbc::octToHex( const std::basic_string<char> &number ) {
    return number.length() == 0 ? "0.0" : nbc::decToHex( octToDec( number ) );
}

std::string nbc::decToBin( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    std::string result;

    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        result += "-";
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if ( number.length() != 0 ) {
        intPoint = std::stoull( number.substr( 0, number.find( '.' ) ) );
    }
    double decPoint = 0;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = std::stod( number.substr( 0, number.length() ) );
        decPoint -= static_cast<int>( decPoint );
    }

    // calculate the binary number from decimal
    do {
        result += ( static_cast<char>( intPoint % 2 ) + '0' );
        intPoint /= 2;
    } while ( intPoint > 0 );

    result.at( 0 ) == '-' ? std::reverse( result.begin() + 1, result.end() )
                          : std::reverse( result.begin(), result.end() );

    // add a '.' to the end
    result.push_back( '.' );
    // if there is an entered decimal point or not
    if ( fmod( decPoint, 1 ) != 0 ) {
        while ( true ) {
            decPoint *= 2;
            if ( fmodl( decPoint, 1.0 ) == 0 ) {
                result.push_back( static_cast<char>( decPoint ) + '0' );
                break;
            } else {
                result.push_back(
                    static_cast<char>( ( (int)decPoint ) + '0' ) );
                decPoint -= (int)decPoint;
            }
        }
    } else {
        result.push_back( '0' );
    }

    return result;
}

std::string nbc::decToOct( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    std::string result;

    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        result += "-";
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if ( number.length() != 0 ) {
        intPoint = std::stoull( number.substr( 0, number.find( '.' ) ) );
    }
    double decPoint = 0;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = std::stod( number.substr( 0, number.length() ) );
        decPoint -= static_cast<int>( decPoint );
    }

    // calculate the octal number from decimal
    do {
        result += ( static_cast<char>( intPoint % 8 ) + '0' );
        intPoint /= 8;
    } while ( intPoint > 0 );

    result.at( 0 ) == '-' ? std::reverse( result.begin() + 1, result.end() )
                          : std::reverse( result.begin(), result.end() );

    // add a '.' to the end
    result.push_back( '.' );
    // if there is an entered decimal point or not
    if ( decPoint != 0 ) {
        while ( true ) {
            decPoint *= 8;
            if ( fmodl( decPoint, 1.0 ) == 0 ) {
                result.push_back( static_cast<char>( decPoint ) + '0' );
                break;
            } else {
                result.push_back(
                    static_cast<char>( ( (int)decPoint ) + '0' ) );
                decPoint -= (int)decPoint;
            }
        }
    } else {
        result.push_back( '0' );
    }
    return result;
}

std::string nbc::decToHex( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    std::string result;

    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        result += "-";
    }

    // split the decimal number as it supposed to be
    unsigned long long intPoint = 0;
    if ( number.length() != 0 ) {
        intPoint = std::stoull( number.substr( 0, number.find( '.' ) ) );
    }
    double decPoint = 0;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = std::stod( number.substr( 0, number.length() ) );
        decPoint -= static_cast<unsigned long long>( decPoint );
    }

    do {
        if ( intPoint % 16 == 15 ) {
            result += ( 'F' );
        } else if ( intPoint % 16 == 14 ) {
            result += ( 'E' );
        } else if ( intPoint % 16 == 13 ) {
            result += ( 'D' );
        } else if ( intPoint % 16 == 12 ) {
            result += ( 'C' );
        } else if ( intPoint % 16 == 11 ) {
            result += ( 'B' );
        } else if ( intPoint % 16 == 10 ) {
            result += ( 'A' );
        } else {
            result += ( static_cast<char>( intPoint % 16 ) + '0' );
        }
        intPoint /= 16;
    } while ( intPoint > 0 );

    result.at( 0 ) == '-' ? std::reverse( result.begin() + 1, result.end() )
                          : std::reverse( result.begin(), result.end() );

    // add a '.' to the end
    result.push_back( '.' );
    // if there is an entered decimal point or not
    if ( decPoint != 0 ) {
        while ( true ) {
            decPoint *= 16;
            if ( fmodl( decPoint, 1.0 ) == 0 ) {
                if ( (int)decPoint == 15 ) {
                    result.push_back( 'F' );
                } else if ( (int)decPoint == 14 ) {
                    result.push_back( 'E' );
                } else if ( (int)decPoint == 13 ) {
                    result.push_back( 'D' );
                } else if ( (int)decPoint == 12 ) {
                    result.push_back( 'C' );
                } else if ( (int)decPoint == 11 ) {
                    result.push_back( 'B' );
                } else if ( (int)decPoint == 10 ) {
                    result.push_back( 'A' );
                } else {
                    result.push_back(
                        static_cast<char>( ( (int)decPoint ) + '0' ) );
                }
                break;
            } else {
                if ( (int)decPoint == 15 ) {
                    result.push_back( 'F' );
                } else if ( (int)decPoint == 14 ) {
                    result.push_back( 'E' );
                } else if ( (int)decPoint == 13 ) {
                    result.push_back( 'D' );
                } else if ( (int)decPoint == 12 ) {
                    result.push_back( 'C' );
                } else if ( (int)decPoint == 11 ) {
                    result.push_back( 'B' );
                } else if ( (int)decPoint == 10 ) {
                    result.push_back( 'A' );
                } else {
                    result.push_back(
                        static_cast<char>( ( (int)decPoint ) + '0' ) );
                }
                decPoint -= (int)decPoint;
            }
        }
    } else {
        result.push_back( '0' );
    }
    return result;
}

std::string nbc::hexToBin( const std::string &number ) {
    return number.length() == 0 || number == "0.0"
               ? "0.0"
               : nbc::decToBin( nbc::hexToDec( number ) );
}

std::string nbc::hexToOct( const std::string &number ) {
    return number.length() == 0 || number == "0.0"
               ? "0.0"
               : nbc::decToOct( nbc::hexToDec( number ) );
}

std::string nbc::hexToDec( std::basic_string<char> number ) {
    if ( number.length() == 0 || number == "0.0" ) return "0.0";

    bool isItNegative = false;
    if ( number.at( 0 ) == '-' ) {
        number = number.substr( 1, number.length() );
        isItNegative = true;
    }

    double result = 0;
    // split the decimal number as it supposed to be
    std::string intPoint;
    if ( number.length() != 0 ) {
        intPoint = number.substr( 0, ( number.length() > number.find( '.' ) )
                                         ? number.find( '.' )
                                         : number.length() );
    } else {
        intPoint = "0";
    }

    std::string decPoint;
    if ( number.find( '.' ) != -1 &&
         number.length() > number.find( '.' ) + 1 ) {
        decPoint = number.substr( number.find( '.' ) + 1, number.length() );
    }

    std::string sResult;

    // calculate the integer part of decimal from hexadecimal
    for ( int i = intPoint.length() - 1; i >= 0; i-- ) {
        if ( intPoint[ i ] == 'A' )
            result += 10 * pow( 16, intPoint.length() - i - 1 );
        else if ( intPoint[ i ] == 'B' )
            result += 11 * pow( 16, intPoint.length() - i - 1 );
        else if ( intPoint[ i ] == 'C' )
            result += 12 * pow( 16, intPoint.length() - i - 1 );
        else if ( intPoint[ i ] == 'D' )
            result += 13 * pow( 16, intPoint.length() - i - 1 );
        else if ( intPoint[ i ] == 'E' )
            result += 14 * pow( 16, intPoint.length() - i - 1 );
        else if ( intPoint[ i ] == 'F' )
            result += 15 * pow( 16, intPoint.length() - i - 1 );
        else
            result += static_cast<int>( intPoint[ i ] - '0' ) *
                      pow( 16, intPoint.length() - i - 1 );
    }

    for ( char i :
          std::to_string( static_cast<unsigned long long>( result ) ) ) {
        sResult.push_back( i );
    }
    sResult.push_back( '.' );
    result = 0;

    if ( !decPoint.empty() ) {
        int iterator = -1;
        for ( char i : decPoint ) {
            if ( i == 'A' )
                result += 10 * pow( 16, iterator );
            else if ( i == 'B' )
                result += 11 * pow( 16, iterator );
            else if ( i == 'C' )
                result += 12 * pow( 16, iterator );
            else if ( i == 'D' )
                result += 13 * pow( 16, iterator );
            else if ( i == 'E' )
                result += 14 * pow( 16, iterator );
            else if ( i == 'F' )
                result += 15 * pow( 16, iterator );
            else
                result += static_cast<int>( i - '0' ) * pow( 16, iterator );
            iterator--;
        }
    }

    if ( decPoint.length() != 0 ) {
        while ( true ) {
            result *= 10;
            if ( fmodl( result, 1.0 ) == 0 ) {
                sResult.push_back( static_cast<char>( result ) + '0' );
                break;
            } else {
                sResult.push_back( static_cast<char>( ( (int)result ) + '0' ) );
                result -= static_cast<int>( result );
            }
        }
    } else {
        sResult.push_back( '0' );
    }

    if ( isItNegative ) sResult.insert( 0, "-" );

    return sResult;
}