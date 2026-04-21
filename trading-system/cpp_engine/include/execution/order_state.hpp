#pragma once

enum class OrderState {
    NEW,
    SENT,
    ACKNOWLEDGED,
    PARTIALLY_FILLED,
    FILLED,
    REJECTED,
    CANCELLED
};
