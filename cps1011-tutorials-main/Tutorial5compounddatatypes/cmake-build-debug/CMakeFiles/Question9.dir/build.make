# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Labs5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Question9.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Question9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Question9.dir/flags.make

CMakeFiles/Question9.dir/Question9.c.obj: CMakeFiles/Question9.dir/flags.make
CMakeFiles/Question9.dir/Question9.c.obj: ../Question9.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Question9.dir/Question9.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Question9.dir\Question9.c.obj -c C:\Users\User\Documents\CProjects\Labs5\Question9.c

CMakeFiles/Question9.dir/Question9.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Question9.dir/Question9.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs5\Question9.c > CMakeFiles\Question9.dir\Question9.c.i

CMakeFiles/Question9.dir/Question9.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Question9.dir/Question9.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs5\Question9.c -o CMakeFiles\Question9.dir\Question9.c.s

# Object files for target Question9
Question9_OBJECTS = \
"CMakeFiles/Question9.dir/Question9.c.obj"

# External object files for target Question9
Question9_EXTERNAL_OBJECTS =

Question9.exe: CMakeFiles/Question9.dir/Question9.c.obj
Question9.exe: CMakeFiles/Question9.dir/build.make
Question9.exe: CMakeFiles/Question9.dir/linklibs.rsp
Question9.exe: CMakeFiles/Question9.dir/objects1.rsp
Question9.exe: CMakeFiles/Question9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Question9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Question9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Question9.dir/build: Question9.exe
.PHONY : CMakeFiles/Question9.dir/build

CMakeFiles/Question9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Question9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Question9.dir/clean

CMakeFiles/Question9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs5 C:\Users\User\Documents\CProjects\Labs5 C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug C:\Users\User\Documents\CProjects\Labs5\cmake-build-debug\CMakeFiles\Question9.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Question9.dir/depend

