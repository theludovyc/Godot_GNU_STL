project(libtheora)

set(header)

set(c
        #"analyze.c"
        #"apiwrapper.c"
        "bitpack.c"
        "cpu.c"
        #"decapiwrapper.c"
        "decinfo.c"
        "decode.c"
        "dequant.c"
        #"encapiwrapper.c"
        #"encfrag.c"
        #"encinfo.c"
        #"encode.c"
        #"encoder_disabled.c"
        #"enquant.c"
        #"fdct.c"
        "fragment.c"
        "huffdec.c"
        #"huffenc.c"
        "idct.c"
        "info.c"
        "internal.c"
        #"mathops.c"
        #"mcenc.c"
        "quant.c"
        #"rate.c"
        "state.c"
        #"tokenize.c"
)

add_library(${PROJECT_NAME} ${header} ${c})

#target_compile_definitions(${PROJECT_NAME} PRIVATE -DOC_X86_ASM)

target_link_libraries(${PROJECT_NAME} PRIVATE libogg)

target_include_directories(${PROJECT_NAME} PUBLIC ".")
