file(GLOB SRC_FILES "*.cpp")
add_library(core STATIC ${SRC_FILES})
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/include)
