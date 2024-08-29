cmake_minimum_required(VERSION 3.10)
project(TORU)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif()

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/trading_engine)
include_directories(${PROJECT_SOURCE_DIR}/include/background_service)
include_directories(${PROJECT_SOURCE_DIR}/include/logger)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(TradingEngineServer
    src/main.cpp
    src/trading_engine/TradingEngineServer.cpp
    src/background_service/BackgroundService.cpp
    src/background_service/ThreadPool.cpp
)

target_link_libraries(TradingEngineServer
    Boost::system
    Threads::Threads
)