# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DT_lab_1_Simplex_Method.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DT_lab_1_Simplex_Method.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DT_lab_1_Simplex_Method.dir/flags.make

CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.obj: CMakeFiles/DT_lab_1_Simplex_Method.dir/flags.make
CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.obj"
	G:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DT_lab_1_Simplex_Method.dir\main.cpp.obj -c C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\main.cpp

CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.i"
	G:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\main.cpp > CMakeFiles\DT_lab_1_Simplex_Method.dir\main.cpp.i

CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.s"
	G:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\main.cpp -o CMakeFiles\DT_lab_1_Simplex_Method.dir\main.cpp.s

# Object files for target DT_lab_1_Simplex_Method
DT_lab_1_Simplex_Method_OBJECTS = \
"CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.obj"

# External object files for target DT_lab_1_Simplex_Method
DT_lab_1_Simplex_Method_EXTERNAL_OBJECTS =

DT_lab_1_Simplex_Method.exe: CMakeFiles/DT_lab_1_Simplex_Method.dir/main.cpp.obj
DT_lab_1_Simplex_Method.exe: CMakeFiles/DT_lab_1_Simplex_Method.dir/build.make
DT_lab_1_Simplex_Method.exe: CMakeFiles/DT_lab_1_Simplex_Method.dir/linklibs.rsp
DT_lab_1_Simplex_Method.exe: CMakeFiles/DT_lab_1_Simplex_Method.dir/objects1.rsp
DT_lab_1_Simplex_Method.exe: CMakeFiles/DT_lab_1_Simplex_Method.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DT_lab_1_Simplex_Method.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DT_lab_1_Simplex_Method.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DT_lab_1_Simplex_Method.dir/build: DT_lab_1_Simplex_Method.exe

.PHONY : CMakeFiles/DT_lab_1_Simplex_Method.dir/build

CMakeFiles/DT_lab_1_Simplex_Method.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DT_lab_1_Simplex_Method.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DT_lab_1_Simplex_Method.dir/clean

CMakeFiles/DT_lab_1_Simplex_Method.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug C:\Users\Slava\CLionProjects\DT_lab_1_Simplex_Method\cmake-build-debug\CMakeFiles\DT_lab_1_Simplex_Method.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DT_lab_1_Simplex_Method.dir/depend

