add_library(broker STATIC flattrade_client.cpp)
target_include_directories(broker PUBLIC ${CMAKE_SOURCE_DIR}/include)
