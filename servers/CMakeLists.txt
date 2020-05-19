project(godotServers)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})


# TODO : need to be set to private
target_link_libraries(${PROJECT_NAME} PUBLIC godotCore)

target_include_directories(${PROJECT_NAME} PUBLIC "../")
