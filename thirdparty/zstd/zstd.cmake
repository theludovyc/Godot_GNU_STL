# Zstd library, can be unbundled in theory
# though we currently use some private symbols
# https://github.com/godotengine/godot/issues/17374

set(src_thirdparty_zstd
        thirdparty/zstd/common/debug.c
        thirdparty/zstd/common/entropy_common.c
        thirdparty/zstd/common/error_private.c
        thirdparty/zstd/common/fse_decompress.c
        thirdparty/zstd/common/pool.c
        thirdparty/zstd/common/threading.c
        thirdparty/zstd/common/xxhash.c
        thirdparty/zstd/common/zstd_common.c
        thirdparty/zstd/compress/fse_compress.c
        thirdparty/zstd/compress/hist.c
        thirdparty/zstd/compress/huf_compress.c
        thirdparty/zstd/compress/zstd_compress.c
        thirdparty/zstd/compress/zstd_double_fast.c
        thirdparty/zstd/compress/zstd_fast.c
        thirdparty/zstd/compress/zstd_lazy.c
        thirdparty/zstd/compress/zstd_ldm.c
        thirdparty/zstd/compress/zstd_opt.c
        thirdparty/zstd/compress/zstdmt_compress.c
        thirdparty/zstd/compress/zstd_compress_literals.c
        thirdparty/zstd/compress/zstd_compress_sequences.c
        thirdparty/zstd/compress/zstd_compress_superblock.c
        thirdparty/zstd/decompress/huf_decompress.c
        thirdparty/zstd/decompress/zstd_ddict.c
        thirdparty/zstd/decompress/zstd_decompress_block.c
        thirdparty/zstd/decompress/zstd_decompress.c
        )

add_compile_definitions(ZSTD_STATIC_LINKING_ONLY)

list(APPEND SRC ${src_thirdparty_zstd})
