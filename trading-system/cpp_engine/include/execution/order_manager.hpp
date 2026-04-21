#pragma once
#include "order.hpp"
#include <unordered_map>

class OrderManager {
    std::unordered_map<int, Order> orders;
    int nextId = 1;

public:
    Order createOrder(const std::string& symbol, int qty, double price, Side side);

    void onOrderSent(int orderId);
    void onOrderAck(int orderId);
    void onOrderFilled(int orderId);
    void onOrderRejected(int orderId);

    Order* getOrder(int orderId);
};
