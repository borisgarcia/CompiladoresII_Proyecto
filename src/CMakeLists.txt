cmake_minimum_required (VERSION 2.6)
project(decaf)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(RE2C REQUIRED)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14" )

add_custom_command (
  OUTPUT ../src/lexer.cpp
  COMMAND ${RE2C} -o../src/lexer.cpp ${PROJECT_SOURCE_DIR}/expr_lexer.re
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/expr_lexer.re
)

add_custom_command (
  OUTPUT ../src/Parser.cpp tokens.h
  COMMAND bison -o../src/Parser.cpp -rall --defines=../src/tokens.h ${PROJECT_SOURCE_DIR}/Parser.y
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/Parser.y
)

add_custom_command(
  OUTPUT ../src/ast.cpp
  COMMAND /opt/treecc/bin/treecc -o ../src/ast.cpp ${PROJECT_SOURCE_DIR}/AST.tc
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/AST.tc
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})


add_executable(${PROJECT_NAME} 
                        lexer.cpp
                        Parser.cpp
                        ast.cpp
                        ident_handler.cpp                        
                        main.cpp)

