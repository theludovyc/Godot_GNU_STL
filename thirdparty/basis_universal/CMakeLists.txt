project(basis_universal)

file(GLOB_RECURSE src *.c *.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BASISU_DEVEL_MESSAGES 1)
    set(BASISD_ENABLE_DEBUG_FLAGS 1)
endif()

if(tool)
    add_compile_definitions(BASISU_NO_IMG_LOADERS)
endif()

add_library(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} src zstd)