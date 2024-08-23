cmake_minimum_required(VERSION 3.10)
project(TORU)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/src/core/tradingengine)
# find_program(CLANG_FORMAT_EXECUTABLE ${PROJECT_SOURCE_DIR}/clang-format)

add_executable(TradingEngineServer src/main.cpp src/core/tradingengine/TradingEngineServer.cpp)