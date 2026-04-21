#include "core/event_loop.hpp"
#include <thread>

void EventLoop::start() {
    // Thread 1: Feature calculation
    std::thread([&]() {
        while (true) {
            auto tick = tickQueue.pop();
            auto features = featureCalc->compute(tick);
            featureQueue.push(features);
        }
    }).detach();

    // Thread 2: Strategy
    std::thread([&]() {
        while (true) {
            auto features = featureQueue.pop();
            auto orderOpt = strategy->onFeatures(features);
            if (!orderOpt && fallbackStrategy) {
                orderOpt = fallbackStrategy->onFeatures(features);
            }
            if (orderOpt) {
                orderQueue.push(*orderOpt);
            }
        }
    }).detach();

    // Thread 3: Execution
    std::thread([&]() {
        while (true) {
            auto order = orderQueue.pop();
            
            auto managedOrder = orderMgr->createOrder(
                order.symbol,
                order.quantity,
                order.price,
                order.side
            );

            if (risk->validate(managedOrder)) {
                exec->execute(managedOrder);
            }
        }
    }).detach();
}