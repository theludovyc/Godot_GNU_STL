cmake_minimum_required(VERSION 3.10)

# set the project name
project(godot_stl)

find_package(Python3)

set(SRC)

set(INCLUDE_DIR)

macro(generateFile filePath)
get_filename_component(fileName ${filePath} NAME_WE)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${filePath}
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_${fileName}.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_${fileName}.py
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/${filePath})
endmacro()

macro(generateHeader filePath)
    generateFile(${filePath}.gen.h)
endmacro()

macro(generateSource filePath)
    generateFile(${filePath}.gen.cpp)
endmacro()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

option(tools "Build the tools (a.k.a. the Godot editor)" ON)
if (tools)
    add_compile_definitions(TOOLS_ENABLED)
endif ()

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(DEBUG_ENABLED)
endif()

if (UNIX AND NOT APPLE)
    include_directories(platform/linuxbsd)
endif ()

if (WIN32)
    include_directories(platform/windows)
endif ()

include(core/core.cmake)

set(MODULES_DOC_CLASSES)
include(modules/modules.cmake)

if(tools)
    include(editor/editor.cmake)
endif()

include(scene/scene.cmake)

include(servers/servers.cmake)

include(drivers/drivers.cmake)

include(main/main.cmake)

add_library(${PROJECT_NAME} ${SRC})

target_compile_definitions(${PROJECT_NAME} PUBLIC NO_THREADS)

target_include_directories(${PROJECT_NAME} PUBLIC . ${INCLUDE_DIR})

enable_testing()
add_subdirectory(tests)
