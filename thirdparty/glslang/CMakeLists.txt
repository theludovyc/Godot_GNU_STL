project(glslang)

file(GLOB_RECURSE src CInterface/*.cpp GenericCodeGen/*.cpp MachineIndependant/*.cpp)

if(WIN32)
    list(APPEND src glslang/OSDependent/Windows/ossource.cpp)
else()
    list(APPEND src glslang/OSDependent/Unix/ossource.cpp)
endif()

add_compile_definitions(ENABLE_OPT=0)

add_library(${PROJECT_NAME} ${src})

target_include_directories(${PROJECT_NAME} PUBLIC .)