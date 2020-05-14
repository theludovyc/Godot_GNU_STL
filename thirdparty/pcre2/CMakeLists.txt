project(pcre2)

option(builtin_pcre2_with_jit "Use JIT compiler for the built-in PCRE2 library" ON)

set(c "src/pcre2_auto_possess.c"
"src/pcre2_chartables.c"
"src/pcre2_compile.c"
"src/pcre2_config.c"
"src/pcre2_context.c"
"src/pcre2_convert.c"
"src/pcre2_dfa_match.c"
"src/pcre2_error.c"
"src/pcre2_extuni.c"
"src/pcre2_find_bracket.c"
"src/pcre2_jit_compile.c"
#"src/pcre2_jit_match.c" "src/pcre2_jit_misc.c" # these files are included in src/pcre2_jit_compile.c.
"src/pcre2_maketables.c"
"src/pcre2_match.c"
"src/pcre2_match_data.c"
"src/pcre2_newline.c"
"src/pcre2_ord2utf.c"
"src/pcre2_pattern_info.c"
"src/pcre2_script_run.c"
"src/pcre2_serialize.c"
"src/pcre2_string_utils.c"
"src/pcre2_study.c"
"src/pcre2_substitute.c"
"src/pcre2_substring.c"
"src/pcre2_tables.c"
"src/pcre2_ucd.c"
"src/pcre2_valid_utf.c"
"src/pcre2_xclass.c")

add_library(${PROJECT_NAME}-16 ${header} ${c})
add_library(${PROJECT_NAME}-32 ${header} ${c})

target_include_directories(${PROJECT_NAME}-16 PUBLIC ".")
target_include_directories(${PROJECT_NAME}-32 PUBLIC ".")

target_compile_definitions(${PROJECT_NAME}-16 PRIVATE -DPCRE2_STATIC -DHAVE_CONFIG_H)
target_compile_definitions(${PROJECT_NAME}-32 PRIVATE -DPCRE2_STATIC -DHAVE_CONFIG_H)

target_compile_definitions(${PROJECT_NAME}-16 PRIVATE -DPCRE2_CODE_UNIT_WIDTH=16)
target_compile_definitions(${PROJECT_NAME}-32 PRIVATE -DPCRE2_CODE_UNIT_WIDTH=32)

if(builtin_pcre2_with_jit)
    target_compile_definitions(${PROJECT_NAME}-16 PRIVATE -DSUPPORT_JIT)
    target_compile_definitions(${PROJECT_NAME}-32 PRIVATE -DSUPPORT_JIT)
endif()
