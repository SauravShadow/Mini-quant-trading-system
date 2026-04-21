#pragma once
#include "../execution/order.hpp"

class IBroker {
public:
  virtual void placeOrder(const Order &) = 0;
  virtual ~IBroker() = default;
};