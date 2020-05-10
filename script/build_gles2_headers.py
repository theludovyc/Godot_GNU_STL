from gles_common import build_legacygl_header

import sys

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("usage : " + sys.argv[0] + " <source>")
        exit()

    build_legacygl_header(str(sys.argv[1]), include="drivers/gles2/shader_gles2.h", class_suffix="GLES2", output_attribs=True, gles2=True)
