project(etcpak)

file(GLOB_RECURSE SRC ./*.cpp)

add_library(${PROJECT_NAME} ${SRC})