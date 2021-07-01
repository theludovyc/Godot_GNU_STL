def generate_splash():
    with open("main/splash.png", "rb") as f:
        buf = f.read()

    with open("main/splash.gen.h", "w") as g:
        g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
        g.write("#ifndef BOOT_SPLASH_H\n")
        g.write("#define BOOT_SPLASH_H\n")
        # Use a neutral gray color to better fit various kinds of projects.
        g.write("static const Color boot_splash_bg_color = Color(0.14, 0.14, 0.14);\n")
        g.write("static const unsigned char boot_splash_png[] = {\n")
        for i in range(len(buf)):
            g.write(str(buf[i]) + ",\n")
        g.write("};\n")
        g.write("#endif")

if __name__ == "__main__":
    generate_splash()
