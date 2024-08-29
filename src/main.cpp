#include <TradingEngineServer.h>

const std::string SERVER_CONFIG_FILE = "server_config.json";
const std::string SERVER_LOG_FILE = "server.log";

int main() {
    TradingEngineServer server(SERVER_CONFIG_FILE, SERVER_LOG_FILE);
    server.run_trading_engine();
    return 0;
}