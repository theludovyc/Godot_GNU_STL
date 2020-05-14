project(godotAlsaMidi)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE ${ALSA_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${ALSA_INCLUDE_DIRS})

# TODO : remove
target_compile_definitions(${PROJECT_NAME} PRIVATE -DALSAMIDI_ENABLED)

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")