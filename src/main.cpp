#include <iostream>
#include <memory>

#include <ITradingEngineServer.h>
#include <ServerConfiguration.h>

int main() {
    // std::shared_ptr<ServerConfiguration> config = std::make_shared<ServerConfiguration>();
    // ITradingEngineServer server(config);
    ITradingEngineServer server = ITradingEngineServer();
    server.run_trading_engine();
    return 0;
}