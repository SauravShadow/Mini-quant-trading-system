#pragma once
#include <string>

struct MarketTick {
  std::string symbol;
  double price;
  long timestamp;
};