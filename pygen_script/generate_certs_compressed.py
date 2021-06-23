def generate_certs_compressed(system_certs_path, builtin_certs):
    src = "thirdparty/certs/ca-certificates.crt"
    dst = "core/io/certs_compressed.gen.h"
    f = open(src, "rb")
    g = open(dst, "w", encoding="utf-8")
    buf = f.read()
    decomp_size = len(buf)
    import zlib

    buf = zlib.compress(buf)

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef CERTS_COMPRESSED_GEN_H\n")
    g.write("#define CERTS_COMPRESSED_GEN_H\n")

    # System certs path. Editor will use them if defined. (for package maintainers)
    path = system_certs_path
    g.write('#define _SYSTEM_CERTS_PATH "%s"\n' % str(path))
    if builtin_certs:
        # Defined here and not in env so changing it does not trigger a full rebuild.
        g.write("#define BUILTIN_CERTS_ENABLED\n")
        g.write("static const int _certs_compressed_size = " + str(len(buf)) + ";\n")
        g.write("static const int _certs_uncompressed_size = " + str(decomp_size) + ";\n")
        g.write("static const unsigned char _certs_compressed[] = {\n")
        for i in range(len(buf)):
            g.write("\t" + str(buf[i]) + ",\n")
        g.write("};\n")
    g.write("#endif // CERTS_COMPRESSED_GEN_H")

    g.close()
    f.close()

if __name__ == "__main__":
    generate_certs_compressed("", "ON")
