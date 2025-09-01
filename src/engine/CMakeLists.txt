find_package(m)

FILE(GLOB C_ENGINE_FILES *.c) # Add all .c files in directory to library
add_library(lib_engine ${C_ENGINE_FILES})

target_link_libraries(lib_engine m)