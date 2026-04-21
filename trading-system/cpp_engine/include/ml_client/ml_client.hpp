#pragma once
#include "feature_engine/indicators.hpp"

class MLClient {
public:
    double predict(const Features& f);
};
