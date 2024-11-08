cmake_minimum_required(VERSION 3.14)

# ! IMPORTANT NOTE
# ! THIS TEST CASES REMAINED FROM NOT REFACTORED OLD CODE BUT IT'S WORKS.
# ! IF WE TRY TO REFACTOR IT, IT WILL TAKE TOO LONG.
# ! SO, THIS PART OF CODE WILL NOT REFACTORED.
file(GLOB TEST_FILES_CPP *.cpp)
file(GLOB TEST_FILES_HPP *.hpp)

# testing binary
add_executable(number_test ${TEST_FILES_HPP} ${TEST_FILES_CPP})
target_link_libraries(number_test PRIVATE NumberBases Tester)
target_include_directories(number_test PRIVATE include)

# define tests
add_test(
  NAME number_test
  COMMAND $<TARGET_FILE:number_test>
)