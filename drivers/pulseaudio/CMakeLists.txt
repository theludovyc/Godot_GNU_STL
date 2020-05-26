project(godotPulseAudio)

find_package(PulseAudio REQUIRED)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE ${PulseAudio_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

# TODO : remove
target_compile_definitions(${PROJECT_NAME} PRIVATE -DPULSEAUDIO_ENABLED)

target_include_directories(${PROJECT_NAME} PRIVATE ${PulseAudio_INCLUDE_DIRS})