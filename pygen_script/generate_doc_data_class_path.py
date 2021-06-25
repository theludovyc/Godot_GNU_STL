import os.path
import sys


def generate_doc_data_class_path(argv):
    # NOTE: It is safe to generate this file here, since this is still executed serially
    g = open("editor/doc_data_class_path.gen.h", "w", encoding="utf-8")

    g.write("static const int _doc_data_class_path_count = 0;\n")

    g.write("struct _DocDataClassPath { const char* name; const char* path; };\n")

    g.write("static const _DocDataClassPath _doc_data_class_paths[" + str(len(argv)) + "] = {\n")

    for i in range(1, len(argv)):
        split_path = os.path.split(argv[i])

        fileName = os.path.splitext(split_path[1])[0]

        g.write('\t{"' + fileName + '", "' + argv[i] + '"},\n')

    g.write("\t{nullptr, nullptr}\n")

    g.write("};\n")

    g.close()


if __name__ == "__main__":
    generate_doc_data_class_path(sys.argv)
