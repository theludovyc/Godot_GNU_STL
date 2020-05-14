cmake_minimum_required(VERSION 3.11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(cmake/compilegles.cmake)
include(cmake/generate.cmake)

set(CMAKE_CXX_STANDARD 17)
find_package(Python 3.5 COMPONENTS Interpreter REQUIRED)

project(godot)

option(tools "Build the tools (a.k.a. the Godot editor)" ON)
if(tools)
  add_definitions(-DTOOLS_ENABLED)
endif()


set(target)
if(NOT DEFINED ${CMAKE_GENERATOR_PLATFORM})
  # linux
  if(UNIX AND NOT APPLE)
    set(target "x11")
	endif()
  # apple
  if(APPLE)
    set(target "osx")
	endif()
  # windows
  if(WIN32)
    set(target "windows")
	endif()
endif()


include(platform/${target}/definition.cmake)

add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(thirdparty)
add_subdirectory(main)
add_subdirectory(scene)
add_subdirectory(servers)
add_subdirectory(modules)
add_subdirectory(platform/${target})
if(tools)
  add_subdirectory(editor)
endif()
