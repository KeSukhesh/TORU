#pragma once

#include <BackgroundService.h>

class TradingEngineServer : public BackgroundService {
public:
    TradingEngineServer(const std::string& config_file_path, const std::string& log_file_path)
        : BackgroundService(log_file_path, config_file_path) {}

    void run_trading_engine();

protected:
    virtual void handle_server_connection(tcp::socket socket) override;
};