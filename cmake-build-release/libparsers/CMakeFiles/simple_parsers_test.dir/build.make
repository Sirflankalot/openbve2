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

# Include any dependencies generated for this target.
include libparsers/CMakeFiles/simple_parsers_test.dir/depend.make

# Include the progress variables for this target.
include libparsers/CMakeFiles/simple_parsers_test.dir/progress.make

# Include the compile flags for this target's objects.
include libparsers/CMakeFiles/simple_parsers_test.dir/flags.make

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

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o: ../libparsers/tests/simple_tests/main.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/main.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/main.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/main.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o: ../libparsers/tests/simple_tests/test_animated.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_animated.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_animated.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_animated.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o: ../libparsers/tests/simple_tests/test_csv.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o: ../libparsers/tests/simple_tests/test_csv_obj.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_obj.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_obj.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_obj.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o: ../libparsers/tests/simple_tests/test_csv_route.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_route.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_route.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_csv_route.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o: ../libparsers/tests/simple_tests/test_fs.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_fs.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_fs.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_fs.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o


libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o: libparsers/CMakeFiles/simple_parsers_test.dir/flags.make
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o: ../libparsers/tests/simple_tests/test_math.cpp
libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o -c /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_math.cpp

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.i"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_math.cpp > CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.i

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.s"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kevincybura/Desktop/c++/openbve2/libparsers/tests/simple_tests/test_math.cpp -o CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.s

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.requires:

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.requires

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.provides: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.requires
	$(MAKE) -f libparsers/CMakeFiles/simple_parsers_test.dir/build.make libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.provides.build
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.provides

libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.provides.build: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o


# Object files for target simple_parsers_test
simple_parsers_test_OBJECTS = \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o" \
"CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o"

# External object files for target simple_parsers_test
simple_parsers_test_EXTERNAL_OBJECTS =

bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/build.make
bin/simple_parsers_test: bin/libparsers.so
bin/simple_parsers_test: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
bin/simple_parsers_test: bin/libcore.so
bin/simple_parsers_test: /usr/lib/x86_64-linux-gnu/libboost_regex.so
bin/simple_parsers_test: /usr/lib/x86_64-linux-gnu/libboost_system.so
bin/simple_parsers_test: libparsers/CMakeFiles/simple_parsers_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kevincybura/Desktop/c++/openbve2/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable ../bin/simple_parsers_test"
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_parsers_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libparsers/CMakeFiles/simple_parsers_test.dir/build: bin/simple_parsers_test

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/build

libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/main.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_animated.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_obj.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_csv_route.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_fs.cpp.o.requires
libparsers/CMakeFiles/simple_parsers_test.dir/requires: libparsers/CMakeFiles/simple_parsers_test.dir/tests/simple_tests/test_math.cpp.o.requires

.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/requires

libparsers/CMakeFiles/simple_parsers_test.dir/clean:
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers && $(CMAKE_COMMAND) -P CMakeFiles/simple_parsers_test.dir/cmake_clean.cmake
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/clean

libparsers/CMakeFiles/simple_parsers_test.dir/depend: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx.gch
libparsers/CMakeFiles/simple_parsers_test.dir/depend: libparsers/cotire/simple_parsers_test_CXX_prefix.hxx
libparsers/CMakeFiles/simple_parsers_test.dir/depend: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx
libparsers/CMakeFiles/simple_parsers_test.dir/depend: libparsers/cotire/simple_parsers_test_CXX_prefix.cxx.log
libparsers/CMakeFiles/simple_parsers_test.dir/depend: libparsers/cotire/simple_parsers_test_CXX_unity.cxx
	cd /home/kevincybura/Desktop/c++/openbve2/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevincybura/Desktop/c++/openbve2 /home/kevincybura/Desktop/c++/openbve2/libparsers /home/kevincybura/Desktop/c++/openbve2/cmake-build-release /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers /home/kevincybura/Desktop/c++/openbve2/cmake-build-release/libparsers/CMakeFiles/simple_parsers_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libparsers/CMakeFiles/simple_parsers_test.dir/depend

