project(module_bullet)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE bullet)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

# TODO: suppress
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")