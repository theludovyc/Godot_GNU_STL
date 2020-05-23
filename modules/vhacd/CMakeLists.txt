project(module_vhacd)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE vhacd)

target_link_libraries(${PROJECT_NAME} PRIVATE godotScene)
