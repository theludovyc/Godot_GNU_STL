def make_app_icon(target, source):
    src = source
    dst = target

    with open(src, "rb") as f:
        buf = f.read()

    with open(dst, "w") as g:
        g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
        g.write("#ifndef APP_ICON_H\n")
        g.write("#define APP_ICON_H\n")
        g.write("static const unsigned char app_icon_png[] = {\n")
        for i in range(len(buf)):
            g.write(str(buf[i]) + ",\n")
        g.write("};\n")
        g.write("#endif")

import sys

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("usage : " + sys.argv[0] + " <destination> <source>")
        exit()
    make_app_icon(sys.argv[1],sys.argv[2])