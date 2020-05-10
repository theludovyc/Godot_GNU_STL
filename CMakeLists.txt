cmake_minimum_required(VERSION 3.10)

include(cmake/compilegles.cmake)

set(CMAKE_CXX_STANDARD 17)
find_package(Python 3.5 COMPONENTS Interpreter REQUIRED)

project(godot)


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



add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(thirdparty)
add_subdirectory(main)