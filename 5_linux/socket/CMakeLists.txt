file(GLOB_RECURSE SOCKET_SRCS *.cc)

foreach(sourcefile ${SOCKET_SRCS})
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable(${exename} ${sourcefile})
endforeach()
