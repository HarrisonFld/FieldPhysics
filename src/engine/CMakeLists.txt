FILE(GLOB C_ENGINE_FILES *.c) # Add all .c files in directory to library
add_library(engine_lib ${C_ENGINE_FILES})