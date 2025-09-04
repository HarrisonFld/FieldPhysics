set(LIB_NAME "lib_engine")

FILE(GLOB_RECURSE LIB_ENGINE_FILES *.c) # Add all .c files in directory to library
add_library(${LIB_NAME} ${LIB_ENGINE_FILES})

target_link_libraries(${LIB_NAME} m) # <math.h>

target_include_directories(${LIB_NAME} PUBLIC core)
target_include_directories(${LIB_NAME} PUBLIC physics)
