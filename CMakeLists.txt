cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

PROJECT(helloc)
add_definitions("-Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(main main.cc)

add_subdirectory(1_STL)

add_subdirectory(3_study/ds)
add_subdirectory(3_study/algorithm)

add_subdirectory(5_linux/thread)
add_subdirectory(5_linux/io)
add_subdirectory(5_linux/socket)

add_subdirectory(8_c_key_words)
add_subdirectory(9_utils)