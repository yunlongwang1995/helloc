file(GLOB_RECURSE IO_SRCS *.cc)

foreach(sourcefile ${IO_SRCS})
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable(${exename} ${sourcefile})
endforeach()
