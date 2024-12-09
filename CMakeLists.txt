cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(minecraft VERSION 1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(lib/glfw)

file(GLOB_RECURSE CPP_FILES src/*.cpp)
file(GLOB_RECURSE C_FILES src/*.c)

add_executable(minecraft ${CPP_FILES} ${C_FILES})

target_include_directories(minecraft PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(minecraft OpenGL::GL glfw)