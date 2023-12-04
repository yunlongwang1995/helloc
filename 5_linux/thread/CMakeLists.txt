file(GLOB_RECURSE THREAD_SRCS *.cc)

foreach(sourcefile ${THREAD_SRCS})
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable(${exename} ${sourcefile})
endforeach()
