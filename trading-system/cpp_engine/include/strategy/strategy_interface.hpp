#pragma once
#include "../execution/order.hpp"
#include "../feature_engine/indicators.hpp"
#include <optional>

class IStrategy {
public:
  virtual std::optional<Order> onFeatures(const Features &features) = 0;
  virtual ~IStrategy() = default;
};