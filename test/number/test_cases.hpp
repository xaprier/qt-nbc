//
// Created by xaprier on 2/5/23.
//

//! IMPORTANT NOTE
//! THIS TEST CASES REMAINED FROM NOT REFACTORED OLD CODE BUT IT'S WORKS.
//! IF WE TRY TO REFACTOR IT, IT WILL TAKE TOO LONG.
//! SO, THIS PART OF CODE WILL NOT REFACTORED.

#ifndef QT_NBC_SRC_HEADER_FILES_TEST_CASES_H_
#define QT_NBC_SRC_HEADER_FILES_TEST_CASES_H_

#include "Binary.hpp"
#include "Decimal.hpp"
#include "Hexadecimal.hpp"
#include "NumberBase.hpp"
#include "Octal.hpp"

void testConstructors();
void testConverters();
void ostreamOverloadTest();
void operator_plusOverloading();
void operator_subtractOverloading();
void operator_multiplyOverloading();
void operator_divideOverloading();
void operator_remainderOverloading();
void operator_assignmentsOverloading();
void operator_RelationOverloading();

#endif  // QT_NBC_SRC_HEADER_FILES_TEST_CASES_H_
