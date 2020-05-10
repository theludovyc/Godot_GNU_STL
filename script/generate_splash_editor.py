def make_splash_editor(target, source):
    src = source
    dst = target

    with open(src, "rb") as f:
        buf = f.read()

    with open(dst, "w") as g:
        g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
        g.write("#ifndef BOOT_SPLASH_EDITOR_H\n")
        g.write("#define BOOT_SPLASH_EDITOR_H\n")
        g.write('static const Color boot_splash_editor_bg_color = Color(0.14, 0.14, 0.14);\n')
        g.write("static const unsigned char boot_splash_editor_png[] = {\n")
        for i in range(len(buf)):
            g.write(str(buf[i]) + ",\n")
        g.write("};\n")
        g.write("#endif")

import sys

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("usage : " + sys.argv[0] + " <destination> <source>")
        exit()
    make_splash_editor(sys.argv[1],sys.argv[2])
