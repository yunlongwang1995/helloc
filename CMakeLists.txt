PROJECT(helloc)
cmake_minimum_required(VERSION 3.21)

add_executable(hello main.cc)

add_subdirectory(examples)

add_subdirectory(internal)

add_subdirectory(data_strucure)