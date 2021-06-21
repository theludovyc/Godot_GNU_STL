file(GLOB_RECURSE src_basis_universal thirdparty/basis_universal/*.c thirdparty/basis_universal/*.cpp)

list(APPEND SRC ${src_basis_universal})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BASISU_DEVEL_MESSAGES 1)
    set(BASISD_ENABLE_DEBUG_FLAGS 1)
endif()

if(tool)
    add_compile_definitions(BASISU_NO_IMG_LOADERS)
endif()
