project(basis_universal)

file(GLOB_RECURSE src *.c *.cpp)

add_library(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} src zstd)

target_include_directories(${PROJECT_NAME} PUBLIC .)