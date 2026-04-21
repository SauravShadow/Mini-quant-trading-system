#include "broker/flattrade_client.hpp"
#include "execution/execution_engine.hpp"
#include "execution/order_manager.hpp"
#include "feature_engine/feature_calculator.hpp"
#include "market_data/market_data_handler.hpp"
#include "risk/risk_manager.hpp"
#include "strategy/rule_based_strategy.hpp"
#include "strategy/ml_strategy.hpp"
#include "core/event_loop.hpp"
#include <thread>
#include <chrono>

int main() {
    MarketDataHandler market;
    FeatureCalculator feature;
    RuleBasedStrategy ruleStrategy;
    MLStrategy mlStrategy;
    RiskManager risk;
    OrderManager orderMgr;
    FlattradeClient broker;
    ExecutionEngine exec(&broker, &orderMgr);

    EventLoop loop;
    // Inject dependencies
    loop.featureCalc = &feature;
    loop.strategy = &mlStrategy;
    loop.fallbackStrategy = &ruleStrategy;
    loop.risk = &risk;
    loop.orderMgr = &orderMgr;
    loop.exec = &exec;

    loop.start();

    // Push ticks into pipeline
    market.start([&](const MarketTick& tick) {
        loop.tickQueue.push(tick);
    });

    std::this_thread::sleep_for(std::chrono::seconds(20));
}