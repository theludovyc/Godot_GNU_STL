project(core_error)

add_library(${PROJECT_NAME} error_macros.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC .)
