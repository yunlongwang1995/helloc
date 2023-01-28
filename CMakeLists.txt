PROJECT(helloc)
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
add_definitions("-Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(main main.cc)

add_subdirectory(1_STL)
add_subdirectory(2_ds)
add_subdirectory(3_algorithm)
add_subdirectory(5_thread)
add_subdirectory(6_io)
add_subdirectory(8_key_words)
add_subdirectory(9_utils)