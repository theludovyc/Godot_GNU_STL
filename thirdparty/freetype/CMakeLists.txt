project(freetype)

file(GLOB_RECURSE header "*.h")

set(c "src/autofit/autofit.c"
"src/base/ftbase.c"
"src/base/ftbbox.c"
"src/base/ftbdf.c"
"src/base/ftbitmap.c"
"src/base/ftcid.c"
"src/base/ftdebug.c"
"src/base/ftfstype.c"
"src/base/ftgasp.c"
"src/base/ftglyph.c"
"src/base/ftgxval.c"
"src/base/ftinit.c"
"src/base/ftmm.c"
"src/base/ftotval.c"
"src/base/ftpatent.c"
"src/base/ftpfr.c"
"src/base/ftstroke.c"
"src/base/ftsynth.c"
"src/base/ftsystem.c"
"src/base/fttype1.c"
"src/base/ftwinfnt.c"
"src/bdf/bdf.c"
"src/bzip2/ftbzip2.c"
"src/cache/ftcache.c"
"src/cff/cff.c"
"src/cid/type1cid.c"
"src/gxvalid/gxvalid.c"
"src/gzip/ftgzip.c"
"src/lzw/ftlzw.c"
"src/otvalid/otvalid.c"
"src/pcf/pcf.c"
"src/pfr/pfr.c"
"src/psaux/psaux.c"
"src/pshinter/pshinter.c"
"src/psnames/psnames.c"
"src/raster/raster.c"
"src/smooth/smooth.c"
"src/truetype/truetype.c"
"src/type1/type1.c"
"src/type42/type42.c"
"src/winfonts/winfnt.c")

file(GLOB sfnt "src/sfnt/*.c")
list(APPEND c ${sfnt})

if(target STREQUAL "javscript")
    list(APPEND c "src/sfnt/sfnt.c")
endif()


add_library(${PROJECT_NAME} ${header} ${c})

# TODO : dont know for what is this 
# only for javscript
# tmp_env.Append(CPPFLAGS=['-U__OPTIMIZE__'])

# TODO : need this ?
# Also requires libpng headers
#  if env['builtin_libpng']:
#  env_freetype.Prepend(CPPPATH=["#thirdparty/libpng"])

target_compile_options(${PROJECT_NAME} PRIVATE -DFT2_BUILD_LIBRARY -DFT_CONFIG_OPTION_USE_PNG)
target_include_directories(${PROJECT_NAME} PUBLIC "./include")

target_link_libraries(${PROJECT_NAME} PRIVATE png)
