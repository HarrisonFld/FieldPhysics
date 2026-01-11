FILE(GLOB_RECURSE SOURCE_FILES *.c)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC modules)

target_link_libraries(${PROJECT_NAME} PRIVATE
    
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
)

# Enable flags for warnings for project maintenance
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
)

install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
)

# Dump all headers in the include directory
FILE(GLOB_RECURSE HEADER_FILES *.h)
install(FILES ${HEADER_FILES}
  DESTINATION include/${PROJECT_NAME}${PROJECT_VERSION}
)
