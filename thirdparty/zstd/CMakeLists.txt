project(zstd)

file(GLOB SRC common/*.c compress/*.c decompress/*.c)

add_library(${PROJECT_NAME} ${SRC})

target_include_directories(zstd PUBLIC . common compress decompress)