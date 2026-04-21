#pragma once
#include "market_data/market_tick.hpp"
#include "indicators.hpp"
#include <vector>

class FeatureCalculator {
    std::vector<double> window;

public:
    Features compute(const MarketTick& tick);
};
