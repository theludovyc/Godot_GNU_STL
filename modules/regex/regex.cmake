set(src_thirdparty_pcre2
        thirdparty/pcre2/src/pcre2_auto_possess.c
        thirdparty/pcre2/src/pcre2_chartables.c
        thirdparty/pcre2/src/pcre2_compile.c
        thirdparty/pcre2/src/pcre2_config.c
        thirdparty/pcre2/src/pcre2_context.c
        thirdparty/pcre2/src/pcre2_convert.c
        thirdparty/pcre2/src/pcre2_dfa_match.c
        thirdparty/pcre2/src/pcre2_error.c
        thirdparty/pcre2/src/pcre2_extuni.c
        thirdparty/pcre2/src/pcre2_find_bracket.c
        thirdparty/pcre2/src/pcre2_jit_compile.c
        thirdparty/pcre2/src/pcre2_maketables.c
        thirdparty/pcre2/src/pcre2_match.c
        thirdparty/pcre2/src/pcre2_match_data.c
        thirdparty/pcre2/src/pcre2_newline.c
        thirdparty/pcre2/src/pcre2_ord2utf.c
        thirdparty/pcre2/src/pcre2_pattern_info.c
        thirdparty/pcre2/src/pcre2_script_run.c
        thirdparty/pcre2/src/pcre2_serialize.c
        thirdparty/pcre2/src/pcre2_string_utils.c
        thirdparty/pcre2/src/pcre2_study.c
        thirdparty/pcre2/src/pcre2_substitute.c
        thirdparty/pcre2/src/pcre2_substring.c
        thirdparty/pcre2/src/pcre2_tables.c
        thirdparty/pcre2/src/pcre2_ucd.c
        thirdparty/pcre2/src/pcre2_valid_utf.c
        thirdparty/pcre2/src/pcre2_xclass.c
        )

add_compile_definitions(PCRE2_STATIC
        HAVE_CONFIG_H
        SUPPORT_UNICODE
        SUPPORT_JIT
        PCRE2_CODE_UNIT_WIDTH=32)

file(GLOB doc_regex modules/regex/doc_classes/*.xml)

list(APPEND MODULES_DOC_CLASSES ${doc_regex})

file(GLOB src_regex modules/regex/*.cpp)

list(APPEND INCLUDE_DIR thirdparty/pcre2/src)

list(APPEND SRC ${src_thirdparty_pcre2} ${src_regex})

list(APPEND MODULES_NAMES regex)
