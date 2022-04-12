cmake_minimum_required(VERSION 3.21)
project(hello)

set(CMAKE_CXX_STANDARD 17)

add_executable(hello
        main.cc

        include/zdb/status.h
        include/zdb/zdb_namespace.h
        include/zdb/zengine.h
        include/zdb/zoptions.h
        include/zdb/ztable.h
        include/zdb/meta_listener.h

        db/db_impl_open.cc
        db/zdb_local_impl.h
        db/options.h
        db/zdb_local_impl.cc
        db/zdb_rpc_impl.h
        db/zdb_rpc_impl.cc
        meta/default_listener.h
        db/ztable_manager.h)

add_subdirectory(examples)