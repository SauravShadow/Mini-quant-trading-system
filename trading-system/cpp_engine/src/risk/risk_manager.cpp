#include "risk/risk_manager.hpp"

bool RiskManager::validate(const Order& order) {
    return order.quantity <= rules.maxQty;
}