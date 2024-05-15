cmake_minimum_required(VERSION 3.14)

project(ASTHandler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HPP_FILES include/*.hpp)
file(GLOB CPP_FILES src/*.cpp)

add_library(${PROJECT_NAME} SHARED
  ${HPP_FILES}
  ${CPP_FILES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE ASTHandler_LIBRARY)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} NumberBases)