# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /userspace/apps/CLion/ch-0/203.3645.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /userspace/apps/CLion/ch-0/203.3645.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ray/Documents/DTTAH/windows/CLion/TaskManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TaskManager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TaskManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TaskManager.dir/flags.make

CMakeFiles/TaskManager.dir/main.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TaskManager.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaskManager.dir/main.cpp.o -c /home/ray/Documents/DTTAH/windows/CLion/TaskManager/main.cpp

CMakeFiles/TaskManager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ray/Documents/DTTAH/windows/CLion/TaskManager/main.cpp > CMakeFiles/TaskManager.dir/main.cpp.i

CMakeFiles/TaskManager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ray/Documents/DTTAH/windows/CLion/TaskManager/main.cpp -o CMakeFiles/TaskManager.dir/main.cpp.s

CMakeFiles/TaskManager.dir/Task.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/Task.cpp.o: ../Task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TaskManager.dir/Task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TaskManager.dir/Task.cpp.o -c /home/ray/Documents/DTTAH/windows/CLion/TaskManager/Task.cpp

CMakeFiles/TaskManager.dir/Task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/Task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ray/Documents/DTTAH/windows/CLion/TaskManager/Task.cpp > CMakeFiles/TaskManager.dir/Task.cpp.i

CMakeFiles/TaskManager.dir/Task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/Task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ray/Documents/DTTAH/windows/CLion/TaskManager/Task.cpp -o CMakeFiles/TaskManager.dir/Task.cpp.s

# Object files for target TaskManager
TaskManager_OBJECTS = \
"CMakeFiles/TaskManager.dir/main.cpp.o" \
"CMakeFiles/TaskManager.dir/Task.cpp.o"

# External object files for target TaskManager
TaskManager_EXTERNAL_OBJECTS =

TaskManager: CMakeFiles/TaskManager.dir/main.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/Task.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/build.make
TaskManager: CMakeFiles/TaskManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TaskManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TaskManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TaskManager.dir/build: TaskManager

.PHONY : CMakeFiles/TaskManager.dir/build

CMakeFiles/TaskManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TaskManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TaskManager.dir/clean

CMakeFiles/TaskManager.dir/depend:
	cd /home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ray/Documents/DTTAH/windows/CLion/TaskManager /home/ray/Documents/DTTAH/windows/CLion/TaskManager /home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug /home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug /home/ray/Documents/DTTAH/windows/CLion/TaskManager/cmake-build-debug/CMakeFiles/TaskManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TaskManager.dir/depend

