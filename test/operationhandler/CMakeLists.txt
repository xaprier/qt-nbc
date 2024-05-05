cmake_minimum_required(VERSION 3.14)

file(GLOB TEST_FILES_CPP *.cpp)
file(GLOB TEST_FILES_HPP *.hpp)

# testing binary
add_executable(operationtest ${TEST_FILES_HPP} ${TEST_FILES_CPP})
target_link_libraries(operationtest PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(operationtest PRIVATE include)

# define tests
add_test(
  NAME operationtest
  COMMAND $<TARGET_FILE:operationtest>
)