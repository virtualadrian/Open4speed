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
include Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/flags.make

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/flags.make
Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o: Demos/BulletXmlImportDemo/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AppBulletXmlImportDemo.dir/main.o -c /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/main.cpp

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBulletXmlImportDemo.dir/main.i"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/main.cpp > CMakeFiles/AppBulletXmlImportDemo.dir/main.i

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBulletXmlImportDemo.dir/main.s"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/main.cpp -o CMakeFiles/AppBulletXmlImportDemo.dir/main.s

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.requires:
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.requires

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.provides: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.requires
	$(MAKE) -f Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/build.make Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.provides.build
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.provides

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.provides.build: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/flags.make
Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o: Demos/BulletXmlImportDemo/BulletXmlImportDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o -c /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/BulletXmlImportDemo.cpp

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.i"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/BulletXmlImportDemo.cpp > CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.i

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.s"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/BulletXmlImportDemo.cpp -o CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.s

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.requires:
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.requires

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.provides: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.requires
	$(MAKE) -f Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/build.make Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.provides.build
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.provides

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.provides.build: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o

# Object files for target AppBulletXmlImportDemo
AppBulletXmlImportDemo_OBJECTS = \
"CMakeFiles/AppBulletXmlImportDemo.dir/main.o" \
"CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o"

# External object files for target AppBulletXmlImportDemo
AppBulletXmlImportDemo_EXTERNAL_OBJECTS =

Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/build.make
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Demos/OpenGL/libOpenGLSupport.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Extras/Serialize/BulletXmlWorldImporter/libBulletXmlWorldImporter.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Extras/Serialize/BulletWorldImporter/libBulletWorldImporter.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: src/BulletSoftBody/libBulletSoftBody.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: src/BulletDynamics/libBulletDynamics.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: src/BulletCollision/libBulletCollision.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Extras/Serialize/BulletFileLoader/libBulletFileLoader.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: src/LinearMath/libLinearMath.a
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: /usr/lib/i386-linux-gnu/libglut.so
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: /usr/lib/i386-linux-gnu/libGL.so
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: /usr/lib/i386-linux-gnu/libGLU.so
Demos/BulletXmlImportDemo/AppBulletXmlImportDemo: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AppBulletXmlImportDemo"
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppBulletXmlImportDemo.dir/link.txt --verbose=$(VERBOSE)
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/cmake -E copy_if_different /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/bullet_basic.xml /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/bullet_basic.xml
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && /usr/bin/cmake -E copy_if_different /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/bullet_basic.xml /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/Debug/bullet_basic.xml

# Rule to build all files generated by this target.
Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/build: Demos/BulletXmlImportDemo/AppBulletXmlImportDemo
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/build

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/requires: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/main.o.requires
Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/requires: Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/BulletXmlImportDemo.o.requires
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/requires

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/clean:
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo && $(CMAKE_COMMAND) -P CMakeFiles/AppBulletXmlImportDemo.dir/cmake_clean.cmake
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/clean

Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/depend:
	cd /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613 /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo /home/lubos/Plocha/Open4speed/support/bullet-2.81-rev2613/Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/BulletXmlImportDemo/CMakeFiles/AppBulletXmlImportDemo.dir/depend

