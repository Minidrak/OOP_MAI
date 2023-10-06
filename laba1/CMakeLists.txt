cmake_minimum_required(VERSION 3.0)

project(turk_numbers) 

set(SOURCE_EXE main.cpp) 

set(SOURCE_LIB turk_numbers.cpp) 

add_library(turk_numbers STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main turk_numbers)