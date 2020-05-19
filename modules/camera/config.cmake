
if(${target} STREQUAL "iphone" OR ${target} STREQUAL "osx" OR ${target} STREQUAL "windows")
set(module_ENABLED ON)
else()
set(module_ENABLED OFF)
endif()

