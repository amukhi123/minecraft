cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

project(minecraft VERSION 1.0)

find_package(OpenGL REQUIRED)

add_subdirectory(lib/glfw)

set(SRC_FILES src/main.cpp)

file(GLOB_RECURSE GFX_FILES src/gfx/*.cpp src/gfx/*.h)
file(GLOB_RECURSE UTIL_FILES src/util/*.cpp src/gfx/*.h)
file(GLOB_RECURSE SHADER_FILES res/*.vs res/*.fs)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${GFX_FILES} ${UTIL_FILES} ${SHADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/src")

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw)

if("${CMAKE_GENERATOR}" STREQUAL "Visual Studio 17 2022" OR "${CMAKE_GENERATOR}" STREQUAL "Visual Studio 16 2019")
	# Only apply to Visual Studio (to create filters)
	source_group("src" FILES ${SRC_FILES})
	source_group("src\\gfx" FILES ${GFX_FILES})
	source_group("src\\util" FILES ${UTIL_FILES})
	source_group("res\\shader" FILES ${SHADER_FILES})
	
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
		set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build/Debug")
	else()
        set_target_properties(${PROJECT_NAME} PROPERTOES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build/Release")
	endif()
endif()

if ("${CMAKE_GENERATOR}" STREQUAL "Ninja")
	# For clangd LSP with ninja build system
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
