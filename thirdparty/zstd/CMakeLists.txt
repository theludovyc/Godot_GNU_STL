project(zstd)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})

target_compile_options(${PROJECT_NAME} PUBLIC -DZSTD_STATIC_LINKING_ONLY)
target_include_directories(${PROJECT_NAME} PUBLIC ".")
target_include_directories(${PROJECT_NAME} PUBLIC "./common")