set(src_thirdparty_png
        thirdparty/libpng/png.c
        thirdparty/libpng/pngerror.c
        thirdparty/libpng/pngget.c
        thirdparty/libpng/pngmem.c
        thirdparty/libpng/pngpread.c
        thirdparty/libpng/pngread.c
        thirdparty/libpng/pngrio.c
        thirdparty/libpng/pngrtran.c
        thirdparty/libpng/pngrutil.c
        thirdparty/libpng/pngset.c
        thirdparty/libpng/pngtrans.c
        thirdparty/libpng/pngwio.c
        thirdparty/libpng/pngwrite.c
        thirdparty/libpng/pngwtran.c
        thirdparty/libpng/pngwutil.c
        )

#TODO neon

file(GLOB src_drivers_png drivers/png/*.cpp)

list(APPEND SRC ${src_thirdparty_png} ${src_drivers_png})
