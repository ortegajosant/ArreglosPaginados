# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PagedArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PagedArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PagedArray.dir/flags.make

CMakeFiles/PagedArray.dir/main.cpp.o: CMakeFiles/PagedArray.dir/flags.make
CMakeFiles/PagedArray.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PagedArray.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PagedArray.dir/main.cpp.o -c "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/main.cpp"

CMakeFiles/PagedArray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PagedArray.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/main.cpp" > CMakeFiles/PagedArray.dir/main.cpp.i

CMakeFiles/PagedArray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PagedArray.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/main.cpp" -o CMakeFiles/PagedArray.dir/main.cpp.s

# Object files for target PagedArray
PagedArray_OBJECTS = \
"CMakeFiles/PagedArray.dir/main.cpp.o"

# External object files for target PagedArray
PagedArray_EXTERNAL_OBJECTS =

PagedArray: CMakeFiles/PagedArray.dir/main.cpp.o
PagedArray: CMakeFiles/PagedArray.dir/build.make
PagedArray: CMakeFiles/PagedArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PagedArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PagedArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PagedArray.dir/build: PagedArray

.PHONY : CMakeFiles/PagedArray.dir/build

CMakeFiles/PagedArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PagedArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PagedArray.dir/clean

CMakeFiles/PagedArray.dir/depend:
	cd "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI" "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI" "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug" "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug" "/home/ortegajosant/Documentos/Algoritmos Extructuras datos Datos II/TareaCortaI/cmake-build-debug/CMakeFiles/PagedArray.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PagedArray.dir/depend

