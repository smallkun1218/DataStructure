# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "/Users/luck/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/221.5080.224/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/luck/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/221.5080.224/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/luck/Desktop/Code/CPP/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hafuman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Hafuman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Hafuman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hafuman.dir/flags.make

CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o: CMakeFiles/Hafuman.dir/flags.make
CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o: ../Tree/huffTree.cpp
CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o: CMakeFiles/Hafuman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o -MF CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o.d -o CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o -c /Users/luck/Desktop/Code/CPP/DataStructure/Tree/huffTree.cpp

CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.i"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/luck/Desktop/Code/CPP/DataStructure/Tree/huffTree.cpp > CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.i

CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.s"
	/usr/local/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/luck/Desktop/Code/CPP/DataStructure/Tree/huffTree.cpp -o CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.s

# Object files for target Hafuman
Hafuman_OBJECTS = \
"CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o"

# External object files for target Hafuman
Hafuman_EXTERNAL_OBJECTS =

Hafuman: CMakeFiles/Hafuman.dir/Tree/huffTree.cpp.o
Hafuman: CMakeFiles/Hafuman.dir/build.make
Hafuman: CMakeFiles/Hafuman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Hafuman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hafuman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hafuman.dir/build: Hafuman
.PHONY : CMakeFiles/Hafuman.dir/build

CMakeFiles/Hafuman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hafuman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hafuman.dir/clean

CMakeFiles/Hafuman.dir/depend:
	cd /Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/luck/Desktop/Code/CPP/DataStructure /Users/luck/Desktop/Code/CPP/DataStructure /Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug /Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug /Users/luck/Desktop/Code/CPP/DataStructure/cmake-build-debug/CMakeFiles/Hafuman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hafuman.dir/depend

