project(mbedtls)

file(GLOB_RECURSE header "include/*.h")
file(GLOB_RECURSE c "library/*.c")

add_library(${PROJECT_NAME} ${header} ${c})

target_compile_options(${PROJECT_NAME} PRIVATE -DMBEDTLS_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/include/godot_core_mbedtls_config.h")
target_include_directories(${PROJECT_NAME} PUBLIC "include")