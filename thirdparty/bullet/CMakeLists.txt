project(bullet)

file(GLOB_RECURSE SRC ./*.cpp)

add_library(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC .)