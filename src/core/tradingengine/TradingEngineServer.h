#pragma once
#include <atomic>
#include <thread>
#include <iostream>
#include <memory>

#include "ILogger.h"
#include "TradingEngineServerConfiguration.h"
#include "ITradingEngineServer.h"
#include "BackgroundService.h"

class TradingEngineServer : public ITradingEngineServer, public BackgroundService {
public:
    TradingEngineServer(std::shared_ptr<ILogger> logger, std::shared_ptr<TradingEngineServerConfiguration> config)
        : logger_(logger), config_(config) {}

    void runTradingEngine() override {
        logger_->log("Starting Trading Engine Server...");
        start();
    }

protected:
    void executeAsync() override;
    void onStopped() override;

private:
    std::shared_ptr<ILogger> logger_;
    std::shared_ptr<TradingEngineServerConfiguration> config_;
};