cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(qt-nbc VERSION 3.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "~/Qt/6.4.3/gcc_64/lib/cmake") # setting qt path

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    cpp-files/main.cpp

    cpp-files/nbconverter.cpp
    header-files/nbconverter.h
    design-files/nbconverter.ui

    design-files/choose.ui
    cpp-files/choose.cpp
    header-files/choose.h

    design-files/nbcalculator.ui
    cpp-files/nbcalculator.cpp
    header-files/nbcalculator.h

    design-files/resources.qrc
)

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/design-files/resources.qrc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt-nbc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${app_icon_resource_windows}
    )

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
            ${app_icon_resource_windows}
        )
    endif()
endif()

target_link_libraries(qt-nbc PRIVATE number)
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

# testing binary
add_executable(cpp_test cpp-files/test.cpp cpp-files/test_cases.cpp header-files/test_cases.h)
target_link_libraries(cpp_test PRIVATE number)

# enable testing functionality
enable_testing()

# define tests
add_test(
    NAME cpp_test
    COMMAND $<TARGET_FILE:cpp_test>
)