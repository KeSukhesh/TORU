#pragma once

#include <background_service/IBackgroundService.h>
#include <trading_engine/ServerConfiguration.h>

class ITradingEngineServer : public IBackgroundService {
public:
    // ITradingEngineServer(std::shared_ptr<ServerConfiguration> config) :  IBackgroundService(1), config_(config) {}
    ITradingEngineServer() :  IBackgroundService(4) {}

    // in future will need to parse in num of threads, rn default: 4
    void run_trading_engine();

protected:
    virtual void handle_server_connection(tcp::socket socket) override;

private:
    // logger
    // config: includes port number, num of thread pools etc.
    std::shared_ptr<ServerConfiguration> config_;
};