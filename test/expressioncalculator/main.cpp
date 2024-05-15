#include "addition.hpp"
#include "divide.hpp"
#include "multiply.hpp"
#include "remainder.hpp"
#include "subtraction.hpp"
#include "test.hpp"

int main() {
    Tester t;
    t.addTest("Addition Tests", addition_tests);
    t.addTest("Subtraction Tests", subtraction_tests);
    t.addTest("Multiply Tests", multiply_tests);
    t.addTest("Division Tests", division_tests);
    t.addTest("Remainder Tests", remainder_tests);
}