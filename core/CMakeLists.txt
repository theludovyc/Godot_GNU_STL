project(core)

file(GLOB src error/*.cpp os/*.cpp templates/*.cpp)

add_library(${PROJECT_NAME} ${src})

target_include_directories(${PROJECT_NAME} PUBLIC .)
