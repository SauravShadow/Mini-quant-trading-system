#pragma once
#include "broker/broker_interface.hpp"

class FlattradeClient : public IBroker {
public:
    void placeOrder(const Order& order) override;
};
