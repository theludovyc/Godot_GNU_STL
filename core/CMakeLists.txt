project(core)

file(GLOB_RECURSE src ./*.cpp)

add_library(${PROJECT_NAME} ${src})

target_include_directories(${PROJECT_NAME} PUBLIC .)
