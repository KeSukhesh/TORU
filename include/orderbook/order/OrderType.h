#pragma once

enum class OrderType {
    GOOD_TILL_CANCEL,
    FILL_AND_KILL,
    FILL_OR_KILL,
    GOOD_FOR_DAY,
    MARKET
};