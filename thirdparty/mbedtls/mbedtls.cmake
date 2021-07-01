# Use our headers for builtin or if the module is not going to be compiled.
# We decided not to depend on system mbedtls just for these few files that can
# be easily extracted.

# MbedTLS core functions (for CryptoCore).
# If the mbedtls module is compiled we don't need to add the .c files with our
# custom config since they will be built by the module itself.
# Only if the module is not enabled, we must compile here the required sources
# to make a "light" build with only the necessary mbedtls files.

# Custom config file
add_compile_definitions(MBEDTLS_CONFIG_FILE="thirdparty/mbedtls/include/godot_core_mbedtls_config.h")

set(src_thirdparty_mbedtls
        thirdparty/mbedtls/library/aes.c
        thirdparty/mbedtls/library/base64.c
        thirdparty/mbedtls/library/md5.c
        thirdparty/mbedtls/library/sha1.c
        thirdparty/mbedtls/library/sha256.c
        thirdparty/mbedtls/library/godot_core_mbedtls_platform.c
        )

list(APPEND INCLUDE_DIR thirdparty/mbedtls/include)

list(APPEND SRC ${src_thirdparty_mbedtls})
