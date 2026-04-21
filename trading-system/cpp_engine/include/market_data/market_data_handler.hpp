#pragma once
#include "market_tick.hpp"
#include <functional>

class MarketDataHandler {
public:
    using Callback = std::function<void(const MarketTick&)>;
    void start(Callback cb);
};
