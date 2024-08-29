#include <iostream>
#include <memory>

#include <TradingEngineServer.h>

int main() {
    std::string config_file_path = "../src/util/server_config.json";
    TradingEngineServer server(config_file_path);
    server.run_trading_engine();
    return 0;
}