#pragma once
#include <string>
#include "order_state.hpp"

enum class Side { BUY, SELL };

struct Order {
    int id;
    std::string symbol;
    int quantity;
    double price;
    Side side;
    OrderState state;
};