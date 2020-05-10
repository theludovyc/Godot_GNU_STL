from gles_common import build_legacygl_header

import sys

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("usage : " + sys.argv[0] + " <source>")
        exit()

    build_legacygl_header(sys.argv[1], include="drivers/gles3/shader_gles3.h", class_suffix="GLES3", output_attribs=True)