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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Debugging1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/app3.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/app3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app3.dir/flags.make

CMakeFiles/app3.dir/Question1.c.obj: CMakeFiles/app3.dir/flags.make
CMakeFiles/app3.dir/Question1.c.obj: ../Question1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app3.dir/Question1.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app3.dir\Question1.c.obj -c C:\Users\User\Documents\CProjects\Debugging1\Question1.c

CMakeFiles/app3.dir/Question1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app3.dir/Question1.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Debugging1\Question1.c > CMakeFiles\app3.dir\Question1.c.i

CMakeFiles/app3.dir/Question1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app3.dir/Question1.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Debugging1\Question1.c -o CMakeFiles\app3.dir\Question1.c.s

# Object files for target app3
app3_OBJECTS = \
"CMakeFiles/app3.dir/Question1.c.obj"

# External object files for target app3
app3_EXTERNAL_OBJECTS =

app3.exe: CMakeFiles/app3.dir/Question1.c.obj
app3.exe: CMakeFiles/app3.dir/build.make
app3.exe: CMakeFiles/app3.dir/linklibs.rsp
app3.exe: CMakeFiles/app3.dir/objects1.rsp
app3.exe: CMakeFiles/app3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable app3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app3.dir/build: app3.exe
.PHONY : CMakeFiles/app3.dir/build

CMakeFiles/app3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app3.dir/clean

CMakeFiles/app3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Debugging1 C:\Users\User\Documents\CProjects\Debugging1 C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug C:\Users\User\Documents\CProjects\Debugging1\cmake-build-debug\CMakeFiles\app3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app3.dir/depend

