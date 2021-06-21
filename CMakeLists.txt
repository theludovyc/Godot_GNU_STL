cmake_minimum_required(VERSION 3.10)

# set the project name
project(godot_stl)

find_package(Python3)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(tools "Build the tools (a.k.a. the Godot editor)" ON)
if (tools)
    add_compile_definitions(TOOLS_ENABLED)
endif ()

include_directories(${PROJECT_NAME} PUBLIC .)

if (UNIX AND NOT APPLE)
    include_directories(platform/linuxbsd)
endif ()

if (WIN32)
    include_directories(platform/windows)
endif ()

add_custom_command(
        OUTPUT core/version_hash.gen.h
        COMMAND ${Python_EXECUTABLE} pygen_script/generate_version.py
        WORKING_DIRECTORY .
        DEPENDS pygen_script/generate_version.py
)

set(SRC)

set(MBEDTLS_CONFIG_FILE thirdparty/mbedtls/include/godot_core_mbedtls_config.h)

include(core/core.cmake)

#add_subdirectory(scene)

include(thirdparty/thirdparty.cmake)

add_library(${PROJECT_NAME} ${SRC})

#add_subdirectory(modules)

enable_testing()
add_subdirectory(tests)

#add_library(${PROJECT_NAME} ${thirdparty_librairies})
