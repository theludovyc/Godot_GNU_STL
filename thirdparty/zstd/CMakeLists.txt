project(zstd)

file(GLOB_RECURSE SRC *.c)

add_library(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC .)
