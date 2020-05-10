project(godotCoreAudio)

# TODO : add find_package for AudioUnit and CoreAudio 

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

# TODO : remove
target_compile_definitions(${PROJECT_NAME} PRIVATE -DCOREAUDIO_ENABLED)

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")