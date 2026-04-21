#pragma once
#include "market_data/market_tick.hpp"
#include "feature_engine/indicators.hpp"
#include "execution/order.hpp"
#include <optional>

struct PipelineData {
    MarketTick tick;
    Features features;
    std::optional<Order> order;
};
