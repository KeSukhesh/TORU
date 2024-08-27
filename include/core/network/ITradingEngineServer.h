#pragma once

class ITradingEngineServer {
public:
    virtual ~ITradingEngineServer() {}

    virtual void runTradingEngine() = 0;
};