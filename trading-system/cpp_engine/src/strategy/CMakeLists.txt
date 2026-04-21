file(GLOB SRC_FILES "*.cpp")
add_library(strategy STATIC ${SRC_FILES})
target_include_directories(strategy PUBLIC ${CMAKE_SOURCE_DIR}/include)
