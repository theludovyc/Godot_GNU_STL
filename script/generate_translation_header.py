def make_translations_header(target, source):

    dst = target

    g = open(dst, "w")

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef _EDITOR_TRANSLATIONS_H\n")
    g.write("#define _EDITOR_TRANSLATIONS_H\n")

    import zlib
    import os.path

    sorted_paths = sorted(source, key=lambda path: os.path.splitext(os.path.basename(path))[0])

    xl_names = []
    for i in range(len(sorted_paths)):
        with open(sorted_paths[i], "rb") as f:
            buf = f.read()
        decomp_size = len(buf)
        buf = zlib.compress(buf)
        name = os.path.splitext(os.path.basename(sorted_paths[i]))[0]

        g.write("static const unsigned char _translation_" + name + "_compressed[] = {\n")
        for j in range(len(buf)):
            g.write("\t" + str(buf[j]) + ",\n")

        g.write("};\n")

        xl_names.append([name, len(buf), str(decomp_size)])

    g.write("struct EditorTranslationList {\n")
    g.write("\tconst char* lang;\n")
    g.write("\tint comp_size;\n")
    g.write("\tint uncomp_size;\n")
    g.write("\tconst unsigned char* data;\n")
    g.write("};\n\n")
    g.write("static EditorTranslationList _editor_translations[] = {\n")
    for x in xl_names:
        g.write("\t{ \"" + x[0] + "\", " + str(x[1]) + ", " + str(x[2]) + ", _translation_" + x[0] + "_compressed},\n")
    g.write("\t{NULL, 0, 0, NULL}\n")
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
    make_translations_header(sys.argv[1],json.loads(jsonstring))