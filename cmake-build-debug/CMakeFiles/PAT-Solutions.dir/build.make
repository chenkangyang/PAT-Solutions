# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alex/Documents/projects/git_repos/PAT-Solutions

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PAT-Solutions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PAT-Solutions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PAT-Solutions.dir/flags.make

CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o: CMakeFiles/PAT-Solutions.dir/flags.make
CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o: ../Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o "CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o" -c "/Users/alex/Documents/projects/git_repos/PAT-Solutions/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp"

CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/alex/Documents/projects/git_repos/PAT-Solutions/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp" > "CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.i"

CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/alex/Documents/projects/git_repos/PAT-Solutions/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp" -o "CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.s"

# Object files for target PAT-Solutions
PAT__Solutions_OBJECTS = \
"CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o"

# External object files for target PAT-Solutions
PAT__Solutions_EXTERNAL_OBJECTS =

PAT-Solutions: CMakeFiles/PAT-Solutions.dir/Basic/1001-害死人不偿命的(3n+1)猜想(15分).cpp.o
PAT-Solutions: CMakeFiles/PAT-Solutions.dir/build.make
PAT-Solutions: CMakeFiles/PAT-Solutions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PAT-Solutions"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PAT-Solutions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PAT-Solutions.dir/build: PAT-Solutions

.PHONY : CMakeFiles/PAT-Solutions.dir/build

CMakeFiles/PAT-Solutions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PAT-Solutions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PAT-Solutions.dir/clean

CMakeFiles/PAT-Solutions.dir/depend:
	cd /Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alex/Documents/projects/git_repos/PAT-Solutions /Users/alex/Documents/projects/git_repos/PAT-Solutions /Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug /Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug /Users/alex/Documents/projects/git_repos/PAT-Solutions/cmake-build-debug/CMakeFiles/PAT-Solutions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PAT-Solutions.dir/depend
