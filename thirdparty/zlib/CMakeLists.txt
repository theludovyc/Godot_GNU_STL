project(zlib)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})

target_include_directories(${PROJECT_NAME} PUBLIC ".")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -DZLIB_DEBUG)
endif()

