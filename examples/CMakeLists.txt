
add_executable(vector_example vector_example.cc)

add_executable(deconstruction_example deconstruction_example.cc)

add_executable(smart_point_example smart_point_example.cc)

add_executable(const_example const_example.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(thread_example thread_example.cc)

add_executable(io_example io_example.cc)