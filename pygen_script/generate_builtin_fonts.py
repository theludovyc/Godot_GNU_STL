import os
import glob

def generate_builtin_fonts():
    source = glob.glob("thirdparty/fonts/*.ttf")

    g = open("editor/builtin_fonts.gen.h", "w", encoding="utf-8")

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef _EDITOR_FONTS_H\n")
    g.write("#define _EDITOR_FONTS_H\n")

    # Saving uncompressed, since FreeType will reference from memory pointer.
    for i in range(len(source)):
        with open(source[i], "rb") as f:
            buf = f.read()

        name = os.path.splitext(os.path.basename(source[i]))[0]

        g.write("static const int _font_" + name + "_size = " + str(len(buf)) + ";\n")
        g.write("static const unsigned char _font_" + name + "[] = {\n")
        for j in range(len(buf)):
            g.write("\t" + str(buf[j]) + ",\n")

        g.write("};\n")

    g.write("#endif")

    g.close()

if __name__ == "__main__":
    generate_builtin_fonts()
