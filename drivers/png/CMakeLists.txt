project(godotPng)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE png)

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")