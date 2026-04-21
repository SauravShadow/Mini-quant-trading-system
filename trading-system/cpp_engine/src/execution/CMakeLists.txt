file(GLOB SRC_FILES "*.cpp")
add_library(execution STATIC ${SRC_FILES})
target_include_directories(execution PUBLIC ${CMAKE_SOURCE_DIR}/include)
