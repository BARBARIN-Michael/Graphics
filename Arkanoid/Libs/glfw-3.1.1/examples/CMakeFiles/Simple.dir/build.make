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
include examples/CMakeFiles/Simple.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/Simple.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/Simple.dir/flags.make

examples/CMakeFiles/Simple.dir/simple.c.o: examples/CMakeFiles/Simple.dir/flags.make
examples/CMakeFiles/Simple.dir/simple.c.o: examples/simple.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object examples/CMakeFiles/Simple.dir/simple.c.o"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Simple.dir/simple.c.o   -c /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples/simple.c

examples/CMakeFiles/Simple.dir/simple.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Simple.dir/simple.c.i"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples/simple.c > CMakeFiles/Simple.dir/simple.c.i

examples/CMakeFiles/Simple.dir/simple.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Simple.dir/simple.c.s"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples/simple.c -o CMakeFiles/Simple.dir/simple.c.s

examples/CMakeFiles/Simple.dir/simple.c.o.requires:
.PHONY : examples/CMakeFiles/Simple.dir/simple.c.o.requires

examples/CMakeFiles/Simple.dir/simple.c.o.provides: examples/CMakeFiles/Simple.dir/simple.c.o.requires
	$(MAKE) -f examples/CMakeFiles/Simple.dir/build.make examples/CMakeFiles/Simple.dir/simple.c.o.provides.build
.PHONY : examples/CMakeFiles/Simple.dir/simple.c.o.provides

examples/CMakeFiles/Simple.dir/simple.c.o.provides.build: examples/CMakeFiles/Simple.dir/simple.c.o

# Object files for target Simple
Simple_OBJECTS = \
"CMakeFiles/Simple.dir/simple.c.o"

# External object files for target Simple
Simple_EXTERNAL_OBJECTS =

examples/Simple.app/Contents/MacOS/Simple: examples/CMakeFiles/Simple.dir/simple.c.o
examples/Simple.app/Contents/MacOS/Simple: examples/CMakeFiles/Simple.dir/build.make
examples/Simple.app/Contents/MacOS/Simple: src/libglfw3.a
examples/Simple.app/Contents/MacOS/Simple: examples/CMakeFiles/Simple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable Simple.app/Contents/MacOS/Simple"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Simple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/Simple.dir/build: examples/Simple.app/Contents/MacOS/Simple
.PHONY : examples/CMakeFiles/Simple.dir/build

examples/CMakeFiles/Simple.dir/requires: examples/CMakeFiles/Simple.dir/simple.c.o.requires
.PHONY : examples/CMakeFiles/Simple.dir/requires

examples/CMakeFiles/Simple.dir/clean:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples && $(CMAKE_COMMAND) -P CMakeFiles/Simple.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/Simple.dir/clean

examples/CMakeFiles/Simple.dir/depend:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/examples/CMakeFiles/Simple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/Simple.dir/depend

