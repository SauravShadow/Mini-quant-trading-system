#include "utils/logger.hpp"
#include <iostream>

void Logger::log(const std::string& msg) {
    std::cout << "[LOG] " << msg << std::endl;
}