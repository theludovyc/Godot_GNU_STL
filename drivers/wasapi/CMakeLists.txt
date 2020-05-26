project(godotWasapi)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

# TODO : remove
target_compile_definitions(${PROJECT_NAME} PRIVATE -DWASAPI_ENABLED)

target_link_libraries(${PROJECT_NAME} PRIVATE ksuser)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)
