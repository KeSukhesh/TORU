#pragma once

#include <condition_variable>
#include <thread>
#include <mutex>
#include <atomic>
#include <map>
#include <unordered_map>

#include <OrderbookAliases.h>
#include <Order.h>
#include <ModifiedOrder.h>
#include <OrderbookLevelInfo.h>
#include <Trade.h>

class Orderbook {
public:
    Orderbook()
        : shutdown_(false)
    {}

    ~Orderbook();
    Orderbook(const Orderbook&) = delete;
    void operator=(const Orderbook&) = delete;
    Orderbook(Orderbook&&) = delete;
    void operator=(Orderbook&&) = delete;

    Trades add_order(OrderPointer order);
    void cancel_order(OrderId order_id);
    Trades modify_order(ModifiedOrder order);

    std::size_t size() const;
    OrderbookLevelInfo get_order_info() const;

private:
    void prune_good_for_day_orders();
    void cancel_orders(Orders order_id_list);
    void cancel_order_internal(OrderId order_id);
    void on_order_cancelled(OrderPointer order);
    void on_order_added(OrderPointer order);
    void on_order_matched(Price price, Quantity quantity, bool isFullyFilled);
    void update_level_data(Price price, Quantity quantity, LevelData::Operation operation);
    bool can_fully_fill(SideType side, Price price, Quantity quantity) const;
    bool can_match(SideType side, Price price) const;
    Trades match_orders();

    std::unordered_map<Price, LevelData> data_;
    std::map<Price, OrderPointers, std::greater<Price>> bids_;
    std::map<Price, OrderPointers, std::less<Price>> asks_;
    std::unordered_map<OrderId, OrderEntry> orders_;
    mutable std::mutex orders_mutex_;
    std::thread orders_prune_thread_;
    std::condition_variable shutdown_condition_variable_;
    std::atomic<bool> shutdown_;

};