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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Labs8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/list2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/list2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list2.dir/flags.make

CMakeFiles/list2.dir/Question9list.c.obj: CMakeFiles/list2.dir/flags.make
CMakeFiles/list2.dir/Question9list.c.obj: ../Question9list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/list2.dir/Question9list.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\list2.dir\Question9list.c.obj -c C:\Users\User\Documents\CProjects\Labs8\Question9list.c

CMakeFiles/list2.dir/Question9list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list2.dir/Question9list.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs8\Question9list.c > CMakeFiles\list2.dir\Question9list.c.i

CMakeFiles/list2.dir/Question9list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list2.dir/Question9list.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs8\Question9list.c -o CMakeFiles\list2.dir\Question9list.c.s

# Object files for target list2
list2_OBJECTS = \
"CMakeFiles/list2.dir/Question9list.c.obj"

# External object files for target list2
list2_EXTERNAL_OBJECTS =

liblist2.a: CMakeFiles/list2.dir/Question9list.c.obj
liblist2.a: CMakeFiles/list2.dir/build.make
liblist2.a: CMakeFiles/list2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library liblist2.a"
	$(CMAKE_COMMAND) -P CMakeFiles\list2.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\list2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list2.dir/build: liblist2.a
.PHONY : CMakeFiles/list2.dir/build

CMakeFiles/list2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\list2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/list2.dir/clean

CMakeFiles/list2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs8 C:\Users\User\Documents\CProjects\Labs8 C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug C:\Users\User\Documents\CProjects\Labs8\cmake-build-debug\CMakeFiles\list2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list2.dir/depend

