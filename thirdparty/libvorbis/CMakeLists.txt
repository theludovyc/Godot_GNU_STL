project(libvorbis)

set(header )
set(c 
        #"analysis.c"
        #"barkmel.c"
        "bitrate.c"
        "block.c"
        "codebook.c"
        "envelope.c"
        "floor0.c"
        "floor1.c"
        "info.c"
        "lookup.c"
        "lpc.c"
        "lsp.c"
        "mapping0.c"
        "mdct.c"
        "psy.c"
        #"psytune.c"
        "registry.c"
        "res0.c"
        "sharedbook.c"
        "smallft.c"
        "synthesis.c"
        #"tone.c"
        #"vorbisenc.c"
        "vorbisfile.c"
        "window.c"
)

add_library(${PROJECT_NAME} ${header} ${c})

target_link_libraries(${PROJECT_NAME} PRIVATE libogg)

target_include_directories(${PROJECT_NAME} PUBLIC ".")