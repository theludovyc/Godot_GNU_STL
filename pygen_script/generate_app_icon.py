def generate_app_icon():
    with open("main/app_icon.png", "rb") as f:
        buf = f.read()

    with open("main/app_icon.gen.h", "w") as g:
        g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
        g.write("#ifndef APP_ICON_H\n")
        g.write("#define APP_ICON_H\n")
        g.write("static const unsigned char app_icon_png[] = {\n")
        for i in range(len(buf)):
            g.write(str(buf[i]) + ",\n")
        g.write("};\n")
        g.write("#endif")

if __name__ == "__main__":
    generate_app_icon()
