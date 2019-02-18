cmake_minimum_required (VERSION 2.6)
project(bisonEj2)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14" )

add_custom_command(
  OUTPUT ../parser.cpp tokens.h
  COMMAND bison -o ../parser.cpp -rall --defines=tokens.h ${PROJECT_SOURCE_DIR}/Parser.y
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/Parser.y
)

add_custom_command (
  OUTPUT ../lexer.cpp
  COMMAND re2c -o ../lexer.cpp ${PROJECT_SOURCE_DIR}/expr_lexer.re
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/expr_lexer.re
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} lexer.cpp parser.cpp ast.cpp main.cpp)
