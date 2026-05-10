#include "market_data/market_tick.hpp"
#include <chrono>
#include <functional>
#include <thread>

class MarketDataHandler {
public:
  using Callback = std::function<void(const MarketTick &)>;

  void start(Callback cb) {
    std::thread([cb]() {
      for (int i = 0; i < 20; i++) {
        MarketTick tick{"NIFTY", 100.0 + i, time(nullptr)};
        cb(tick);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }).detach();
  }
};