file(GLOB SRC_FILES "*.cpp")
add_library(feature_engine STATIC ${SRC_FILES})
target_include_directories(feature_engine PUBLIC ${CMAKE_SOURCE_DIR}/include)
