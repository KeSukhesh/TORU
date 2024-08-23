#include <iostream>
#include <thread>
#include <chrono>
#include "core/tradingengine/TradingEngineServer.h"

void TradingEngineServer::executeAsync() {
    while (!stopRequested.load()) {
        // server loop code
        logger_->log("Trading Engine Server Running...");
        // Simulate work with sleep
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void TradingEngineServer::onStopped() {
    logger_->log("Trading Engine Server Stopped.");
}