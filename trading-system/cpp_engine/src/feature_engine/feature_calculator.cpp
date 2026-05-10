#include "feature_engine/feature_calculator.hpp"

Features FeatureCalculator::compute(const MarketTick &tick) {
  window.push_back(tick.price);
  if (window.size() > 5) {
    window.erase(window.begin());
  }
  double sum = 0;
  for (double price : window)
    sum += price;
  return {tick.price, sum / window.size()};
}