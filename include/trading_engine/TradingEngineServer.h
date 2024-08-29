#pragma once

#include <BackgroundService.h>
#include <ServerConfiguration.h>
#include <FileLogger.h>

class TradingEngineServer : public BackgroundService {
public:
    TradingEngineServer(const std::string& configFilePath, const std::string& logFilePath)
        :  config_(ServerConfiguration(configFilePath)), BackgroundService(logFilePath) {}

    void run_trading_engine();

    ServerConfiguration get_server_config() { return config_; }
    void set_server_config(ServerConfiguration config) { config_ = config; }

protected:
    virtual void handle_server_connection(tcp::socket socket) override;

private:
    ServerConfiguration config_;
};