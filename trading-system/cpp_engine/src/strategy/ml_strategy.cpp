#include "strategy/ml_strategy.hpp"

std::optional<Order> MLStrategy::onFeatures(const Features& f) {
    double score = ml.predict(f);

    if (score > 0.7) {
        return Order{0, "NIFTY", 1, f.price, Side::BUY, OrderState::NEW};
    }
    return std::nullopt;
}