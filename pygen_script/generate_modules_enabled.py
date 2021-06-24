import sys

def generate_modules_enabled(sources):
    with open("modules/modules_enabled.gen.h", "w") as f:
        for i in range(1, len(sources)):
            f.write("#define %s\n" % ("MODULE_" + sources[i].upper() + "_ENABLED"))

if __name__ == "__main__":
    generate_modules_enabled(sys.argv)
