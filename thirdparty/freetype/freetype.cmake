set(src_freetype
        thirdparty/freetype/src/autofit/autofit.c
        thirdparty/freetype/src/base/ftbase.c
        thirdparty/freetype/src/base/ftbbox.c
        thirdparty/freetype/src/base/ftbdf.c
        thirdparty/freetype/src/base/ftbitmap.c
        thirdparty/freetype/src/base/ftcid.c
        thirdparty/freetype/src/base/ftdebug.c
        thirdparty/freetype/src/base/ftfstype.c
        thirdparty/freetype/src/base/ftgasp.c
        thirdparty/freetype/src/base/ftglyph.c
        thirdparty/freetype/src/base/ftgxval.c
        thirdparty/freetype/src/base/ftinit.c
        thirdparty/freetype/src/base/ftmm.c
        thirdparty/freetype/src/base/ftotval.c
        thirdparty/freetype/src/base/ftpatent.c
        thirdparty/freetype/src/base/ftpfr.c
        thirdparty/freetype/src/base/ftstroke.c
        thirdparty/freetype/src/base/ftsynth.c
        thirdparty/freetype/src/base/ftsystem.c
        thirdparty/freetype/src/base/fttype1.c
        thirdparty/freetype/src/base/ftwinfnt.c
        thirdparty/freetype/src/bdf/bdf.c
        thirdparty/freetype/src/bzip2/ftbzip2.c
        thirdparty/freetype/src/cache/ftcache.c
        thirdparty/freetype/src/cff/cff.c
        thirdparty/freetype/src/cid/type1cid.c
        thirdparty/freetype/src/gxvalid/gxvalid.c
        thirdparty/freetype/src/gzip/ftgzip.c
        thirdparty/freetype/src/lzw/ftlzw.c
        thirdparty/freetype/src/otvalid/otvalid.c
        thirdparty/freetype/src/pcf/pcf.c
        thirdparty/freetype/src/pfr/pfr.c
        thirdparty/freetype/src/psaux/psaux.c
        thirdparty/freetype/src/pshinter/pshinter.c
        thirdparty/freetype/src/psnames/psnames.c
        thirdparty/freetype/src/raster/raster.c
        thirdparty/freetype/src/smooth/smooth.c
        thirdparty/freetype/src/truetype/truetype.c
        thirdparty/freetype/src/type1/type1.c
        thirdparty/freetype/src/type42/type42.c
        thirdparty/freetype/src/winfonts/winfnt.c
        thirdparty/freetype/src/sfnt/sfnt.c
        )

list(APPEND SRC ${src_freetype})

#todo
#if env[platform] == uwp:
# Include header for UWP to fix build issues
#env_freetype.Append(CCFLAGS=[/FI 'modules/freetype/uwpdef.h'])
# Globally too as freetype is used in scene (see bottom)
#env.Append(CCFLAGS=[/FI 'modules/freetype/uwpdef.h'])

add_compile_definitions(FT2_BUILD_LIBRARY FT_CONFIG_OPTION_USE_PNG)

#todo
# Must be done after all CPPDEFINES are being set so we can copy them.
#if env[platform] == javascript:
# Forcibly undefine this macro so SIMD is not used in this file
# since currently unsupported in WASM
#tmp_env = env_freetype.Clone()
#tmp_env.Append(CPPFLAGS=[-U__OPTIMIZE__])

list(APPEND INCLUDE_DIR thirdparty/freetype/include)
