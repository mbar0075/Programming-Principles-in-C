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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Labs7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Question2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Question2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Question2.dir/flags.make

CMakeFiles/Question2.dir/Question2.c.obj: CMakeFiles/Question2.dir/flags.make
CMakeFiles/Question2.dir/Question2.c.obj: ../Question2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Question2.dir/Question2.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Question2.dir\Question2.c.obj -c C:\Users\User\Documents\CProjects\Labs7\Question2.c

CMakeFiles/Question2.dir/Question2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Question2.dir/Question2.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs7\Question2.c > CMakeFiles\Question2.dir\Question2.c.i

CMakeFiles/Question2.dir/Question2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Question2.dir/Question2.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs7\Question2.c -o CMakeFiles\Question2.dir\Question2.c.s

CMakeFiles/Question2.dir/sgets.c.obj: CMakeFiles/Question2.dir/flags.make
CMakeFiles/Question2.dir/sgets.c.obj: ../sgets.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Question2.dir/sgets.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Question2.dir\sgets.c.obj -c C:\Users\User\Documents\CProjects\Labs7\sgets.c

CMakeFiles/Question2.dir/sgets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Question2.dir/sgets.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs7\sgets.c > CMakeFiles\Question2.dir\sgets.c.i

CMakeFiles/Question2.dir/sgets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Question2.dir/sgets.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs7\sgets.c -o CMakeFiles\Question2.dir\sgets.c.s

# Object files for target Question2
Question2_OBJECTS = \
"CMakeFiles/Question2.dir/Question2.c.obj" \
"CMakeFiles/Question2.dir/sgets.c.obj"

# External object files for target Question2
Question2_EXTERNAL_OBJECTS =

Question2.exe: CMakeFiles/Question2.dir/Question2.c.obj
Question2.exe: CMakeFiles/Question2.dir/sgets.c.obj
Question2.exe: CMakeFiles/Question2.dir/build.make
Question2.exe: CMakeFiles/Question2.dir/linklibs.rsp
Question2.exe: CMakeFiles/Question2.dir/objects1.rsp
Question2.exe: CMakeFiles/Question2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Question2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Question2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Question2.dir/build: Question2.exe
.PHONY : CMakeFiles/Question2.dir/build

CMakeFiles/Question2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Question2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Question2.dir/clean

CMakeFiles/Question2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs7 C:\Users\User\Documents\CProjects\Labs7 C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug C:\Users\User\Documents\CProjects\Labs7\cmake-build-debug\CMakeFiles\Question2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Question2.dir/depend

