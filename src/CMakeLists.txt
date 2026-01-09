find_package(SDL3 REQUIRED)

# Create executable and link libraries
FILE(GLOB SOURCE_FILES *.c) # Add all .c files in directory to library
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3
)
