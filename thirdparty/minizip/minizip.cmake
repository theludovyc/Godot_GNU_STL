# Minizip library, could be unbundled in theory
# However, our version has some custom modifications, so it won't compile with the system one

set(src_thirdparty_minizip
        thirdparty/minizip/ioapi.c
        thirdparty/minizip/unzip.c
        thirdparty/minizip/zip.c
        )

list(APPEND SRC ${src_thirdparty_minizip})
