# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/angelinabannikova/Desktop/some_push

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/angelinabannikova/Desktop/some_push/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/push_swap.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/push_swap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/push_swap.dir/flags.make

CMakeFiles/push_swap.dir/commands.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/commands.c.o: ../commands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/push_swap.dir/commands.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/commands.c.o -c /Users/angelinabannikova/Desktop/some_push/commands.c

CMakeFiles/push_swap.dir/commands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/commands.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/commands.c > CMakeFiles/push_swap.dir/commands.c.i

CMakeFiles/push_swap.dir/commands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/commands.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/commands.c -o CMakeFiles/push_swap.dir/commands.c.s

CMakeFiles/push_swap.dir/ft_atoi.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/ft_atoi.c.o: ../ft_atoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/push_swap.dir/ft_atoi.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/ft_atoi.c.o -c /Users/angelinabannikova/Desktop/some_push/ft_atoi.c

CMakeFiles/push_swap.dir/ft_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/ft_atoi.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/ft_atoi.c > CMakeFiles/push_swap.dir/ft_atoi.c.i

CMakeFiles/push_swap.dir/ft_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/ft_atoi.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/ft_atoi.c -o CMakeFiles/push_swap.dir/ft_atoi.c.s

CMakeFiles/push_swap.dir/ft_isdigit.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/ft_isdigit.c.o: ../ft_isdigit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/push_swap.dir/ft_isdigit.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/ft_isdigit.c.o -c /Users/angelinabannikova/Desktop/some_push/ft_isdigit.c

CMakeFiles/push_swap.dir/ft_isdigit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/ft_isdigit.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/ft_isdigit.c > CMakeFiles/push_swap.dir/ft_isdigit.c.i

CMakeFiles/push_swap.dir/ft_isdigit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/ft_isdigit.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/ft_isdigit.c -o CMakeFiles/push_swap.dir/ft_isdigit.c.s

CMakeFiles/push_swap.dir/ft_split.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/ft_split.c.o: ../ft_split.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/push_swap.dir/ft_split.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/ft_split.c.o -c /Users/angelinabannikova/Desktop/some_push/ft_split.c

CMakeFiles/push_swap.dir/ft_split.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/ft_split.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/ft_split.c > CMakeFiles/push_swap.dir/ft_split.c.i

CMakeFiles/push_swap.dir/ft_split.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/ft_split.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/ft_split.c -o CMakeFiles/push_swap.dir/ft_split.c.s

CMakeFiles/push_swap.dir/ft_strlen.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/ft_strlen.c.o: ../ft_strlen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/push_swap.dir/ft_strlen.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/ft_strlen.c.o -c /Users/angelinabannikova/Desktop/some_push/ft_strlen.c

CMakeFiles/push_swap.dir/ft_strlen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/ft_strlen.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/ft_strlen.c > CMakeFiles/push_swap.dir/ft_strlen.c.i

CMakeFiles/push_swap.dir/ft_strlen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/ft_strlen.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/ft_strlen.c -o CMakeFiles/push_swap.dir/ft_strlen.c.s

CMakeFiles/push_swap.dir/ft_strncmp.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/ft_strncmp.c.o: ../ft_strncmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/push_swap.dir/ft_strncmp.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/ft_strncmp.c.o -c /Users/angelinabannikova/Desktop/some_push/ft_strncmp.c

CMakeFiles/push_swap.dir/ft_strncmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/ft_strncmp.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/ft_strncmp.c > CMakeFiles/push_swap.dir/ft_strncmp.c.i

CMakeFiles/push_swap.dir/ft_strncmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/ft_strncmp.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/ft_strncmp.c -o CMakeFiles/push_swap.dir/ft_strncmp.c.s

CMakeFiles/push_swap.dir/mini_sort.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/mini_sort.c.o: ../mini_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/push_swap.dir/mini_sort.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/mini_sort.c.o -c /Users/angelinabannikova/Desktop/some_push/mini_sort.c

CMakeFiles/push_swap.dir/mini_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/mini_sort.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/mini_sort.c > CMakeFiles/push_swap.dir/mini_sort.c.i

CMakeFiles/push_swap.dir/mini_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/mini_sort.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/mini_sort.c -o CMakeFiles/push_swap.dir/mini_sort.c.s

CMakeFiles/push_swap.dir/new_push_swap.c.o: CMakeFiles/push_swap.dir/flags.make
CMakeFiles/push_swap.dir/new_push_swap.c.o: ../new_push_swap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/push_swap.dir/new_push_swap.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/push_swap.dir/new_push_swap.c.o -c /Users/angelinabannikova/Desktop/some_push/new_push_swap.c

CMakeFiles/push_swap.dir/new_push_swap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/push_swap.dir/new_push_swap.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/angelinabannikova/Desktop/some_push/new_push_swap.c > CMakeFiles/push_swap.dir/new_push_swap.c.i

CMakeFiles/push_swap.dir/new_push_swap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/push_swap.dir/new_push_swap.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/angelinabannikova/Desktop/some_push/new_push_swap.c -o CMakeFiles/push_swap.dir/new_push_swap.c.s

# Object files for target push_swap
push_swap_OBJECTS = \
"CMakeFiles/push_swap.dir/commands.c.o" \
"CMakeFiles/push_swap.dir/ft_atoi.c.o" \
"CMakeFiles/push_swap.dir/ft_isdigit.c.o" \
"CMakeFiles/push_swap.dir/ft_split.c.o" \
"CMakeFiles/push_swap.dir/ft_strlen.c.o" \
"CMakeFiles/push_swap.dir/ft_strncmp.c.o" \
"CMakeFiles/push_swap.dir/mini_sort.c.o" \
"CMakeFiles/push_swap.dir/new_push_swap.c.o"

# External object files for target push_swap
push_swap_EXTERNAL_OBJECTS =

push_swap: CMakeFiles/push_swap.dir/commands.c.o
push_swap: CMakeFiles/push_swap.dir/ft_atoi.c.o
push_swap: CMakeFiles/push_swap.dir/ft_isdigit.c.o
push_swap: CMakeFiles/push_swap.dir/ft_split.c.o
push_swap: CMakeFiles/push_swap.dir/ft_strlen.c.o
push_swap: CMakeFiles/push_swap.dir/ft_strncmp.c.o
push_swap: CMakeFiles/push_swap.dir/mini_sort.c.o
push_swap: CMakeFiles/push_swap.dir/new_push_swap.c.o
push_swap: CMakeFiles/push_swap.dir/build.make
push_swap: CMakeFiles/push_swap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable push_swap"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/push_swap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/push_swap.dir/build: push_swap
.PHONY : CMakeFiles/push_swap.dir/build

CMakeFiles/push_swap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/push_swap.dir/cmake_clean.cmake
.PHONY : CMakeFiles/push_swap.dir/clean

CMakeFiles/push_swap.dir/depend:
	cd /Users/angelinabannikova/Desktop/some_push/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/angelinabannikova/Desktop/some_push /Users/angelinabannikova/Desktop/some_push /Users/angelinabannikova/Desktop/some_push/cmake-build-debug /Users/angelinabannikova/Desktop/some_push/cmake-build-debug /Users/angelinabannikova/Desktop/some_push/cmake-build-debug/CMakeFiles/push_swap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/push_swap.dir/depend

