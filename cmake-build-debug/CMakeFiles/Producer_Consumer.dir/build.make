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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lamp/Programming/Producer_Consumer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lamp/Programming/Producer_Consumer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Producer_Consumer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Producer_Consumer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Producer_Consumer.dir/flags.make

CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o: CMakeFiles/Producer_Consumer.dir/flags.make
CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o: ../soruces/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lamp/Programming/Producer_Consumer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o -c /home/lamp/Programming/Producer_Consumer/soruces/main.cpp

CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lamp/Programming/Producer_Consumer/soruces/main.cpp > CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.i

CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lamp/Programming/Producer_Consumer/soruces/main.cpp -o CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.s

# Object files for target Producer_Consumer
Producer_Consumer_OBJECTS = \
"CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o"

# External object files for target Producer_Consumer
Producer_Consumer_EXTERNAL_OBJECTS =

Producer_Consumer: CMakeFiles/Producer_Consumer.dir/soruces/main.cpp.o
Producer_Consumer: CMakeFiles/Producer_Consumer.dir/build.make
Producer_Consumer: libconsoled.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_log-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_log_setup-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_thread-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_system-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_filesystem-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_program_options-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_log-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_log_setup-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_thread-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_system-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_filesystem-mt-d-x64.a
Producer_Consumer: /home/lamp/.hunter/_Base/35fa55b/252be92/b78b2c5/Install/lib/libboost_program_options-mt-d-x64.a
Producer_Consumer: CMakeFiles/Producer_Consumer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lamp/Programming/Producer_Consumer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Producer_Consumer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Producer_Consumer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Producer_Consumer.dir/build: Producer_Consumer

.PHONY : CMakeFiles/Producer_Consumer.dir/build

CMakeFiles/Producer_Consumer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Producer_Consumer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Producer_Consumer.dir/clean

CMakeFiles/Producer_Consumer.dir/depend:
	cd /home/lamp/Programming/Producer_Consumer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lamp/Programming/Producer_Consumer /home/lamp/Programming/Producer_Consumer /home/lamp/Programming/Producer_Consumer/cmake-build-debug /home/lamp/Programming/Producer_Consumer/cmake-build-debug /home/lamp/Programming/Producer_Consumer/cmake-build-debug/CMakeFiles/Producer_Consumer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Producer_Consumer.dir/depend

