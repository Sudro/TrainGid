# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\qt\Tools\CMake_64\bin\cmake.exe

# The command to remove a file.
RM = D:\qt\Tools\CMake_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\qt\projects\TrainGid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\qt\projects\TrainGid\build\Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug

# Utility rule file for MyExecutable_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MyExecutable_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyExecutable_autogen.dir/progress.make

CMakeFiles/MyExecutable_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=D:\qt\projects\TrainGid\build\Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MyExecutable"
	D:\qt\Tools\CMake_64\bin\cmake.exe -E cmake_autogen D:/qt/projects/TrainGid/build/Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug/CMakeFiles/MyExecutable_autogen.dir/AutogenInfo.json Debug

MyExecutable_autogen: CMakeFiles/MyExecutable_autogen
MyExecutable_autogen: CMakeFiles/MyExecutable_autogen.dir/build.make
.PHONY : MyExecutable_autogen

# Rule to build all files generated by this target.
CMakeFiles/MyExecutable_autogen.dir/build: MyExecutable_autogen
.PHONY : CMakeFiles/MyExecutable_autogen.dir/build

CMakeFiles/MyExecutable_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyExecutable_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyExecutable_autogen.dir/clean

CMakeFiles/MyExecutable_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\qt\projects\TrainGid D:\qt\projects\TrainGid D:\qt\projects\TrainGid\build\Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug D:\qt\projects\TrainGid\build\Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug D:\qt\projects\TrainGid\build\Desktop_Qt_6_7_0_llvm_mingw_64_bit-Debug\CMakeFiles\MyExecutable_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyExecutable_autogen.dir/depend
