cmake_minimum_required(VERSION 3.10)
project(TORU)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include/core/trading_engine_threadpool)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(TradingEngineServer
    src/core/tradingengine/TradingEngineServer.cpp
    include/core/trading_engine_threadpool/ThreadPool.cpp
)

target_link_libraries(TradingEngineServer
    Boost::system
    Threads::Threads
)