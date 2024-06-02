cmake_minimum_required(VERSION 3.14)

file(GLOB TEST_FILES_CPP *.cpp)
file(GLOB TEST_FILES_HPP *.hpp)

# testing binary
add_executable(expressioncalculator_test ${TEST_FILES_HPP} ${TEST_FILES_CPP})
target_link_libraries(expressioncalculator_test PRIVATE Tester NumberBases ASTHandler)
target_include_directories(expressioncalculator_test PRIVATE include)

# define tests
add_test(
  NAME expressioncalculator_test
  COMMAND $<TARGET_FILE:expressioncalculator_test>
)