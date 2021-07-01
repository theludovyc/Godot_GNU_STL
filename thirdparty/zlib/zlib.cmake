# Zlib library, can be unbundled

set(src_thirdparty_zlib
        thirdparty/zlib/adler32.c
        thirdparty/zlib/compress.c
        thirdparty/zlib/crc32.c
        thirdparty/zlib/deflate.c
        thirdparty/zlib/infback.c
        thirdparty/zlib/inffast.c
        thirdparty/zlib/inflate.c
        thirdparty/zlib/inftrees.c
        thirdparty/zlib/trees.c
        thirdparty/zlib/uncompr.c
        thirdparty/zlib/zutil.c
        )

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(ZLIB_DEBUG)
endif ()

list(APPEND SRC ${src_thirdparty_zlib})
