cmake_minimum_required(VERSION 3.5)

project(qt-nbc VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.4.0/gcc_64/lib/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    cpp-files/main.cpp

    cpp-files/nbconverter.cpp
    header-files/nbconverter.h
    design-files/nbconverter.ui

    header-files/nbc.h
    cpp-files/nbc.cpp

    design-files/choose.ui
    cpp-files/choose.cpp
    header-files/choose.h

    design-files/nbcalculator.ui
    cpp-files/nbcalculator.cpp
    header-files/nbcalculator.h
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

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/design-files/icon.svg
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
