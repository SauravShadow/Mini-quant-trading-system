file(GLOB SRC_FILES "*.cpp")
add_library(risk STATIC ${SRC_FILES})
target_include_directories(risk PUBLIC ${CMAKE_SOURCE_DIR}/include)
