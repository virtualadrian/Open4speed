# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613

# Include any dependencies generated for this target.
include Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/flags.make

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/flags.make
Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o: Demos/RagdollDemo/RagdollDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o -c /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/RagdollDemo.cpp

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppRagdollDemo.dir/RagdollDemo.i"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/RagdollDemo.cpp > CMakeFiles/AppRagdollDemo.dir/RagdollDemo.i

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppRagdollDemo.dir/RagdollDemo.s"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/RagdollDemo.cpp -o CMakeFiles/AppRagdollDemo.dir/RagdollDemo.s

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.requires:
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.requires

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.provides: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.requires
	$(MAKE) -f Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/build.make Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.provides.build
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.provides

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.provides.build: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/flags.make
Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o: Demos/RagdollDemo/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AppRagdollDemo.dir/main.o -c /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/main.cpp

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppRagdollDemo.dir/main.i"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/main.cpp > CMakeFiles/AppRagdollDemo.dir/main.i

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppRagdollDemo.dir/main.s"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/main.cpp -o CMakeFiles/AppRagdollDemo.dir/main.s

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.requires:
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.requires

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.provides: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.requires
	$(MAKE) -f Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/build.make Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.provides.build
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.provides

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.provides.build: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o

# Object files for target AppRagdollDemo
AppRagdollDemo_OBJECTS = \
"CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o" \
"CMakeFiles/AppRagdollDemo.dir/main.o"

# External object files for target AppRagdollDemo
AppRagdollDemo_EXTERNAL_OBJECTS =

Demos/RagdollDemo/AppRagdollDemo: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o
Demos/RagdollDemo/AppRagdollDemo: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o
Demos/RagdollDemo/AppRagdollDemo: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/build.make
Demos/RagdollDemo/AppRagdollDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/RagdollDemo/AppRagdollDemo: src/BulletDynamics/libBulletDynamics.a
Demos/RagdollDemo/AppRagdollDemo: src/BulletCollision/libBulletCollision.a
Demos/RagdollDemo/AppRagdollDemo: src/LinearMath/libLinearMath.a
Demos/RagdollDemo/AppRagdollDemo: /usr/lib/i386-linux-gnu/libglut.so
Demos/RagdollDemo/AppRagdollDemo: /usr/lib/i386-linux-gnu/libGL.so
Demos/RagdollDemo/AppRagdollDemo: /usr/lib/i386-linux-gnu/libGLU.so
Demos/RagdollDemo/AppRagdollDemo: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AppRagdollDemo"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppRagdollDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/build: Demos/RagdollDemo/AppRagdollDemo
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/build

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/requires: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/RagdollDemo.o.requires
Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/requires: Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/main.o.requires
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/requires

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/clean:
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppRagdollDemo.dir/cmake_clean.cmake
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/clean

Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/depend:
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/RagdollDemo/CMakeFiles/AppRagdollDemo.dir/depend

