cmake_minimum_required(VERSION 3.14)

project(number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(number SHARED

    # header files
    Binary.h
    Octal.h
    Decimal.h
    Hexadecimal.h
    BaseClass.h
    Number.h

    # cpp files
    Base/BaseClass.cpp

    Binary/Binary.cpp
    Binary/dividing.cpp
    Binary/multiplying.cpp
    Binary/remainder.cpp
    Binary/subtracting.cpp
    Binary/summing.cpp

    Octal/Octal.cpp
    Octal/dividing.cpp
    Octal/multiplying.cpp
    Octal/remainder.cpp
    Octal/subtracting.cpp
    Octal/summing.cpp

    Decimal/Decimal.cpp
    Decimal/dividing.cpp
    Decimal/multiplying.cpp
    Decimal/remainder.cpp
    Decimal/subtracting.cpp
    Decimal/summing.cpp

    Hexadecimal/Hexadecimal.cpp
    Hexadecimal/dividing.cpp
    Hexadecimal/multiplying.cpp
    Hexadecimal/remainder.cpp
    Hexadecimal/subtracting.cpp
    Hexadecimal/summing.cpp
)

target_compile_definitions(number PRIVATE NUMBER_LIBRARY)