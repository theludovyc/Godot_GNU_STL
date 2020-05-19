# TODO : this is not module if is not set editor while crash

project(module_mbedtls)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE mbedtls)

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../..")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")


target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

if(NOT tools)
    # godotEditor
    target_link_libraries(${exe_name} PRIVATE godotEditor)
endif()