project(libogg)

file(GLOB header "*.h")
file(GLOB c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})

target_include_directories(${PROJECT_NAME} PUBLIC ".")

target_link_libraries(${PROJECT_NAME} PUBLIC godotCore)