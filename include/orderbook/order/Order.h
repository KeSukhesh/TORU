#pragma once

#include <exception>
#include <list>
#include <memory>

#include <OrderbookAliases.h>
#include <OrderType.h>
#include <SideType.h>

class Order {
public:
    Order(OrderType order_type, OrderId order_id, SideType side, Price price, Quantity quantity)
        : order_type_(order_type)
        , order_id_(order_id)
        , side_(side)
        , price_(price)
        , initial_quantity_(quantity)
        , remaining_quantity_(quantity)
    {}

    Order(OrderId order_id, SideType side, Quantity quantity)
        : Order(OrderType::MARKET, order_id, side, OrderbookAliases::INVALID_PRICE, quantity)
    {}

    OrderId get_order_id() const { return order_id_; }
    SideType get_side() const { return side_; }
    Price get_price() const { return price_; }
    OrderType get_order_type() const { return order_type_; }
    Quantity get_initial_quantity() const { return initial_quantity_; }
    Quantity get_remaining_quantity() const { return remaining_quantity_; }
    Quantity get_filled_quantity() const { return get_initial_quantity() - get_remaining_quantity(); }
    bool is_filled() const { return get_remaining_quantity() == 0; }

    void fill(Quantity quantity) {
        if (quantity > get_remaining_quantity())
            // throw std::logic_error("Order (" + get_order_id() + ") cannot be filled for more than its remaining quantity.");

        remaining_quantity_ -= quantity;
    }

    void to_good_till_cancel(Price price) {
        if (get_order_type() != OrderType::MARKET)
            // throw std::logic_error("Order (" + get_order_id() + ") cannot have its price adjusted, only market orders can.");

        price_ = price;
        order_type_ = OrderType::GOOD_TILL_CANCEL;
    }

private:
    OrderType order_type_;
    OrderId order_id_;
    SideType side_;
    Price price_;
    Quantity initial_quantity_;
    Quantity remaining_quantity_;

};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;

struct OrderEntry {
    OrderPointer order_;
    OrderPointers::iterator location_;
};