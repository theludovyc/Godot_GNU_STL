project(module_svg)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_compile_definitions(${PROJECT_NAME} PUBLIC -DSVG_ENABLED)

target_link_libraries(${PROJECT_NAME} PRIVATE nanosvg)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)