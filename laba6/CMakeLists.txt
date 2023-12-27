cmake_minimum_required(VERSION 3.10)
project(laba6)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(laba6_exe main.cpp npc.cpp vip.cpp bear.cpp muskrat.cpp)

enable_testing()
add_executable(laba6_test test.cpp)
target_link_libraries(laba6_test ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND laba6_test)