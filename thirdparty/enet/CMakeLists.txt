project(enet)

file(GLOB_RECURSE SRC ./*.c)

add_compile_definitions(GODOT_ENET)

add_library(${PROJECT_NAME} ${SRC})