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
CMAKE_COMMAND = /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevincybura/Desktop/c++/openbve2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevincybura/Desktop/c++/openbve2/cmake-build-release

# Utility rule file for simple_parsers_test_pch.

# Include the progress variables for this target.
include libparsers/CMakeFiles/simple_parsers_test_pch.dir/progress.make

libparsers/CMakeFiles/simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch


libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx
libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch: /usr/bin/c++
libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX precompiled header libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch"
	cd /home/kevincybura/Desktop/c++/openbve2/libparsers && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake precompile /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/simple_parsers_test_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_prefix.hxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch tests/simple_tests/main.cpp

libparsers/cotire/simple_parsers_test_CXX_prefix.hxx: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CXX prefix header libparsers/cotire/simple_parsers_test_CXX_prefix.hxx"
	/home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake combine /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/simple_parsers_test_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_prefix.hxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_prefix.cxx

libparsers/cotire/simple_parsers_test_CXX_prefix.cxx: libparsers/cotire/simple_parsers_test_CXX_unity.cxx
libparsers/cotire/simple_parsers_test_CXX_prefix.cxx: /usr/bin/c++
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating CXX prefix source libparsers/cotire/simple_parsers_test_CXX_prefix.cxx"
	cd /home/kevincybura/Desktop/c++/openbve2/libparsers && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake prefix /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/simple_parsers_test_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_prefix.cxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_unity.cxx

libparsers/cotire/simple_parsers_test_CXX_prefix.cxx.log: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate libparsers/cotire/simple_parsers_test_CXX_prefix.cxx.log

libparsers/cotire/simple_parsers_test_CXX_unity.cxx: libparsers/simple_parsers_test_CXX_cotire.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating CXX unity source libparsers/cotire/simple_parsers_test_CXX_unity.cxx"
	cd /home/kevincybura/Desktop/c++/openbve2/libparsers && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake unity /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/simple_parsers_test_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/cotire/simple_parsers_test_CXX_unity.cxx

simple_parsers_test_pch: libparsers/CMakeFiles/simple_parsers_test_pch
simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx
simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx
simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx.log
simple_parsers_test_pch: libparsers/cotire/simple_parsers_test_CXX_unity.cxx
simple_parsers_test_pch: libparsers/CMakeFiles/simple_parsers_test_pch.dir/build.make

.PHONY : simple_parsers_test_pch

# Rule to build all files generated by this target.
libparsers/CMakeFiles/simple_parsers_test_pch.dir/build: simple_parsers_test_pch

.PHONY : libparsers/CMakeFiles/simple_parsers_test_pch.dir/build

libparsers/CMakeFiles/simple_parsers_test_pch.dir/clean:
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && $(CMAKE_COMMAND) -P CMakeFiles/simple_parsers_test_pch.dir/cmake_clean.cmake
.PHONY : libparsers/CMakeFiles/simple_parsers_test_pch.dir/clean

libparsers/CMakeFiles/simple_parsers_test_pch.dir/depend:
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevincybura/Desktop/c++/openbve2 /home/kevincybura/Desktop/c++/openbve2/libparsers /home/kevincybura/Desktop/c++/openbve2/cmake-build-release /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/CMakeFiles/simple_parsers_test_pch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libparsers/CMakeFiles/simple_parsers_test_pch.dir/depend

