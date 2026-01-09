FILE(GLOB SOURCE_FILES *.c)
add_library(FieldPhysics STATIC ${SOURCE_FILES})

target_include_directories(FieldPhysics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(FieldPhysics PUBLIC .)
