# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chris/repos/DIT_OOP_PROJECT_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chris/repos/DIT_OOP_PROJECT_1/build

# Include any dependencies generated for this target.
include CMakeFiles/DIT_OOP_PROJECT_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DIT_OOP_PROJECT_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DIT_OOP_PROJECT_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DIT_OOP_PROJECT_1.dir/flags.make

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/flags.make
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o: /home/chris/repos/DIT_OOP_PROJECT_1/source/pomodoro.cpp
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o -MF CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o.d -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o -c /home/chris/repos/DIT_OOP_PROJECT_1/source/pomodoro.cpp

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/repos/DIT_OOP_PROJECT_1/source/pomodoro.cpp > CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.i

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/repos/DIT_OOP_PROJECT_1/source/pomodoro.cpp -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.s

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/flags.make
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o: /home/chris/repos/DIT_OOP_PROJECT_1/source/mainFrame.cpp
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o -MF CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o.d -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o -c /home/chris/repos/DIT_OOP_PROJECT_1/source/mainFrame.cpp

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/repos/DIT_OOP_PROJECT_1/source/mainFrame.cpp > CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.i

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/repos/DIT_OOP_PROJECT_1/source/mainFrame.cpp -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.s

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/flags.make
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o: /home/chris/repos/DIT_OOP_PROJECT_1/source/myApp.cpp
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o -MF CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o.d -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o -c /home/chris/repos/DIT_OOP_PROJECT_1/source/myApp.cpp

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/repos/DIT_OOP_PROJECT_1/source/myApp.cpp > CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.i

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/repos/DIT_OOP_PROJECT_1/source/myApp.cpp -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.s

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/flags.make
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o: /home/chris/repos/DIT_OOP_PROJECT_1/source/database.cpp
CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o: CMakeFiles/DIT_OOP_PROJECT_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o -MF CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o.d -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o -c /home/chris/repos/DIT_OOP_PROJECT_1/source/database.cpp

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chris/repos/DIT_OOP_PROJECT_1/source/database.cpp > CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.i

CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chris/repos/DIT_OOP_PROJECT_1/source/database.cpp -o CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.s

# Object files for target DIT_OOP_PROJECT_1
DIT_OOP_PROJECT_1_OBJECTS = \
"CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o" \
"CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o" \
"CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o" \
"CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o"

# External object files for target DIT_OOP_PROJECT_1
DIT_OOP_PROJECT_1_EXTERNAL_OBJECTS =

DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/source/pomodoro.cpp.o
DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/source/mainFrame.cpp.o
DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/source/myApp.cpp.o
DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/source/database.cpp.o
DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/build.make
DIT_OOP_PROJECT_1: CMakeFiles/DIT_OOP_PROJECT_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DIT_OOP_PROJECT_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DIT_OOP_PROJECT_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DIT_OOP_PROJECT_1.dir/build: DIT_OOP_PROJECT_1
.PHONY : CMakeFiles/DIT_OOP_PROJECT_1.dir/build

CMakeFiles/DIT_OOP_PROJECT_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DIT_OOP_PROJECT_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DIT_OOP_PROJECT_1.dir/clean

CMakeFiles/DIT_OOP_PROJECT_1.dir/depend:
	cd /home/chris/repos/DIT_OOP_PROJECT_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chris/repos/DIT_OOP_PROJECT_1 /home/chris/repos/DIT_OOP_PROJECT_1 /home/chris/repos/DIT_OOP_PROJECT_1/build /home/chris/repos/DIT_OOP_PROJECT_1/build /home/chris/repos/DIT_OOP_PROJECT_1/build/CMakeFiles/DIT_OOP_PROJECT_1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DIT_OOP_PROJECT_1.dir/depend
