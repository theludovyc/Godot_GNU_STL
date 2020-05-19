project(enet)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${cpp} ${c})

# TODO : remove ... why ???
target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)
target_compile_definitions(${PROJECT_NAME} PUBLIC -DGODOT_ENET)

target_include_directories(${PROJECT_NAME} PUBLIC ".")

