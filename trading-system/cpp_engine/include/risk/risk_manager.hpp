#pragma once
#include "execution/order.hpp"
#include "risk_rules.hpp"

class RiskManager {
    RiskRules rules;

public:
    bool validate(const Order& order);
};
