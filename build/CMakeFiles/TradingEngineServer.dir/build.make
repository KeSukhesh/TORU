# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /snap/cmake/1409/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1409/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kesukhesh/projects/TORU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kesukhesh/projects/TORU/build

# Include any dependencies generated for this target.
include CMakeFiles/TradingEngineServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TradingEngineServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TradingEngineServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TradingEngineServer.dir/flags.make

CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o: CMakeFiles/TradingEngineServer.dir/flags.make
CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o: /home/kesukhesh/projects/TORU/src/core/tradingengine/TradingEngineServer.cpp
CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o: CMakeFiles/TradingEngineServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kesukhesh/projects/TORU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o -MF CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o.d -o CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o -c /home/kesukhesh/projects/TORU/src/core/tradingengine/TradingEngineServer.cpp

CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kesukhesh/projects/TORU/src/core/tradingengine/TradingEngineServer.cpp > CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.i

CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kesukhesh/projects/TORU/src/core/tradingengine/TradingEngineServer.cpp -o CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.s

CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o: CMakeFiles/TradingEngineServer.dir/flags.make
CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o: /home/kesukhesh/projects/TORU/include/core/trading_engine_threadpool/ThreadPool.cpp
CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o: CMakeFiles/TradingEngineServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kesukhesh/projects/TORU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o -MF CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o.d -o CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o -c /home/kesukhesh/projects/TORU/include/core/trading_engine_threadpool/ThreadPool.cpp

CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kesukhesh/projects/TORU/include/core/trading_engine_threadpool/ThreadPool.cpp > CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.i

CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kesukhesh/projects/TORU/include/core/trading_engine_threadpool/ThreadPool.cpp -o CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.s

# Object files for target TradingEngineServer
TradingEngineServer_OBJECTS = \
"CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o" \
"CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o"

# External object files for target TradingEngineServer
TradingEngineServer_EXTERNAL_OBJECTS =

TradingEngineServer: CMakeFiles/TradingEngineServer.dir/src/core/tradingengine/TradingEngineServer.cpp.o
TradingEngineServer: CMakeFiles/TradingEngineServer.dir/include/core/trading_engine_threadpool/ThreadPool.cpp.o
TradingEngineServer: CMakeFiles/TradingEngineServer.dir/build.make
TradingEngineServer: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
TradingEngineServer: CMakeFiles/TradingEngineServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kesukhesh/projects/TORU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TradingEngineServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TradingEngineServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TradingEngineServer.dir/build: TradingEngineServer
.PHONY : CMakeFiles/TradingEngineServer.dir/build

CMakeFiles/TradingEngineServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TradingEngineServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TradingEngineServer.dir/clean

CMakeFiles/TradingEngineServer.dir/depend:
	cd /home/kesukhesh/projects/TORU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kesukhesh/projects/TORU /home/kesukhesh/projects/TORU /home/kesukhesh/projects/TORU/build /home/kesukhesh/projects/TORU/build /home/kesukhesh/projects/TORU/build/CMakeFiles/TradingEngineServer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TradingEngineServer.dir/depend

