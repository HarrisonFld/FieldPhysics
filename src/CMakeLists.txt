FILE(GLOB_RECURSE SOURCE_FILES *.c)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC modules)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
)

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
)