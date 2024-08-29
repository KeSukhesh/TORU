#pragma once

#include <background_service/BackgroundService.h>
#include <trading_engine/ServerConfiguration.h>

class TradingEngineServer : public BackgroundService {
public:
    TradingEngineServer(const std::string& configFilePath)
        :  config_(ServerConfiguration(configFilePath)) {}

    void run_trading_engine();

    ServerConfiguration get_server_config() { return config_; }
    void set_server_config(ServerConfiguration config) { config_ = config; }

protected:
    virtual void handle_server_connection(tcp::socket socket) override;

private:
    // need logger
    ServerConfiguration config_;
};