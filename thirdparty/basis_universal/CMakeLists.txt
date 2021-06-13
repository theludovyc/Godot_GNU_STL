project(basis_universal)

file(GLOB SRC encoder/*.c encoder/*.cpp)

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} SRC zstd)