cmake_minimum_required(VERSION 3.10)

# set the project name
project(godot_stl)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(tools "Build the tools (a.k.a. the Godot editor)" ON)
if(tools)
    add_compile_definitions(TOOLS_ENABLED)
endif()

include_directories(${PROJECT_NAME} PUBLIC .)

if(UNIX AND NOT APPLE)
    include_directories(platform/linuxbsd)
endif()

if(WIN32)
    include_directories(platform/windows)
endif()

#add_subdirectory(thirdparty)

#add_subdirectory(modules)

enable_testing()
add_subdirectory(tests)

#add_library(${PROJECT_NAME} ${thirdparty_librairies})
