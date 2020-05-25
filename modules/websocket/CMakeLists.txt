project(module_websocket)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

if(NOT ${target} STREQUAL "javascript")
    target_link_libraries(${PROJECT_NAME} PRIVATE wslay)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)
