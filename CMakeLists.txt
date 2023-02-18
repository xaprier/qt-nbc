cmake_minimum_required(VERSION 3.2)

project(qt-nbc VERSION 3.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.4.1/gcc_64/lib/cmake") # path to Qt6Config.cmake

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/cpp-files/main.cpp

    src/cpp-files/nbconverter.cpp
    src/header-files/nbconverter.h
    src/design-files/nbconverter.ui

    src/cpp-files/nbc.cpp

    src/design-files/choose.ui
    src/cpp-files/choose.cpp
    src/header-files/choose.h

    src/design-files/nbcalculator.ui
    src/cpp-files/nbcalculator.cpp
    src/header-files/nbcalculator.h

    src/cpp-files/test_cases.cpp
    src/header-files/test_cases.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt-nbc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

# Define target properties for Android with Qt 6 as:
# set_property(TARGET qt-nbc APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qt-nbc SHARED
            ${PROJECT_SOURCES}
        )

    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qt-nbc
            ${PROJECT_SOURCES}
        )
    endif()
endif()

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/libnumber.so")
    add_library(
        number SHARED
        lib/Number/BaseClass.h
        lib/Number/Binary.h
        lib/Number/Decimal.h
        lib/Number/Hexadecimal.h
        lib/Number/Octal.h
        lib/Number/Number.h

        lib/Number/Base/BaseClass.cpp

        lib/Number/Binary/Binary.cpp
        lib/Number/Binary/dividing.cpp
        lib/Number/Binary/multiplying.cpp
        lib/Number/Binary/remainder.cpp
        lib/Number/Binary/subtracting.cpp
        lib/Number/Binary/summing.cpp

        lib/Number/Decimal/Decimal.cpp
        lib/Number/Decimal/dividing.cpp
        lib/Number/Decimal/multiplying.cpp
        lib/Number/Decimal/remainder.cpp
        lib/Number/Decimal/subtracting.cpp
        lib/Number/Decimal/summing.cpp

        lib/Number/Hexadecimal/Hexadecimal.cpp
        lib/Number/Hexadecimal/dividing.cpp
        lib/Number/Hexadecimal/multiplying.cpp
        lib/Number/Hexadecimal/remainder.cpp
        lib/Number/Hexadecimal/subtracting.cpp
        lib/Number/Hexadecimal/summing.cpp

        lib/Number/Octal/Octal.cpp
        lib/Number/Octal/dividing.cpp
        lib/Number/Octal/multiplying.cpp
        lib/Number/Octal/remainder.cpp
        lib/Number/Octal/subtracting.cpp
        lib/Number/Octal/summing.cpp
    )
    target_link_libraries(qt-nbc PRIVATE number)
else()
    add_library(
        number SHARED
        IMPORTED
    )
    set_target_properties(
        number PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/libnumber.so"
    )
    target_link_libraries(qt-nbc PRIVATE number)
endif()

# target_link_libraries(qt-nbc PRIVATE number)
target_link_libraries(qt-nbc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(qt-nbc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt-nbc)
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/design-files/icon.svg
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_BINARY_DIR}/libnumber.so DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
