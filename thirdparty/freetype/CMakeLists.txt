project(freetype)

#todo
#if env["platform"] == "uwp":
# Include header for UWP to fix build issues
#env_freetype.Append(CCFLAGS=["/FI", '"modules/freetype/uwpdef.h"'])
# Globally too, as freetype is used in scene (see bottom)
#env.Append(CCFLAGS=["/FI", '"modules/freetype/uwpdef.h"'])

file(GLOB_RECURSE SRC ./*.c)

add_compile_definitions(FT2_BUILD_LIBRARY FT_CONFIG_OPTION_USE_PNG)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(ZLIB_DEBUG)
endif()

#todo
#sfnt = thirdparty_dir + "src/sfnt/sfnt.c"
# Must be done after all CPPDEFINES are being set so we can copy them.
#if env["platform"] == "javascript":
# Forcibly undefine this macro so SIMD is not used in this file,
# since currently unsupported in WASM
#tmp_env = env_freetype.Clone()
#tmp_env.Append(CPPFLAGS=["-U__OPTIMIZE__"])
#sfnt = tmp_env.Object(sfnt)
#thirdparty_sources += [sfnt]

add_library(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC include)