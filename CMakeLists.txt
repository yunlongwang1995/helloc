cmake_minimum_required(VERSION 3.21)
project(hello)

add_executable(hello
        main.cc
        example/person.cc

        include/zdb/status.h
        include/zdb/zdb_namespace.h
        include/zdb/zengine.h
        include/zdb/zoptions.h
        include/zdb/ztable.h

        db/db_impl_open.cc)

add_subdirectory(arrow)

set(CMAKE_CXX_STANDARD 17)