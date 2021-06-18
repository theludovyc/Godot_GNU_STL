project(modules_bmp)

add_library(${PROJECT_NAME} image_loader_bmp.cpp register_types.cpp)

target_include_directories(${PROJECT_NAME} .)
