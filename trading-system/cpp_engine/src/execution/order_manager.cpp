#include "execution/order_manager.hpp"
#include <iostream>

Order OrderManager::createOrder(const std::string& symbol, int qty, double price, Side side) {
    Order order;
    order.id = nextId++;
    order.symbol = symbol;
    order.quantity = qty;
    order.price = price;
    order.side = side;
    order.state = OrderState::NEW;

    orders[order.id] = order;
    return order;
}

void OrderManager::onOrderSent(int orderId) {
    orders[orderId].state = OrderState::SENT;
}

void OrderManager::onOrderAck(int orderId) {
    orders[orderId].state = OrderState::ACKNOWLEDGED;
}

void OrderManager::onOrderFilled(int orderId) {
    orders[orderId].state = OrderState::FILLED;
}

void OrderManager::onOrderRejected(int orderId) {
    orders[orderId].state = OrderState::REJECTED;
}

Order* OrderManager::getOrder(int orderId) {
    if (orders.find(orderId) != orders.end())
        return &orders[orderId];
    return nullptr;
}