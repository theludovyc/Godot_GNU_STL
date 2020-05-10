
project(glad)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.c")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_include_directories(${PROJECT_NAME} PUBLIC ".")

target_compile_definitions(${PROJECT_NAME} PUBLIC -DGLAD_ENABLED -DGLES_OVER_GL)