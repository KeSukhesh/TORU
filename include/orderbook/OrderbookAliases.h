#pragma once

#include <vector>
#include <cstdint>
#include <limits>

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;
using Orders = std::vector<OrderId>;

struct OrderbookAliases {
    static const Price INVALID_PRICE = std::numeric_limits<Price>::quiet_NaN();
};