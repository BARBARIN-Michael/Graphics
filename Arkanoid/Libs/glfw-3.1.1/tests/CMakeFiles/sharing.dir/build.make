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
include tests/CMakeFiles/sharing.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/sharing.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/sharing.dir/flags.make

tests/CMakeFiles/sharing.dir/sharing.c.o: tests/CMakeFiles/sharing.dir/flags.make
tests/CMakeFiles/sharing.dir/sharing.c.o: tests/sharing.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object tests/CMakeFiles/sharing.dir/sharing.c.o"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/sharing.dir/sharing.c.o   -c /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/sharing.c

tests/CMakeFiles/sharing.dir/sharing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sharing.dir/sharing.c.i"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/sharing.c > CMakeFiles/sharing.dir/sharing.c.i

tests/CMakeFiles/sharing.dir/sharing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sharing.dir/sharing.c.s"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/sharing.c -o CMakeFiles/sharing.dir/sharing.c.s

tests/CMakeFiles/sharing.dir/sharing.c.o.requires:
.PHONY : tests/CMakeFiles/sharing.dir/sharing.c.o.requires

tests/CMakeFiles/sharing.dir/sharing.c.o.provides: tests/CMakeFiles/sharing.dir/sharing.c.o.requires
	$(MAKE) -f tests/CMakeFiles/sharing.dir/build.make tests/CMakeFiles/sharing.dir/sharing.c.o.provides.build
.PHONY : tests/CMakeFiles/sharing.dir/sharing.c.o.provides

tests/CMakeFiles/sharing.dir/sharing.c.o.provides.build: tests/CMakeFiles/sharing.dir/sharing.c.o

# Object files for target sharing
sharing_OBJECTS = \
"CMakeFiles/sharing.dir/sharing.c.o"

# External object files for target sharing
sharing_EXTERNAL_OBJECTS =

tests/sharing.app/Contents/MacOS/sharing: tests/CMakeFiles/sharing.dir/sharing.c.o
tests/sharing.app/Contents/MacOS/sharing: tests/CMakeFiles/sharing.dir/build.make
tests/sharing.app/Contents/MacOS/sharing: src/libglfw3.a
tests/sharing.app/Contents/MacOS/sharing: tests/CMakeFiles/sharing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable sharing.app/Contents/MacOS/sharing"
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/sharing.dir/build: tests/sharing.app/Contents/MacOS/sharing
.PHONY : tests/CMakeFiles/sharing.dir/build

tests/CMakeFiles/sharing.dir/requires: tests/CMakeFiles/sharing.dir/sharing.c.o.requires
.PHONY : tests/CMakeFiles/sharing.dir/requires

tests/CMakeFiles/sharing.dir/clean:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests && $(CMAKE_COMMAND) -P CMakeFiles/sharing.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/sharing.dir/clean

tests/CMakeFiles/sharing.dir/depend:
	cd /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1 /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests /Volumes/42_MBARBARI/graphics/Arkanoid/Libs/glfw-3.1.1/tests/CMakeFiles/sharing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/sharing.dir/depend

