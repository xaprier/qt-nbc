#include <iostream>
#include "../header-files/test_cases.h"

template <class T>
std::ostream &operator<<(std::ostream &output, const BaseClass &n) {
    output << n.num;
    return output;
}

int main() {
    testConstructors();
    testConverters();
    ostreamOverloadTest();
    operator_plusOverloading();
    operator_subtractOverloading();
    operator_multiplyOverloading();
    operator_divideOverloading();
    operator_remainderOverloading();
 	operator_assignmentsOverloading();
	operator_RelationOverloading();
    return 0;
}
