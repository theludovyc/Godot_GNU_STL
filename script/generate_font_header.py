import os
def make_fonts_header(target, source):

    dst = target

    g = open(dst, "w")

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef _EDITOR_FONTS_H\n")
    g.write("#define _EDITOR_FONTS_H\n")

    # saving uncompressed, since freetype will reference from memory pointer
    xl_names = []
    for i in range(len(source)):
        with open(source[i], "rb")as f:
            buf = f.read()

        name = os.path.splitext(os.path.basename(source[i]))[0]

        g.write("static const int _font_" + name + "_size = " + str(len(buf)) + ";\n")
        g.write("static const unsigned char _font_" + name + "[] = {\n")
        for j in range(len(buf)):
            g.write("\t" + str(buf[j]) + ",\n")

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
    make_fonts_header(sys.argv[1],json.loads(jsonstring))