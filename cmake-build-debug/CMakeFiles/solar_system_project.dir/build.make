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
CMAKE_COMMAND = /opt/clion-2022.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2022.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Graphics/SolarSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Graphics/SolarSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/solar_system_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/solar_system_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/solar_system_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/solar_system_project.dir/flags.make

CMakeFiles/solar_system_project.dir/src/main.cpp.o: CMakeFiles/solar_system_project.dir/flags.make
CMakeFiles/solar_system_project.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/solar_system_project.dir/src/main.cpp.o: CMakeFiles/solar_system_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Graphics/SolarSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/solar_system_project.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solar_system_project.dir/src/main.cpp.o -MF CMakeFiles/solar_system_project.dir/src/main.cpp.o.d -o CMakeFiles/solar_system_project.dir/src/main.cpp.o -c /Graphics/SolarSystem/src/main.cpp

CMakeFiles/solar_system_project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solar_system_project.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Graphics/SolarSystem/src/main.cpp > CMakeFiles/solar_system_project.dir/src/main.cpp.i

CMakeFiles/solar_system_project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solar_system_project.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Graphics/SolarSystem/src/main.cpp -o CMakeFiles/solar_system_project.dir/src/main.cpp.s

CMakeFiles/solar_system_project.dir/src/camera.cpp.o: CMakeFiles/solar_system_project.dir/flags.make
CMakeFiles/solar_system_project.dir/src/camera.cpp.o: ../src/camera.cpp
CMakeFiles/solar_system_project.dir/src/camera.cpp.o: CMakeFiles/solar_system_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Graphics/SolarSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/solar_system_project.dir/src/camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solar_system_project.dir/src/camera.cpp.o -MF CMakeFiles/solar_system_project.dir/src/camera.cpp.o.d -o CMakeFiles/solar_system_project.dir/src/camera.cpp.o -c /Graphics/SolarSystem/src/camera.cpp

CMakeFiles/solar_system_project.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solar_system_project.dir/src/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Graphics/SolarSystem/src/camera.cpp > CMakeFiles/solar_system_project.dir/src/camera.cpp.i

CMakeFiles/solar_system_project.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solar_system_project.dir/src/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Graphics/SolarSystem/src/camera.cpp -o CMakeFiles/solar_system_project.dir/src/camera.cpp.s

CMakeFiles/solar_system_project.dir/src/planet.cpp.o: CMakeFiles/solar_system_project.dir/flags.make
CMakeFiles/solar_system_project.dir/src/planet.cpp.o: ../src/planet.cpp
CMakeFiles/solar_system_project.dir/src/planet.cpp.o: CMakeFiles/solar_system_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Graphics/SolarSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/solar_system_project.dir/src/planet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solar_system_project.dir/src/planet.cpp.o -MF CMakeFiles/solar_system_project.dir/src/planet.cpp.o.d -o CMakeFiles/solar_system_project.dir/src/planet.cpp.o -c /Graphics/SolarSystem/src/planet.cpp

CMakeFiles/solar_system_project.dir/src/planet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solar_system_project.dir/src/planet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Graphics/SolarSystem/src/planet.cpp > CMakeFiles/solar_system_project.dir/src/planet.cpp.i

CMakeFiles/solar_system_project.dir/src/planet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solar_system_project.dir/src/planet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Graphics/SolarSystem/src/planet.cpp -o CMakeFiles/solar_system_project.dir/src/planet.cpp.s

CMakeFiles/solar_system_project.dir/src/ui.cpp.o: CMakeFiles/solar_system_project.dir/flags.make
CMakeFiles/solar_system_project.dir/src/ui.cpp.o: ../src/ui.cpp
CMakeFiles/solar_system_project.dir/src/ui.cpp.o: CMakeFiles/solar_system_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Graphics/SolarSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/solar_system_project.dir/src/ui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/solar_system_project.dir/src/ui.cpp.o -MF CMakeFiles/solar_system_project.dir/src/ui.cpp.o.d -o CMakeFiles/solar_system_project.dir/src/ui.cpp.o -c /Graphics/SolarSystem/src/ui.cpp

CMakeFiles/solar_system_project.dir/src/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/solar_system_project.dir/src/ui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Graphics/SolarSystem/src/ui.cpp > CMakeFiles/solar_system_project.dir/src/ui.cpp.i

CMakeFiles/solar_system_project.dir/src/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/solar_system_project.dir/src/ui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Graphics/SolarSystem/src/ui.cpp -o CMakeFiles/solar_system_project.dir/src/ui.cpp.s

# Object files for target solar_system_project
solar_system_project_OBJECTS = \
"CMakeFiles/solar_system_project.dir/src/main.cpp.o" \
"CMakeFiles/solar_system_project.dir/src/camera.cpp.o" \
"CMakeFiles/solar_system_project.dir/src/planet.cpp.o" \
"CMakeFiles/solar_system_project.dir/src/ui.cpp.o"

# External object files for target solar_system_project
solar_system_project_EXTERNAL_OBJECTS =

solar_system_project: CMakeFiles/solar_system_project.dir/src/main.cpp.o
solar_system_project: CMakeFiles/solar_system_project.dir/src/camera.cpp.o
solar_system_project: CMakeFiles/solar_system_project.dir/src/planet.cpp.o
solar_system_project: CMakeFiles/solar_system_project.dir/src/ui.cpp.o
solar_system_project: CMakeFiles/solar_system_project.dir/build.make
solar_system_project: /usr/lib/x86_64-linux-gnu/libGL.so
solar_system_project: /usr/lib/x86_64-linux-gnu/libGLU.so
solar_system_project: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
solar_system_project: CMakeFiles/solar_system_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Graphics/SolarSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable solar_system_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/solar_system_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/solar_system_project.dir/build: solar_system_project
.PHONY : CMakeFiles/solar_system_project.dir/build

CMakeFiles/solar_system_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/solar_system_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/solar_system_project.dir/clean

CMakeFiles/solar_system_project.dir/depend:
	cd /Graphics/SolarSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Graphics/SolarSystem /Graphics/SolarSystem /Graphics/SolarSystem/cmake-build-debug /Graphics/SolarSystem/cmake-build-debug /Graphics/SolarSystem/cmake-build-debug/CMakeFiles/solar_system_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/solar_system_project.dir/depend

