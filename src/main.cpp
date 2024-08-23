#include <memory>

#include "TradingEngineServer.h"
#include "ConsoleLogger.h"
#include "TradingEngineServerConfiguration.h"

int main() {
    auto logger = std::make_shared<ConsoleLogger>();
    auto config = std::make_shared<TradingEngineServerConfiguration>();
    TradingEngineServer server(logger, config);
    server.runTradingEngine();

    // simulate for some time
    std::this_thread::sleep_for(std::chrono::seconds(5));

    server.stop();
    return 0;
}