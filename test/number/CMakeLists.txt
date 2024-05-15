cmake_minimum_required(VERSION 3.14)

file(GLOB TEST_FILES_CPP *.cpp)
file(GLOB TEST_FILES_HPP *.hpp)

# testing binary
add_executable(number_test ${TEST_FILES_HPP} ${TEST_FILES_CPP})
target_link_libraries(number_test PRIVATE NumberBases)
target_include_directories(number_test PRIVATE include)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME number_test
  COMMAND $<TARGET_FILE:number_test>
)