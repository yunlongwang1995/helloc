PROJECT(helloc)
cmake_minimum_required(VERSION 3.21)
add_executable(hello main.cc)

add_subdirectory(1_标准库STL)
add_subdirectory(2_数据结构)
add_subdirectory(3_算法)
add_subdirectory(8_key_words)
add_subdirectory(6_io)
add_subdirectory(5_thread)

add_subdirectory(9_utils)
