cmake_minimum_required(VERSION 3.10)
project(FieldEngine VERSION 0.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(example)