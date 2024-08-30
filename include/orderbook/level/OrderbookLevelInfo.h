#pragma once

#include "LevelData.h"

using LevelInfo = std::vector<LevelData>;

class OrderbookLevelInfo {
public:
    OrderbookLevelInfo(const LevelInfo& bids, const LevelInfo& asks)
        : bids_(bids)
        , asks_(asks)
    {}

    const LevelInfo& get_bids() const { return bids_; }
    const LevelInfo& get_asks() const { return asks_; }

private:
    LevelInfo bids_;
    LevelInfo asks_;
};