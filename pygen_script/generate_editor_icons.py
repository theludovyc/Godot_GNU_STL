import os
from io import StringIO
import glob

def generate_editor_icons():
    svg_icons = glob.glob("editor/icons/*.svg")
    #todo add modules icons

    icons_string = StringIO()

    for f in svg_icons:

        fname = str(f)

        icons_string.write('\t"')

        with open(fname, "rb") as svgf:
            b = svgf.read(1)
            while len(b) == 1:
                icons_string.write("\\" + str(hex(ord(b)))[1:])
                b = svgf.read(1)

        icons_string.write('"')
        if fname != svg_icons[-1]:
            icons_string.write(",")
        icons_string.write("\n")

    s = StringIO()
    s.write("/* THIS FILE IS GENERATED DO NOT EDIT */\n")
    s.write("#ifndef _EDITOR_ICONS_H\n")
    s.write("#define _EDITOR_ICONS_H\n")
    s.write("static const int editor_icons_count = {};\n".format(len(svg_icons)))
    s.write("static const char *editor_icons_sources[] = {\n")
    s.write(icons_string.getvalue())
    s.write("};\n\n")
    s.write("static const char *editor_icons_names[] = {\n")

    # this is used to store the indices of thumbnail icons
    thumb_medium_indices = []
    thumb_big_indices = []
    index = 0
    for f in svg_icons:

        fname = str(f)

        # Trim the `.svg` extension from the string.
        icon_name = os.path.basename(fname)[:-4]
        # some special cases
        if icon_name.endswith("MediumThumb"):  # don't know a better way to handle this
            thumb_medium_indices.append(str(index))
        if icon_name.endswith("BigThumb"):  # don't know a better way to handle this
            thumb_big_indices.append(str(index))

        s.write('\t"{0}"'.format(icon_name))

        if fname != svg_icons[-1]:
            s.write(",")
        s.write("\n")

        index += 1

    s.write("};\n")

    if thumb_medium_indices:
        s.write("\n\n")
        s.write("static const int editor_md_thumbs_count = {};\n".format(len(thumb_medium_indices)))
        s.write("static const int editor_md_thumbs_indices[] = {")
        s.write(", ".join(thumb_medium_indices))
        s.write("};\n")
    if thumb_big_indices:
        s.write("\n\n")
        s.write("static const int editor_bg_thumbs_count = {};\n".format(len(thumb_big_indices)))
        s.write("static const int editor_bg_thumbs_indices[] = {")
        s.write(", ".join(thumb_big_indices))
        s.write("};\n")

    s.write("#endif\n")

    with open("editor/editor_icons.gen.h", "w") as f:
        f.write(s.getvalue())

    s.close()
    icons_string.close()


if __name__ == "__main__":
    generate_editor_icons()
