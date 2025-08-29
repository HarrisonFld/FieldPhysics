#[===[
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
]===]

find_package(PkgConfig REQUIRED)
find_package(raylib REQUIRED)

# Include GLib headers
pkg_check_modules(GLIB REQUIRED glib-2.0)
include_directories(${GLIB_INCLUDE_DIRS})
link_directories(${GLIB_LIBRARY_DIRS})
add_definitions(${GLIB_CFLAGS_OTHER})

# Create executable and link libraries
add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PRIVATE ${GLIB_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${GLIB_LIBRARY_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE ${GLIB_CFLAGS_OTHER})


target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLIB_LIBRARIES})