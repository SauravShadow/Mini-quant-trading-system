cmake_minimum_required(VERSION 3.15)
project(cpp_engine LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(src/broker)
add_subdirectory(src/core)
add_subdirectory(src/execution)
add_subdirectory(src/feature_engine)
add_subdirectory(src/market_data)
add_subdirectory(src/ml_client)
add_subdirectory(src/risk)
add_subdirectory(src/strategy)
add_subdirectory(src/utils)

add_executable(cpp_engine src/main.cpp)
target_include_directories(cpp_engine PRIVATE include)

find_package(CURL REQUIRED)
target_link_libraries(cpp_engine PRIVATE 
    broker core execution feature_engine market_data ml_client risk strategy utils CURL::libcurl
)
