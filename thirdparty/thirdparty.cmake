include(thirdparty/basis_universal/basis_universal.cmake)

file(GLOB_RECURSE src_zstd thirdparty/zstd/*.c)
list(APPEND SRC ${src_zstd})

add_compile_definitions(BT_USE_OLD_DAMPING_METHOD)
file(GLOB_RECURSE src_bullet thirdparty/bullet/*.c)
list(APPEND SRC ${src_bullet})

#add_subdirectory(bullet)

#add_subdirectory(cvtt)

#add_subdirectory(embree)

#add_subdirectory(enet)

#add_subdirectory(etcpak)

#add_subdirectory(freetype)

#add_subdirectory(glslang)

#set(thirdparty_libraries zstd basis_universal bullet cvtt embree)
