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

add_subdirectory(thirdparty)

#add_library(${PROJECT_NAME} ${thirdparty_librairies})