cmake_minimum_required(VERSION 3.21)

find_package(Arrow REQUIRED)
include_directories( ${Arrow_INCLUDE_DIR} )

#如果找到了(Arrow_FOUND会被设置为True，是一种约定，你也可以使用自己喜欢的变量<但是不建议这么做>)
if (Arrow_FOUND)
    #打印相关的信息
    message(STATUS "Arrow_FOUND:${Arrow_FOUND}")
    message(STATUS "Arrow_version:${Arrow_VERSION}")
    message(STATUS "Arrow_include:${Arrow_INCLUDE_DIR}")
    message(STATUS "Arrow_library:${Arrow_LIBRARY}")
endif()

add_executable(arrow_example main.cpp)
target_link_libraries(arrow_example PRIVATE arrow_shared)