#pragma once

#include "orderbook/OrderbookAliases.h"

struct LevelData {
    Price price_;
    Quantity quantity_;

    enum class Operation {
        ADD,
        REMOVE,
        MATCH
    };
};