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

# Utility rule file for test_main_pch.

# Include the progress variables for this target.
include test_main/CMakeFiles/test_main_pch.dir/progress.make

test_main/CMakeFiles/test_main_pch: test_main/cotire/test_main_CXX_prefix.hxx.gch


test_main/cotire/test_main_CXX_prefix.hxx.gch: test_main/cotire/test_main_CXX_prefix.hxx
test_main/cotire/test_main_CXX_prefix.hxx.gch: /usr/bin/c++
test_main/cotire/test_main_CXX_prefix.hxx.gch: test_main/cotire/test_main_CXX_prefix.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX precompiled header test_main/cotire/test_main_CXX_prefix.hxx.gch"
	cd /home/kevincybura/Desktop/c++/openbve2/test_main && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake precompile /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/test_main_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_prefix.hxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_prefix.hxx.gch main.cpp

test_main/cotire/test_main_CXX_prefix.hxx: test_main/cotire/test_main_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CXX prefix header test_main/cotire/test_main_CXX_prefix.hxx"
	/home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake combine /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/test_main_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_prefix.hxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_prefix.cxx

test_main/cotire/test_main_CXX_prefix.cxx: test_main/cotire/test_main_CXX_unity.cxx
test_main/cotire/test_main_CXX_prefix.cxx: /usr/bin/c++
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating CXX prefix source test_main/cotire/test_main_CXX_prefix.cxx"
	cd /home/kevincybura/Desktop/c++/openbve2/test_main && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake prefix /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/test_main_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_prefix.cxx /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_unity.cxx

test_main/cotire/test_main_CXX_prefix.cxx.log: test_main/cotire/test_main_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate test_main/cotire/test_main_CXX_prefix.cxx.log

test_main/cotire/test_main_CXX_unity.cxx: test_main/test_main_CXX_cotire.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating CXX unity source test_main/cotire/test_main_CXX_unity.cxx"
	cd /home/kevincybura/Desktop/c++/openbve2/test_main && /home/kevincybura/Desktop/clion-2018.1.3/bin/cmake/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/kevincybura/Desktop/c++/openbve2/dependencies/cotire/CMake/cotire.cmake unity /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/test_main_CXX_cotire.cmake /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/cotire/test_main_CXX_unity.cxx

test_main_pch: test_main/CMakeFiles/test_main_pch
test_main_pch: test_main/cotire/test_main_CXX_prefix.hxx.gch
test_main_pch: test_main/cotire/test_main_CXX_prefix.hxx
test_main_pch: test_main/cotire/test_main_CXX_prefix.cxx
test_main_pch: test_main/cotire/test_main_CXX_prefix.cxx.log
test_main_pch: test_main/cotire/test_main_CXX_unity.cxx
test_main_pch: test_main/CMakeFiles/test_main_pch.dir/build.make

.PHONY : test_main_pch

# Rule to build all files generated by this target.
test_main/CMakeFiles/test_main_pch.dir/build: test_main_pch

.PHONY : test_main/CMakeFiles/test_main_pch.dir/build

test_main/CMakeFiles/test_main_pch.dir/clean:
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main && $(CMAKE_COMMAND) -P CMakeFiles/test_main_pch.dir/cmake_clean.cmake
.PHONY : test_main/CMakeFiles/test_main_pch.dir/clean

test_main/CMakeFiles/test_main_pch.dir/depend:
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevincybura/Desktop/c++/openbve2 /home/kevincybura/Desktop/c++/openbve2/test_main /home/kevincybura/Desktop/c++/openbve2/cmake-build-release /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/test_main/CMakeFiles/test_main_pch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test_main/CMakeFiles/test_main_pch.dir/depend

