#pragma once
#include "core/message_queue.hpp"
#include "market_data/market_tick.hpp"
#include "feature_engine/feature_calculator.hpp"
#include "strategy/strategy_interface.hpp"
#include "risk/risk_manager.hpp"
#include "execution/execution_engine.hpp"
#include "execution/order_manager.hpp"
#include <thread>

class EventLoop {
public:
    MessageQueue<MarketTick> tickQueue;
    MessageQueue<Features> featureQueue;
    MessageQueue<Order> orderQueue;

    FeatureCalculator* featureCalc;
    IStrategy* strategy;
    IStrategy* fallbackStrategy = nullptr;
    RiskManager* risk;
    OrderManager* orderMgr;
    ExecutionEngine* exec;

    void start();
};
