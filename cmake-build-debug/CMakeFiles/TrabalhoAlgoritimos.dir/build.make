# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\guilh\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\guilh\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TrabalhoAlgoritimos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrabalhoAlgoritimos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrabalhoAlgoritimos.dir/flags.make

CMakeFiles/TrabalhoAlgoritimos.dir/main.c.obj: CMakeFiles/TrabalhoAlgoritimos.dir/flags.make
CMakeFiles/TrabalhoAlgoritimos.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TrabalhoAlgoritimos.dir/main.c.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TrabalhoAlgoritimos.dir\main.c.obj   -c "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\main.c"

CMakeFiles/TrabalhoAlgoritimos.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TrabalhoAlgoritimos.dir/main.c.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\main.c" > CMakeFiles\TrabalhoAlgoritimos.dir\main.c.i

CMakeFiles/TrabalhoAlgoritimos.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TrabalhoAlgoritimos.dir/main.c.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\main.c" -o CMakeFiles\TrabalhoAlgoritimos.dir\main.c.s

# Object files for target TrabalhoAlgoritimos
TrabalhoAlgoritimos_OBJECTS = \
"CMakeFiles/TrabalhoAlgoritimos.dir/main.c.obj"

# External object files for target TrabalhoAlgoritimos
TrabalhoAlgoritimos_EXTERNAL_OBJECTS =

TrabalhoAlgoritimos.exe: CMakeFiles/TrabalhoAlgoritimos.dir/main.c.obj
TrabalhoAlgoritimos.exe: CMakeFiles/TrabalhoAlgoritimos.dir/build.make
TrabalhoAlgoritimos.exe: CMakeFiles/TrabalhoAlgoritimos.dir/linklibs.rsp
TrabalhoAlgoritimos.exe: CMakeFiles/TrabalhoAlgoritimos.dir/objects1.rsp
TrabalhoAlgoritimos.exe: CMakeFiles/TrabalhoAlgoritimos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TrabalhoAlgoritimos.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TrabalhoAlgoritimos.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrabalhoAlgoritimos.dir/build: TrabalhoAlgoritimos.exe

.PHONY : CMakeFiles/TrabalhoAlgoritimos.dir/build

CMakeFiles/TrabalhoAlgoritimos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TrabalhoAlgoritimos.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TrabalhoAlgoritimos.dir/clean

CMakeFiles/TrabalhoAlgoritimos.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos" "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos" "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug" "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug" "D:\AMF\3 - Terceiro Semestre\Algoritimos II\TrabalhoAlgoritimos\cmake-build-debug\CMakeFiles\TrabalhoAlgoritimos.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TrabalhoAlgoritimos.dir/depend

