from utils import escape_string

def make_authors_header(target, source):
    sections = ["Project Founders", "Lead Developer", "Project Manager", "Developers"]
    sections_id = ["AUTHORS_FOUNDERS", "AUTHORS_LEAD_DEVELOPERS", "AUTHORS_PROJECT_MANAGERS", "AUTHORS_DEVELOPERS"]

    src = source
    dst = target
    f = open(src, "r")
    g = open(dst, "w")

    g.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    g.write("#ifndef _EDITOR_AUTHORS_H\n")
    g.write("#define _EDITOR_AUTHORS_H\n")

    reading = False

    def close_section():
        g.write("\t0\n")
        g.write("};\n")

    for line in f:
        if reading:
            if line.startswith("    "):
                g.write("\t\"" + escape_string(line.strip()) + "\",\n")
                continue
        if line.startswith("## "):
            if reading:
                close_section()
                reading = False
            for section, section_id in zip(sections, sections_id):
                if line.strip().endswith(section):
                    current_section = escape_string(section_id)
                    reading = True
                    g.write("const char *const " + current_section + "[] = {\n")
                    break

    if reading:
        close_section()

    g.write("#endif\n")

    g.close()
    f.close()

import sys

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("usage : " + sys.argv[0] + " <destination> <source>")
        exit()
    make_authors_header(sys.argv[1],sys.argv[2])
