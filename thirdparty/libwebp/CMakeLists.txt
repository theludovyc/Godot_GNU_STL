project(libwebp)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})

target_include_directories(${PROJECT_NAME} PRIVATE ".")

target_include_directories(${PROJECT_NAME} PUBLIC "src")