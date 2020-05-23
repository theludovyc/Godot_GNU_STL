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

        #"x86/mmxencfrag.c"
        #"x86/mmxfdct.c"
        "x86/mmxfrag.c"
        "x86/mmxidct.c"
        "x86/mmxstate.c"
        #"x86/sse2fdct.c"
        #"x86/x86enc.c"
        "x86/x86state.c"
)

add_library(${PROJECT_NAME} ${header} ${c})

target_include_directories(${PROJECT_NAME} PUBLIC ".")