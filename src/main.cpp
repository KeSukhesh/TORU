#include <TradingEngineServer.h>

int main() {
    TradingEngineServer server("server_config.json");
    server.run_trading_engine();

    return 0;
}