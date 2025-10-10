set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

# Create executable and link libraries
FILE(GLOB SOURCE_FILES *.cpp) # Add all .c files in directory to library
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    OpenGL
    glfw
)
