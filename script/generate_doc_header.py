def make_doc_header(target, source):

    dst = target
    g = open(dst, "w")
    buf = ""
    docbegin = ""
    docend = ""
    for src in source:
        if not src.endswith(".xml"):
            continue
        with open(src, "r") as f:
            content = f.read()
        buf += content

    buf = (docbegin + buf + docend).encode("utf-8")
    decomp_size = len(buf)
    import zlib
    buf = zlib.compress(buf)

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef _DOC_DATA_RAW_H\n")
    g.write("#define _DOC_DATA_RAW_H\n")
    g.write("static const int _doc_data_compressed_size = " + str(len(buf)) + ";\n")
    g.write("static const int _doc_data_uncompressed_size = " + str(decomp_size) + ";\n")
    g.write("static const unsigned char _doc_data_compressed[] = {\n")
    for i in range(len(buf)):
        g.write("\t" + str(buf[i]) + ",\n")
    g.write("};\n")

    g.write("#endif")

    g.close()

import sys
import json

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("usage : " + sys.argv[0] + " <destination> <source>")
        exit()
    jsonstring = "[\"" + sys.argv[2].replace(";","\",\"") + "\"]"
    make_doc_header(sys.argv[1],json.loads(jsonstring))