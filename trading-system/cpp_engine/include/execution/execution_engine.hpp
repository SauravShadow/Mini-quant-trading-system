#pragma once
#include "order.hpp"
#include "broker/broker_interface.hpp"
#include "execution/order_manager.hpp"

class ExecutionEngine {
    IBroker* broker;
    OrderManager* orderMgr;

public:
    ExecutionEngine(IBroker* b, OrderManager* mgr);

    void execute(Order& order);
};
