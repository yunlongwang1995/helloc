file(GLOB_RECURSE STL_SRCS *.cc)

foreach(sourcefile ${STL_SRCS})
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable(${exename} ${sourcefile})
endforeach()
