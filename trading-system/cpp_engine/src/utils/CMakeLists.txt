file(GLOB SRC_FILES "*.cpp")
add_library(utils STATIC ${SRC_FILES})
target_include_directories(utils PUBLIC ${CMAKE_SOURCE_DIR}/include)
