def generate_splash_editor():
    with open("main/splash_editor.png", "rb") as f:
        buf = f.read()

    with open("main/splash_editor.gen.h", "w") as g:
        g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
        g.write("#ifndef BOOT_SPLASH_EDITOR_H\n")
        g.write("#define BOOT_SPLASH_EDITOR_H\n")
        # The editor splash background color is taken from the default editor theme's background color.
        # This helps achieve a visually "smoother" transition between the splash screen and the editor.
        g.write("static const Color boot_splash_editor_bg_color = Color(0.125, 0.145, 0.192);\n")
        g.write("static const unsigned char boot_splash_editor_png[] = {\n")
        for i in range(len(buf)):
            g.write(str(buf[i]) + ",\n")
        g.write("};\n")
        g.write("#endif")

if __name__ == "__main__":
    generate_splash_editor()
