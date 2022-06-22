PROJECT(helloc)
cmake_minimum_required(VERSION 3.21)
add_executable(hello main.cc)

add_subdirectory(1_stl)
add_subdirectory(2_data_strucure)
add_subdirectory(3_algorithm)
add_subdirectory(4_key_words)
add_subdirectory(5_io)
add_subdirectory(6_thread)

add_subdirectory(8_util)
add_subdirectory(9_tmp)
