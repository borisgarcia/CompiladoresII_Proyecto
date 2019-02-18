# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/boris/Desktop/CompiladoresII/Proyecto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/boris/Desktop/CompiladoresII/Proyecto/build

# Include any dependencies generated for this target.
include CMakeFiles/test_parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_parser.dir/flags.make

lexer.cpp: ../expr_lexer.re
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating lexer.cpp"
	/usr/local/bin/re2c -olexer.cpp /home/boris/Desktop/CompiladoresII/Proyecto/expr_lexer.re

Parser.cpp: ../Parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating Parser.cpp, tokens.h"
	bison -oParser.cpp -rall --defines=tokens.h /home/boris/Desktop/CompiladoresII/Proyecto/Parser.y

tokens.h: Parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate tokens.h

CMakeFiles/test_parser.dir/lexer.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/lexer.cpp.o: lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_parser.dir/lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/lexer.cpp.o -c /home/boris/Desktop/CompiladoresII/Proyecto/build/lexer.cpp

CMakeFiles/test_parser.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boris/Desktop/CompiladoresII/Proyecto/build/lexer.cpp > CMakeFiles/test_parser.dir/lexer.cpp.i

CMakeFiles/test_parser.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boris/Desktop/CompiladoresII/Proyecto/build/lexer.cpp -o CMakeFiles/test_parser.dir/lexer.cpp.s

CMakeFiles/test_parser.dir/lexer.cpp.o.requires:

.PHONY : CMakeFiles/test_parser.dir/lexer.cpp.o.requires

CMakeFiles/test_parser.dir/lexer.cpp.o.provides: CMakeFiles/test_parser.dir/lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_parser.dir/build.make CMakeFiles/test_parser.dir/lexer.cpp.o.provides.build
.PHONY : CMakeFiles/test_parser.dir/lexer.cpp.o.provides

CMakeFiles/test_parser.dir/lexer.cpp.o.provides.build: CMakeFiles/test_parser.dir/lexer.cpp.o


CMakeFiles/test_parser.dir/Parser.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/Parser.cpp.o: Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_parser.dir/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/Parser.cpp.o -c /home/boris/Desktop/CompiladoresII/Proyecto/build/Parser.cpp

CMakeFiles/test_parser.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boris/Desktop/CompiladoresII/Proyecto/build/Parser.cpp > CMakeFiles/test_parser.dir/Parser.cpp.i

CMakeFiles/test_parser.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boris/Desktop/CompiladoresII/Proyecto/build/Parser.cpp -o CMakeFiles/test_parser.dir/Parser.cpp.s

CMakeFiles/test_parser.dir/Parser.cpp.o.requires:

.PHONY : CMakeFiles/test_parser.dir/Parser.cpp.o.requires

CMakeFiles/test_parser.dir/Parser.cpp.o.provides: CMakeFiles/test_parser.dir/Parser.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_parser.dir/build.make CMakeFiles/test_parser.dir/Parser.cpp.o.provides.build
.PHONY : CMakeFiles/test_parser.dir/Parser.cpp.o.provides

CMakeFiles/test_parser.dir/Parser.cpp.o.provides.build: CMakeFiles/test_parser.dir/Parser.cpp.o


CMakeFiles/test_parser.dir/main.cpp.o: CMakeFiles/test_parser.dir/flags.make
CMakeFiles/test_parser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test_parser.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_parser.dir/main.cpp.o -c /home/boris/Desktop/CompiladoresII/Proyecto/main.cpp

CMakeFiles/test_parser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_parser.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/boris/Desktop/CompiladoresII/Proyecto/main.cpp > CMakeFiles/test_parser.dir/main.cpp.i

CMakeFiles/test_parser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_parser.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/boris/Desktop/CompiladoresII/Proyecto/main.cpp -o CMakeFiles/test_parser.dir/main.cpp.s

CMakeFiles/test_parser.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/test_parser.dir/main.cpp.o.requires

CMakeFiles/test_parser.dir/main.cpp.o.provides: CMakeFiles/test_parser.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_parser.dir/build.make CMakeFiles/test_parser.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/test_parser.dir/main.cpp.o.provides

CMakeFiles/test_parser.dir/main.cpp.o.provides.build: CMakeFiles/test_parser.dir/main.cpp.o


# Object files for target test_parser
test_parser_OBJECTS = \
"CMakeFiles/test_parser.dir/lexer.cpp.o" \
"CMakeFiles/test_parser.dir/Parser.cpp.o" \
"CMakeFiles/test_parser.dir/main.cpp.o"

# External object files for target test_parser
test_parser_EXTERNAL_OBJECTS =

test_parser: CMakeFiles/test_parser.dir/lexer.cpp.o
test_parser: CMakeFiles/test_parser.dir/Parser.cpp.o
test_parser: CMakeFiles/test_parser.dir/main.cpp.o
test_parser: CMakeFiles/test_parser.dir/build.make
test_parser: CMakeFiles/test_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable test_parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_parser.dir/build: test_parser

.PHONY : CMakeFiles/test_parser.dir/build

CMakeFiles/test_parser.dir/requires: CMakeFiles/test_parser.dir/lexer.cpp.o.requires
CMakeFiles/test_parser.dir/requires: CMakeFiles/test_parser.dir/Parser.cpp.o.requires
CMakeFiles/test_parser.dir/requires: CMakeFiles/test_parser.dir/main.cpp.o.requires

.PHONY : CMakeFiles/test_parser.dir/requires

CMakeFiles/test_parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_parser.dir/clean

CMakeFiles/test_parser.dir/depend: lexer.cpp
CMakeFiles/test_parser.dir/depend: Parser.cpp
CMakeFiles/test_parser.dir/depend: tokens.h
	cd /home/boris/Desktop/CompiladoresII/Proyecto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/boris/Desktop/CompiladoresII/Proyecto /home/boris/Desktop/CompiladoresII/Proyecto /home/boris/Desktop/CompiladoresII/Proyecto/build /home/boris/Desktop/CompiladoresII/Proyecto/build /home/boris/Desktop/CompiladoresII/Proyecto/build/CMakeFiles/test_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_parser.dir/depend

