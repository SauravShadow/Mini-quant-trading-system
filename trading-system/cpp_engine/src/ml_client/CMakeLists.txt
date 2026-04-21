file(GLOB SRC_FILES "*.cpp")
add_library(ml_client STATIC ${SRC_FILES})
target_include_directories(ml_client PUBLIC ${CMAKE_SOURCE_DIR}/include)
