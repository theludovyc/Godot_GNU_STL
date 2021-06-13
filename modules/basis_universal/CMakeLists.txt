project(modules_basis_universal)

add_library(${PROJECT_NAME} register_types.cpp texture_basisu.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC .)