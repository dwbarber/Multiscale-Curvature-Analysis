# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /nix/store/24gbi6mcw4c6jgzai9aaxx9qi2rxdb09-cmake-3.29.6/bin/cmake

# The command to remove a file.
RM = /nix/store/24gbi6mcw4c6jgzai9aaxx9qi2rxdb09-cmake-3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gavin4d/programming/Multiscale-Curvature-Analysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gavin4d/programming/Multiscale-Curvature-Analysis

# Include any dependencies generated for this target.
include CMakeFiles/gui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gui.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gui.dir/flags.make

CMakeFiles/gui.dir/gui.cpp.o: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/gui.cpp.o: gui.cpp
CMakeFiles/gui.dir/gui.cpp.o: CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gavin4d/programming/Multiscale-Curvature-Analysis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gui.dir/gui.cpp.o"
	/nix/store/vh9fsdhgxcnab2qk7vdp2palkkn6j3cp-gcc-wrapper-13.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui.dir/gui.cpp.o -MF CMakeFiles/gui.dir/gui.cpp.o.d -o CMakeFiles/gui.dir/gui.cpp.o -c /home/gavin4d/programming/Multiscale-Curvature-Analysis/gui.cpp

CMakeFiles/gui.dir/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gui.dir/gui.cpp.i"
	/nix/store/vh9fsdhgxcnab2qk7vdp2palkkn6j3cp-gcc-wrapper-13.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gavin4d/programming/Multiscale-Curvature-Analysis/gui.cpp > CMakeFiles/gui.dir/gui.cpp.i

CMakeFiles/gui.dir/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gui.dir/gui.cpp.s"
	/nix/store/vh9fsdhgxcnab2qk7vdp2palkkn6j3cp-gcc-wrapper-13.3.0/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gavin4d/programming/Multiscale-Curvature-Analysis/gui.cpp -o CMakeFiles/gui.dir/gui.cpp.s

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/gui.cpp.o"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

libgui.a: CMakeFiles/gui.dir/gui.cpp.o
libgui.a: CMakeFiles/gui.dir/build.make
libgui.a: CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gavin4d/programming/Multiscale-Curvature-Analysis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgui.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gui.dir/build: libgui.a
.PHONY : CMakeFiles/gui.dir/build

CMakeFiles/gui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gui.dir/clean

CMakeFiles/gui.dir/depend:
	cd /home/gavin4d/programming/Multiscale-Curvature-Analysis && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gavin4d/programming/Multiscale-Curvature-Analysis /home/gavin4d/programming/Multiscale-Curvature-Analysis /home/gavin4d/programming/Multiscale-Curvature-Analysis /home/gavin4d/programming/Multiscale-Curvature-Analysis /home/gavin4d/programming/Multiscale-Curvature-Analysis/CMakeFiles/gui.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/gui.dir/depend

