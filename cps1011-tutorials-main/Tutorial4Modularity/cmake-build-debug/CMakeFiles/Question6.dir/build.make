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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Labs4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Question6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Question6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Question6.dir/flags.make

CMakeFiles/Question6.dir/Question6.c.obj: CMakeFiles/Question6.dir/flags.make
CMakeFiles/Question6.dir/Question6.c.obj: ../Question6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Question6.dir/Question6.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Question6.dir\Question6.c.obj -c C:\Users\User\Documents\CProjects\Labs4\Question6.c

CMakeFiles/Question6.dir/Question6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Question6.dir/Question6.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs4\Question6.c > CMakeFiles\Question6.dir\Question6.c.i

CMakeFiles/Question6.dir/Question6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Question6.dir/Question6.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs4\Question6.c -o CMakeFiles\Question6.dir\Question6.c.s

# Object files for target Question6
Question6_OBJECTS = \
"CMakeFiles/Question6.dir/Question6.c.obj"

# External object files for target Question6
Question6_EXTERNAL_OBJECTS =

Question6.exe: CMakeFiles/Question6.dir/Question6.c.obj
Question6.exe: CMakeFiles/Question6.dir/build.make
Question6.exe: CMakeFiles/Question6.dir/linklibs.rsp
Question6.exe: CMakeFiles/Question6.dir/objects1.rsp
Question6.exe: CMakeFiles/Question6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Question6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Question6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Question6.dir/build: Question6.exe
.PHONY : CMakeFiles/Question6.dir/build

CMakeFiles/Question6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Question6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Question6.dir/clean

CMakeFiles/Question6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs4 C:\Users\User\Documents\CProjects\Labs4 C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug C:\Users\User\Documents\CProjects\Labs4\cmake-build-debug\CMakeFiles\Question6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Question6.dir/depend

