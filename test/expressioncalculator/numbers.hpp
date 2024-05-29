#include <cmath>
#include <string>

#pragma once

const std::string b1 = "11101.001";
const std::string b2 = "11.0101";
const std::string o1 = "35.1";
const std::string o2 = "3.24";
const std::string d1 = "29.125";
const std::string d2 = "3.3125";
const std::string x1 = "1D.2";
const std::string x2 = "3.5";

const double d1_double = std::stod(d1);
const double d2_double = std::stod(d2);

const double res_division = d1_double / d2_double;
const double res_addition = d1_double + d2_double;
const double res_multiply = d1_double * d2_double;
const double res_subtraction = d1_double - d2_double;
const double res_remainder1 = std::fmod(d1_double, d2_double);
const double res_remainder2 = std::fmod(d2_double, d1_double);

const double res_me_addition_multiply = d1_double + d1_double * d2_double;             // d1 + d1 * d2
const double res_me_addition_divide = d1_double + d1_double / d2_double;               // d1 + d1 / d2
const double res_me_addition_remainder = d1_double + std::fmod(d1_double, d2_double);  // d1 + d1 % d2
const double res_me_addition_subtraction = d1_double + d1_double - d2_double;          // d1 + d1 - d2

const double res_me_subtraction_multiply = d1_double - d1_double * d2_double;             // d1 - d1 * d2
const double res_me_subtraction_divide = d1_double - d1_double / d2_double;               // d1 - d1 / d2
const double res_me_subtraction_remainder = d1_double - std::fmod(d1_double, d2_double);  // d1 - d1 % d2
const double res_me_subtraction_addition = d1_double - d1_double + d2_double;             // d1 - d1 + d2
//
const double res_me_multiply_addition = d1_double * d1_double + d2_double;             // d1 * d1 + d2
const double res_me_multiply_subtraction = d1_double * d1_double - d2_double;          // d1 * d1 - d2
const double res_me_multiply_divide = d1_double * d1_double / d2_double;               // d1 * d1 / d2
const double res_me_multiply_remainder = std::fmod(d1_double * d1_double, d2_double);  // d1 * d1 % d2

const double res_me_divide_addition = d1_double / d1_double + d2_double;             // d1 / d1 + d2
const double res_me_divide_subtraction = d1_double / d1_double - d2_double;          // d1 / d1 - d2
const double res_me_divide_multiply = d1_double / d1_double * d2_double;             // d1 / d1 * d2
const double res_me_divide_remainder = std::fmod(d1_double / d1_double, d2_double);  // d1 / d1 % d2

const double res_me_remainder_addition = std::fmod(d1_double, d1_double) + d2_double;     // d1 % d1 + d2
const double res_me_remainder_subtraction = std::fmod(d1_double, d1_double) - d2_double;  // d1 % d1 - d2
const double res_me_remainder_multiply = std::fmod(d1_double, d1_double) * d2_double;     // d1 % d1 * d2
const double res_me_remainder_divide = std::fmod(d1_double, d1_double) / d2_double;       // d1 % d1 / d2

const char op_addition = '+';
const char op_division = '/';
const char op_multiply = '*';
const char op_subtraction = '-';
const char op_remainder = '%';
