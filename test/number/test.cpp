#include "test.hpp"

#include "test_cases.hpp"

//! IMPORTANT NOTE
//! THIS TEST CASES REMAINED FROM NOT REFACTORED OLD CODE BUT IT'S WORKS.
//! IF WE TRY TO REFACTOR IT, IT WILL TAKE TOO LONG.
//! SO, THIS PART OF CODE WILL NOT REFACTORED.

int main() {
    Tester t;
    t.addTest("Constructors", testConstructors);
    t.addTest("Converters", testConverters);
    t.addTest("ostreamOverload", ostreamOverloadTest);
    t.addTest("operator_plusOverloading", operator_plusOverloading);
    t.addTest("operator_subtractOverloading", operator_subtractOverloading);
    t.addTest("operator_multiplyOverloading", operator_multiplyOverloading);
    t.addTest("operator_divideOverloading", operator_divideOverloading);
    t.addTest("operator_remainderOverloading", operator_remainderOverloading);
    t.addTest("operator_assignmentsOverloading", operator_assignmentsOverloading);
    t.addTest("operator_RelationOverloading", operator_RelationOverloading);
    return 0;
}