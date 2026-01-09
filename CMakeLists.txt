cmake_minimum_required(VERSION 3.10)
project(FieldPhysicsProjects VERSION 0.2)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lib)
add_subdirectory(src)

