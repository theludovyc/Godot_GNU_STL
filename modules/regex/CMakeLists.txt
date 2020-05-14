# TODO : remove and use std lib
project(module_regex)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})


# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../..")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

target_link_libraries(${PROJECT_NAME} PRIVATE pcre2-16)
target_link_libraries(${PROJECT_NAME} PRIVATE pcre2-32)
target_compile_options(${PROJECT_NAME} PRIVATE -DPCRE2_CODE_UNIT_WIDTH=0)