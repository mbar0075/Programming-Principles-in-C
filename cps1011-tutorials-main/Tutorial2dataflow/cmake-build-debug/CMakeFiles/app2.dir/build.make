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
include CMakeFiles/app2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/app2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app2.dir/flags.make

CMakeFiles/app2.dir/Question2.c.obj: CMakeFiles/app2.dir/flags.make
CMakeFiles/app2.dir/Question2.c.obj: ../Question2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app2.dir/Question2.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app2.dir\Question2.c.obj -c C:\Users\User\Documents\CProjects\Labs2\Question2.c

CMakeFiles/app2.dir/Question2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app2.dir/Question2.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Documents\CProjects\Labs2\Question2.c > CMakeFiles\app2.dir\Question2.c.i

CMakeFiles/app2.dir/Question2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app2.dir/Question2.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\User\Documents\CProjects\Labs2\Question2.c -o CMakeFiles\app2.dir\Question2.c.s

# Object files for target app2
app2_OBJECTS = \
"CMakeFiles/app2.dir/Question2.c.obj"

# External object files for target app2
app2_EXTERNAL_OBJECTS =

app2.exe: CMakeFiles/app2.dir/Question2.c.obj
app2.exe: CMakeFiles/app2.dir/build.make
app2.exe: CMakeFiles/app2.dir/linklibs.rsp
app2.exe: CMakeFiles/app2.dir/objects1.rsp
app2.exe: CMakeFiles/app2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable app2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app2.dir/build: app2.exe
.PHONY : CMakeFiles/app2.dir/build

CMakeFiles/app2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app2.dir/clean

CMakeFiles/app2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\CProjects\Labs2 C:\Users\User\Documents\CProjects\Labs2 C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug C:\Users\User\Documents\CProjects\Labs2\cmake-build-debug\CMakeFiles\app2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app2.dir/depend

