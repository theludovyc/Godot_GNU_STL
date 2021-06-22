include(thirdparty/basis_universal/basis_universal.cmake)

macro(buildThirdpartyFile dirName ext)
    file(GLOB_RECURSE src_${dirName} thirdparty/${dirName}/${ext})
    list(APPEND SRC ${src_${dirName}})
endmacro()

macro(buildThirdpartyFileC dirName)
    buildThirdpartyFile(${dirName} *.c)
endmacro()

macro(buildThridparyFileCpp dirName)
    buildThirdpartyFile(${dirName} *.cpp)
endmacro()

include(thirdparty/bullet/bullet.cmake)

list(APPEND SRC thirdparty/cvtt/ConvectionKernels.cpp)

#buildThridparyFileCpp(embree)

add_compile_definitions(GODOT_ENET)
buildThirdpartyFileC(enet)

buildThridparyFileCpp(etcpak)

include(thirdparty/freetype/freetype.cmake)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(ZLIB_DEBUG)
endif()

buildThirdpartyFileC(zstd)

#add_subdirectory(glslang)

#set(thirdparty_libraries zstd basis_universal bullet cvtt embree)
