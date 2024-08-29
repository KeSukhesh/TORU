#pragma once

#include <background_service/BackgroundService.h>
#include <trading_engine/ServerConfiguration.h>

class TradingEngineServer : public BackgroundService {
public:
    TradingEngineServer(const std::string& configFilePath)
        : BackgroundService(ServerConfiguration(configFilePath).getNumberOfThreads()),
          config_(std::make_shared<ServerConfiguration>(configFilePath)) {}

    void run_trading_engine();

    std::shared_ptr<ServerConfiguration> get_server_config() { return config_; }
    void set_server_config(std::shared_ptr<ServerConfiguration> config) { config_ = config; }

protected:
    virtual void handle_server_connection(tcp::socket socket) override;

private:
    // logger
    std::shared_ptr<ServerConfiguration> config_;
};