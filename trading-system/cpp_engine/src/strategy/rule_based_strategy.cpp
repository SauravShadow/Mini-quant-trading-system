#include "strategy/rule_based_strategy.hpp"

std::optional<Order> RuleBasedStrategy::onFeatures(const Features& f) {
    if (f.price > f.moving_avg) {
        return Order{0, "NIFTY", 1, f.price, Side::BUY, OrderState::NEW};
    }
    return std::nullopt;
}