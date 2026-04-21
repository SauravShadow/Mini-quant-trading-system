file(GLOB SRC_FILES "*.cpp")
add_library(market_data STATIC ${SRC_FILES})
target_include_directories(market_data PUBLIC ${CMAKE_SOURCE_DIR}/include)
