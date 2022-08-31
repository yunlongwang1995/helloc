set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(thread 1_thread.cc)

add_executable(mutex 2_0_mutex.cc)
add_executable(lock_guard 2_1_lock_guard.cc)
add_executable(unique_lock 2_2_unique_lock.cc)

add_executable(atomic 3_atomic.cc)

add_executable(convar 4_convar.cc)