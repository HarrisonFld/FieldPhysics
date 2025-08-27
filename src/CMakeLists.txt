include(FetchContent)
set(RAYLIB_VERSION 5.5.0)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP true
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "") # Don't build example code
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} raylib)