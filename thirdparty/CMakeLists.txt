
add_definitions(-w)

add_subdirectory(misc)
add_subdirectory(zlib)
add_subdirectory(minizip)
add_subdirectory(zstd)
add_subdirectory(mbedtls)
add_subdirectory(glad)
add_subdirectory(libpng)
add_subdirectory(freetype)
add_subdirectory(pcre2)
add_subdirectory(nanosvg)

remove_definitions(-w)