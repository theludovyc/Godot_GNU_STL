project(godotWindows)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

# TODO : remove
target_compile_definitions(${PROJECT_NAME} PRIVATE -DWINDOWS_ENABLED)

target_link_libraries(${PROJECT_NAME} PRIVATE shlwapi)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)
