#include "execution/execution_engine.hpp"
#include <iostream>

ExecutionEngine::ExecutionEngine(IBroker* b, OrderManager* mgr)
    : broker(b), orderMgr(mgr) {}

void ExecutionEngine::execute(Order& order) {
    orderMgr->onOrderSent(order.id);

    // simulate broker interaction
    broker->placeOrder(order);

    // simulate response (replace with real callback later)
    orderMgr->onOrderAck(order.id);
    orderMgr->onOrderFilled(order.id);

    std::cout << "Order " << order.id << " FILLED\n";
}