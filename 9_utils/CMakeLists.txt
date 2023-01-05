file(GLOB_RECURSE KEY_WORDS_SRCS *.cc)

foreach(sourcefile ${KEY_WORDS_SRCS})
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable(${exename} ${sourcefile})
endforeach()
