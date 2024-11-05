cmake_minimum_required(VERSION 3.14)

project(
    XNBC
    VERSION 1.0.0
    DESCRIPTION "Number based calculator and converter"
    HOMEPAGE_URL "https://github.com/xaprier/XNBC"
    LANGUAGES CXX)

set(PROJECT_ORGANIZATION "SFENX")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(lib)
add_subdirectory(res) # icon and .desktop file for gnu/linux

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

configure_file(./include/Config.hpp.cmake ${CMAKE_CURRENT_BINARY_DIR}/Config.hpp)

file(GLOB CPP_FILES src/*.cpp)
file(GLOB UI_FILES design/*.ui)
file(GLOB QRC_FILES res/*.qrc)
file(GLOB HPP_FILES include/*.hpp)

set(PROJECT_SOURCES
  ${HPP_FILES}
  ${CPP_FILES}
  ${UI_FILES}
  ${QRC_FILES}
)

if(WIN32)
    set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/res/icon.rc")
    list(APPEND PROJECT_SOURCES ${app_icon_resource_windows})
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${app_icon_resource_windows}
  )

else()
  if(ANDROID)
    add_library(${PROJECT_NAME} SHARED
      ${PROJECT_SOURCES}
    )

  # Define properties for Android with Qt 5 after find_package() calls as:
  # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(${PROJECT_NAME}
      ${PROJECT_SOURCES}
      ${app_icon_resource_windows}
    )
  endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE NumberBases ASTHandler)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE include)

set_target_properties(${PROJECT_NAME} PROPERTIES
  MACOSX_BUNDLE_GUI_IDENTIFIER https://xaprier.dev
  MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
  MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

if(WIN32)
    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        RUNTIME DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
else()
    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endif()

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(${PROJECT_NAME})
endif()

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:ASTHandler>
        $<TARGET_FILE:NumberBases>
        $<TARGET_FILE:tester>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# # Check if the compiler is GCC and get the version
# if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     message(STATUS "GCC detected, version: ${CMAKE_CXX_COMPILER_VERSION}")

#     # Compare the GCC version
#     if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "11.0")
#         message(STATUS "GCC version is less than 11, disabling tests.")
#     else()
#         # Add the test directory if GCC version is 11 or higher
#         add_subdirectory(test)
#     endif()
# else()
#     # Not GCC; add the test directory
#     add_subdirectory(test)
# endif()
add_subdirectory(test)