#pragma once

#include <TradeInfo.h>

class Trade {
public:
    Trade(const TradeInfo& bid, const TradeInfo& ask)
        : bid_trade_(bid)
        , ask_trade_(ask)
    {}

    const TradeInfo& get_bid_trade() const { return bid_trade_; }
    const TradeInfo& get_ask_trade() const { return ask_trade_; }

private:
    TradeInfo bid_trade_;
    TradeInfo ask_trade_;

};

using Trades = std::vector<Trade>;