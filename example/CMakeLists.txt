find_package(SDL3 REQUIRED)

set(TESTING_NAME FieldEngineTest)

# Create executable and link libraries
FILE(GLOB SOURCE_FILES *.c) # Add all .c files in directory to library
add_executable(${TESTING_NAME} ${SOURCE_FILES})

target_link_libraries(${TESTING_NAME} PRIVATE
    FieldEngine
    SDL3
)

