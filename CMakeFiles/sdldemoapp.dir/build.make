# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/emilcia/simsamples/01hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emilcia/simsamples/01hello

# Include any dependencies generated for this target.
include CMakeFiles/sdldemoapp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sdldemoapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sdldemoapp.dir/flags.make

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o: CMakeFiles/sdldemoapp.dir/flags.make
CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o: src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilcia/simsamples/01hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o -c /home/emilcia/simsamples/01hello/src/graphics.cpp

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdldemoapp.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilcia/simsamples/01hello/src/graphics.cpp > CMakeFiles/sdldemoapp.dir/src/graphics.cpp.i

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdldemoapp.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilcia/simsamples/01hello/src/graphics.cpp -o CMakeFiles/sdldemoapp.dir/src/graphics.cpp.s

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.requires:

.PHONY : CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.requires

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.provides: CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdldemoapp.dir/build.make CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.provides.build
.PHONY : CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.provides

CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.provides.build: CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o


CMakeFiles/sdldemoapp.dir/src/main.cpp.o: CMakeFiles/sdldemoapp.dir/flags.make
CMakeFiles/sdldemoapp.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilcia/simsamples/01hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sdldemoapp.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdldemoapp.dir/src/main.cpp.o -c /home/emilcia/simsamples/01hello/src/main.cpp

CMakeFiles/sdldemoapp.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdldemoapp.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilcia/simsamples/01hello/src/main.cpp > CMakeFiles/sdldemoapp.dir/src/main.cpp.i

CMakeFiles/sdldemoapp.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdldemoapp.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilcia/simsamples/01hello/src/main.cpp -o CMakeFiles/sdldemoapp.dir/src/main.cpp.s

CMakeFiles/sdldemoapp.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/sdldemoapp.dir/src/main.cpp.o.requires

CMakeFiles/sdldemoapp.dir/src/main.cpp.o.provides: CMakeFiles/sdldemoapp.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdldemoapp.dir/build.make CMakeFiles/sdldemoapp.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sdldemoapp.dir/src/main.cpp.o.provides

CMakeFiles/sdldemoapp.dir/src/main.cpp.o.provides.build: CMakeFiles/sdldemoapp.dir/src/main.cpp.o


CMakeFiles/sdldemoapp.dir/src/physics.cpp.o: CMakeFiles/sdldemoapp.dir/flags.make
CMakeFiles/sdldemoapp.dir/src/physics.cpp.o: src/physics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilcia/simsamples/01hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sdldemoapp.dir/src/physics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdldemoapp.dir/src/physics.cpp.o -c /home/emilcia/simsamples/01hello/src/physics.cpp

CMakeFiles/sdldemoapp.dir/src/physics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdldemoapp.dir/src/physics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilcia/simsamples/01hello/src/physics.cpp > CMakeFiles/sdldemoapp.dir/src/physics.cpp.i

CMakeFiles/sdldemoapp.dir/src/physics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdldemoapp.dir/src/physics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilcia/simsamples/01hello/src/physics.cpp -o CMakeFiles/sdldemoapp.dir/src/physics.cpp.s

CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.requires:

.PHONY : CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.requires

CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.provides: CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdldemoapp.dir/build.make CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.provides.build
.PHONY : CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.provides

CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.provides.build: CMakeFiles/sdldemoapp.dir/src/physics.cpp.o


# Object files for target sdldemoapp
sdldemoapp_OBJECTS = \
"CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o" \
"CMakeFiles/sdldemoapp.dir/src/main.cpp.o" \
"CMakeFiles/sdldemoapp.dir/src/physics.cpp.o"

# External object files for target sdldemoapp
sdldemoapp_EXTERNAL_OBJECTS =

sdldemoapp: CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o
sdldemoapp: CMakeFiles/sdldemoapp.dir/src/main.cpp.o
sdldemoapp: CMakeFiles/sdldemoapp.dir/src/physics.cpp.o
sdldemoapp: CMakeFiles/sdldemoapp.dir/build.make
sdldemoapp: /usr/lib/x86_64-linux-gnu/libSDL2main.a
sdldemoapp: /usr/lib/x86_64-linux-gnu/libSDL2.so
sdldemoapp: CMakeFiles/sdldemoapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilcia/simsamples/01hello/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sdldemoapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sdldemoapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sdldemoapp.dir/build: sdldemoapp

.PHONY : CMakeFiles/sdldemoapp.dir/build

CMakeFiles/sdldemoapp.dir/requires: CMakeFiles/sdldemoapp.dir/src/graphics.cpp.o.requires
CMakeFiles/sdldemoapp.dir/requires: CMakeFiles/sdldemoapp.dir/src/main.cpp.o.requires
CMakeFiles/sdldemoapp.dir/requires: CMakeFiles/sdldemoapp.dir/src/physics.cpp.o.requires

.PHONY : CMakeFiles/sdldemoapp.dir/requires

CMakeFiles/sdldemoapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sdldemoapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sdldemoapp.dir/clean

CMakeFiles/sdldemoapp.dir/depend:
	cd /home/emilcia/simsamples/01hello && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilcia/simsamples/01hello /home/emilcia/simsamples/01hello /home/emilcia/simsamples/01hello /home/emilcia/simsamples/01hello /home/emilcia/simsamples/01hello/CMakeFiles/sdldemoapp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sdldemoapp.dir/depend

