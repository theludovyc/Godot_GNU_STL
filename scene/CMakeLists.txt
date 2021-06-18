project(scene)

file(GLOB_RECURSE src ./*.cpp)

add_library(${PROJECT_NAME} ${src})
