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
CMAKE_SOURCE_DIR = C:\Users\User\Documents\CProjects\Labs2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/app6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/app6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app6.dir/flags.make

CMakeFiles/app6.dir/Question6.c.obj: CMakeFiles/app6.dir/flags.make
CMakeFiles/app6.dir/Question6.c.obj: ../Question6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app6.dir/Question6.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app6.dir\Question6.c.obj -c C:\Users\User\Documents\CProjects\Labs2\Question6.c

CMakeFiles/app6.dir/Question6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app6.dir/Question6.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs2\Question6.c > CMakeFiles\app6.dir\Question6.c.i

CMakeFiles/app6.dir/Question6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app6.dir/Question6.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs2\Question6.c -o CMakeFiles\app6.dir\Question6.c.s

# Object files for target app6
app6_OBJECTS = \
"CMakeFiles/app6.dir/Question6.c.obj"

# External object files for target app6
app6_EXTERNAL_OBJECTS =

app6.exe: CMakeFiles/app6.dir/Question6.c.obj
app6.exe: CMakeFiles/app6.dir/build.make
app6.exe: CMakeFiles/app6.dir/linklibs.rsp
app6.exe: CMakeFiles/app6.dir/objects1.rsp
app6.exe: CMakeFiles/app6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable app6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app6.dir/build: app6.exe
.PHONY : CMakeFiles/app6.dir/build

CMakeFiles/app6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app6.dir/clean

CMakeFiles/app6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs2 C:\Users\User\Documents\CProjects\Labs2 C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles\app6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app6.dir/depend
