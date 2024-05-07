cmake_minimum_required(VERSION 3.14)

file(GLOB CPP_FILES *.cpp)

# testing binary
add_executable(tester_test ${CPP_FILES})
target_link_libraries(tester_test PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(tester_test PRIVATE include)

# define tests
add_test(
  NAME tester_test
  COMMAND $<TARGET_FILE:tester_test>
)