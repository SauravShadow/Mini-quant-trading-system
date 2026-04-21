#include "ml_client/ml_client.hpp"
#include "ml_client/http_client.hpp"
#include <sstream>

double MLClient::predict(const Features& f) {
    HttpClient http;

    std::stringstream ss;
    ss << "{ \"price\": " << f.price
       << ", \"moving_avg\": " << f.moving_avg << " }";

    std::string response = http.post("http://127.0.0.1:8000/predict", ss.str());

    // VERY SIMPLE parsing (improve later)
    if (response.find("0.8") != std::string::npos) return 0.8;
    return 0.3;
}