#pragma once

#include <background_service/BackgroundService.h>
#include <trading_engine/ServerConfiguration.h>

class TradingEngineServer : public BackgroundService {
public:
    TradingEngineServer(const std::string& configFilePath)
        :  config_(std::make_shared<ServerConfiguration>(configFilePath)) {}

    void run_trading_engine();

    std::shared_ptr<ServerConfiguration> get_server_config() { return config_; }
    void set_server_config(std::shared_ptr<ServerConfiguration> config) { config_ = config; }

protected:
    virtual void handle_server_connection(tcp::socket socket) override;

private:
    // need logger
    std::shared_ptr<ServerConfiguration> config_;
};