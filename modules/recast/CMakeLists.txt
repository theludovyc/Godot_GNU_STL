project(module_recast)

# TODO : usefull MODULE_CSG_ENABLED and MODULE_GRIDMAP_ENABLED ???

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE recastnavigation)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore godotScene)
