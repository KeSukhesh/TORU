#include <Orderbook.h>

bool Orderbook::can_match(SideType side, Price price) const {
    if (side == SideType::BUY) {
        if (asks_.empty())
            return false;

        const auto& [best_ask, _] = *asks_.begin();
        return price >= best_ask;
    } else {
        if (bids_.empty())
            return false;

        const auto& [best_bid, _] = * bids_.begin();
        return price <= best_bid;
    }
}

Trades Orderbook::match_orders() {
    Trades trades;
    trades.reserve(orders_.size());

    while (true) {
        if (bids_.empty() || asks_.empty())
            break;

        auto& [bidPrice, bids] = *bids_.begin();
		auto& [askPrice, asks] = *asks_.begin();

		if (bidPrice < askPrice)
			break;

		while (!bids.empty() && !asks.empty()) {
			auto bid = bids.front();
			auto ask = asks.front();

			Quantity quantity = std::min(bid->get_remaining_quantity(), ask->get_remaining_quantity());
			bid->fill(quantity);
			ask->fill(quantity);

			if (bid->is_filled()) {
				bids.pop_front();
				orders_.erase(bid->get_order_id());
			}

			if (ask->is_filled()) {
				asks.pop_front();
				orders_.erase(ask->get_order_id());
			}

			trades.push_back(Trade{
				TradeInfo{ bid->get_order_id(), bid->get_price(), quantity },
				TradeInfo{ ask->get_order_id(), ask->get_price(), quantity }
            });

			on_order_matched(bid->get_price(), quantity, bid->is_filled());
			on_order_matched(ask->get_price(), quantity, ask->is_filled());
		}

        if (bids.empty()) {
            bids_.erase(bidPrice);
            data_.erase(bidPrice);
        }

        if (asks.empty()) {
            asks_.erase(askPrice);
            data_.erase(askPrice);
        }
    }

    if (!bids_.empty()) {
        auto& [_, bids] = *bids_.begin();
		auto& order = bids.front();
		if (order->get_order_type() == OrderType::FILL_AND_KILL)
			cancel_order(order->get_order_id());
    }

    if (!asks_.empty()) {
        auto& [_, asks] = *asks_.begin();
		auto& order = asks.front();
		if (order->get_order_type() == OrderType::FILL_AND_KILL)
			cancel_order(order->get_order_id());
    }

    return trades;
}

Trades Orderbook::add_order(OrderPointer order) {
	std::scoped_lock ordersLock{ orders_mutex_ };

	if (orders_.contains(order->get_order_id()))
		return { };

	if (order->get_order_type() == OrderType::MARKET) {
		if (order->get_side() == SideType::BUY && !asks_.empty()) {
			const auto& [worst_ask, _] = *asks_.rbegin();
			order->to_good_till_cancel(worst_ask);
		} else if (order->get_side() == SideType::SELL && !bids_.empty()) {
			const auto& [worst_bid, _] = *bids_.rbegin();
			order->to_good_till_cancel(worst_bid);
		} else
			return {};
	}

	if (order->get_order_type() == OrderType::FILL_AND_KILL && !can_match(order->get_side(), order->get_price()))
		return { };

	if (order->get_order_type() == OrderType::FILL_OR_KILL && !can_fully_fill(order->get_side(), order->get_price(), order->get_initial_quantity()))
		return { };

	OrderPointers::iterator iterator;

	if (order->get_side() == SideType::BUY) {
		auto& orders = bids_[order->get_price()];
		orders.push_back(order);
		iterator = std::prev(orders.end());
	} else {
		auto& orders = asks_[order->get_price()];
		orders.push_back(order);
		iterator = std::prev(orders.end());
	}

	orders_.insert({ order->get_order_id(), OrderEntry{ order, iterator } });
	on_order_added(order);

	return match_orders();

}
