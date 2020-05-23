project(tinyexr)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cc")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_include_directories(${PROJECT_NAME} PUBLIC ".")