#pragma once
#include "strategy_interface.hpp"

class RuleBasedStrategy : public IStrategy {
public:
    std::optional<Order> onFeatures(const Features& f) override;
};
