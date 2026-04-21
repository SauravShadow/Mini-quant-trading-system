#include "market_data/market_data_handler.hpp"
#include <thread>
#include <chrono>

void MarketDataHandler::start(Callback cb) {
    std::thread([cb]() {
        for (int i = 0; i < 50; i++) {
            MarketTick tick{"NIFTY", 100.0 + i, time(nullptr)};
            cb(tick);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }).detach();
}