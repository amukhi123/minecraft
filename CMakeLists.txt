cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(minecraft VERSION 1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(lib/glfw)

# Remove src/*.c (glad.c should be in the libs folder)
file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.c)
file(GLOB_RECURSE HEADER_FILES src/*.h)

add_executable(minecraft ${SRC_FILES} ${HEADER_FILES})

target_include_directories(minecraft PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(minecraft OpenGL::GL glfw)