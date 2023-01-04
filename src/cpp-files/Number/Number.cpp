#include "../../header-files/Number/Number.h"
#include "header-files/Number/Octal.h"

#include <string>
#include <utility>
#include <cmath>

Number::Number(std::string number) : num(std::move(number)) {}

Number::Number( const Octal& o ) : num(o.num) {}

Number::Number( const Hexadecimal& h ) : num(h.num) {}

Number::Number( const Binary& b ) : num(b.num) {}

Number::Number( const Decimal& d ) : num(d.num) {}