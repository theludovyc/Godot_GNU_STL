project(minizip)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})


target_link_libraries(${PROJECT_NAME} PRIVATE zlib)