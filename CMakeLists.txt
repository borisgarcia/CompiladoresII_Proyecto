cmake_minimum_required (VERSION 2.6)
project(test_parser)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(RE2C REQUIRED)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14" )

add_custom_command (
  OUTPUT lexer.cpp
  COMMAND ${RE2C} -olexer.cpp ${PROJECT_SOURCE_DIR}/expr_lexer.re
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/expr_lexer.re
)

add_custom_command (
  OUTPUT Parser.cpp tokens.h
  COMMAND bison -oParser.cpp -rall --defines=tokens.h ${PROJECT_SOURCE_DIR}/Parser.y
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/Parser.y
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})


add_executable(${PROJECT_NAME} 
                        lexer.cpp
                        Parser.cpp
                        main.cpp)

