#pragma once

#include <Order.h>

class ModifiedOrder {
    ModifiedOrder(OrderId order_id, SideType side, Price price, Quantity quantity)
        : order_id_(order_id)
        , price_(price)
        , side_(side)
        , quantity_(quantity)
    {}

    OrderId get_order_id() const { return order_id_; }
    Price get_price() const { return price_; }
    SideType get_side() const { return side_; }
    Quantity get_quantity() const { return quantity_; }

    OrderPointer to_order_pointer(OrderType type) const {
        return std::make_shared<Order>(type, get_order_id(), get_side(), get_price(), get_quantity());
    }

private:
    OrderId order_id_;
    Price price_;
    SideType side_;
    Quantity quantity_;

};