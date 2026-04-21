#pragma once
#include "strategy/strategy_interface.hpp"
#include "ml_client/ml_client.hpp"

class MLStrategy : public IStrategy {
    MLClient ml;

public:
    std::optional<Order> onFeatures(const Features& f) override;
};
