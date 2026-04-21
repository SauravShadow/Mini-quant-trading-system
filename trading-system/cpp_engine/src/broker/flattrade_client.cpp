#include "broker/flattrade_client.hpp"
#include <iostream>

void FlattradeClient::placeOrder(const Order& order) {
    std::cout << "Order sent: " << order.symbol
              << " @ " << order.price << std::endl;
}