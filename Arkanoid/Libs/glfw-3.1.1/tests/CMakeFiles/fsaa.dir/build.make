# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /Volumes/Data/nfs/zfs-student-2/users/2014/mbarbari/.brew/Cellar/cmake/3.2.1/bin/cmake

# The command to remove a file.
RM = /Volumes/Data/nfs/zfs-student-2/users/2014/mbarbari/.brew/Cellar/cmake/3.2.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1

# Include any dependencies generated for this target.
include tests/CMakeFiles/fsaa.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/fsaa.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/fsaa.dir/flags.make

tests/CMakeFiles/fsaa.dir/fsaa.c.o: tests/CMakeFiles/fsaa.dir/flags.make
tests/CMakeFiles/fsaa.dir/fsaa.c.o: tests/fsaa.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/fsaa.dir/fsaa.c.o"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/fsaa.dir/fsaa.c.o   -c /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/fsaa.c

tests/CMakeFiles/fsaa.dir/fsaa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fsaa.dir/fsaa.c.i"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/fsaa.c > CMakeFiles/fsaa.dir/fsaa.c.i

tests/CMakeFiles/fsaa.dir/fsaa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fsaa.dir/fsaa.c.s"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/fsaa.c -o CMakeFiles/fsaa.dir/fsaa.c.s

tests/CMakeFiles/fsaa.dir/fsaa.c.o.requires:
.PHONY : tests/CMakeFiles/fsaa.dir/fsaa.c.o.requires

tests/CMakeFiles/fsaa.dir/fsaa.c.o.provides: tests/CMakeFiles/fsaa.dir/fsaa.c.o.requires
	$(MAKE) -f tests/CMakeFiles/fsaa.dir/build.make tests/CMakeFiles/fsaa.dir/fsaa.c.o.provides.build
.PHONY : tests/CMakeFiles/fsaa.dir/fsaa.c.o.provides

tests/CMakeFiles/fsaa.dir/fsaa.c.o.provides.build: tests/CMakeFiles/fsaa.dir/fsaa.c.o

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o: tests/CMakeFiles/fsaa.dir/flags.make
tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o: deps/getopt.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/fsaa.dir/__/deps/getopt.c.o   -c /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/deps/getopt.c

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fsaa.dir/__/deps/getopt.c.i"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/deps/getopt.c > CMakeFiles/fsaa.dir/__/deps/getopt.c.i

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fsaa.dir/__/deps/getopt.c.s"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/deps/getopt.c -o CMakeFiles/fsaa.dir/__/deps/getopt.c.s

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.requires:
.PHONY : tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/fsaa.dir/build.make tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o

# Object files for target fsaa
fsaa_OBJECTS = \
"CMakeFiles/fsaa.dir/fsaa.c.o" \
"CMakeFiles/fsaa.dir/__/deps/getopt.c.o"

# External object files for target fsaa
fsaa_EXTERNAL_OBJECTS =

tests/fsaa: tests/CMakeFiles/fsaa.dir/fsaa.c.o
tests/fsaa: tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o
tests/fsaa: tests/CMakeFiles/fsaa.dir/build.make
tests/fsaa: src/libglfw3.a
tests/fsaa: tests/CMakeFiles/fsaa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable fsaa"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fsaa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/fsaa.dir/build: tests/fsaa
.PHONY : tests/CMakeFiles/fsaa.dir/build

tests/CMakeFiles/fsaa.dir/requires: tests/CMakeFiles/fsaa.dir/fsaa.c.o.requires
tests/CMakeFiles/fsaa.dir/requires: tests/CMakeFiles/fsaa.dir/__/deps/getopt.c.o.requires
.PHONY : tests/CMakeFiles/fsaa.dir/requires

tests/CMakeFiles/fsaa.dir/clean:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && $(CMAKE_COMMAND) -P CMakeFiles/fsaa.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/fsaa.dir/clean

tests/CMakeFiles/fsaa.dir/depend:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/CMakeFiles/fsaa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/fsaa.dir/depend

