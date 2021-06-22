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

add_compile_definitions(BT_USE_OLD_DAMPING_METHOD)
buildThirdpartyFileC(bullet)

buildThirdpartyFileC(zstd)

list(APPEND SRC thirdparty/cvtt/ConvectionKernels.cpp)

#buildThridparyFileCpp(embree)

add_compile_definitions(GODOT_ENET)
buildThirdpartyFileC(enet)

#add_subdirectory(etcpak)

#add_subdirectory(freetype)

#add_subdirectory(glslang)

#set(thirdparty_libraries zstd basis_universal bullet cvtt embree)
