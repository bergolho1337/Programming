# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/berg/Github/Programming/C/Priority-Queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/berg/Github/Programming/C/Priority-Queue/build

# Include any dependencies generated for this target.
include CMakeFiles/PriorityQueue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PriorityQueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PriorityQueue.dir/flags.make

CMakeFiles/PriorityQueue.dir/src/main.c.o: CMakeFiles/PriorityQueue.dir/flags.make
CMakeFiles/PriorityQueue.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/berg/Github/Programming/C/Priority-Queue/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PriorityQueue.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PriorityQueue.dir/src/main.c.o   -c /home/berg/Github/Programming/C/Priority-Queue/src/main.c

CMakeFiles/PriorityQueue.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PriorityQueue.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/berg/Github/Programming/C/Priority-Queue/src/main.c > CMakeFiles/PriorityQueue.dir/src/main.c.i

CMakeFiles/PriorityQueue.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PriorityQueue.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/berg/Github/Programming/C/Priority-Queue/src/main.c -o CMakeFiles/PriorityQueue.dir/src/main.c.s

# Object files for target PriorityQueue
PriorityQueue_OBJECTS = \
"CMakeFiles/PriorityQueue.dir/src/main.c.o"

# External object files for target PriorityQueue
PriorityQueue_EXTERNAL_OBJECTS =

../bin/PriorityQueue: CMakeFiles/PriorityQueue.dir/src/main.c.o
../bin/PriorityQueue: CMakeFiles/PriorityQueue.dir/build.make
../bin/PriorityQueue: src/queue/libpqueue.a
../bin/PriorityQueue: CMakeFiles/PriorityQueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/berg/Github/Programming/C/Priority-Queue/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/PriorityQueue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PriorityQueue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PriorityQueue.dir/build: ../bin/PriorityQueue

.PHONY : CMakeFiles/PriorityQueue.dir/build

CMakeFiles/PriorityQueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PriorityQueue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PriorityQueue.dir/clean

CMakeFiles/PriorityQueue.dir/depend:
	cd /home/berg/Github/Programming/C/Priority-Queue/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/berg/Github/Programming/C/Priority-Queue /home/berg/Github/Programming/C/Priority-Queue /home/berg/Github/Programming/C/Priority-Queue/build /home/berg/Github/Programming/C/Priority-Queue/build /home/berg/Github/Programming/C/Priority-Queue/build/CMakeFiles/PriorityQueue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PriorityQueue.dir/depend

