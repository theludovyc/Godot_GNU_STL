import sys
import os

def generate_register_module_types(modules_names):
    includes_cpp = ""
    preregister_cpp = ""
    register_cpp = ""
    unregister_cpp = ""

    for i in range(1, len(modules_names)):
        name = modules_names[i]

        reg_path = "modules/" + name + "/register_types.h"

        if os.path.exists(reg_path):
            includes_cpp += '#include "' + reg_path + '"\n'
            preregister_cpp += "#ifdef MODULE_" + name.upper() + "_HAS_PREREGISTER\n"
            preregister_cpp += "\tpreregister_" + name + "_types();\n"
            preregister_cpp += "#endif\n"
            register_cpp += "\tregister_" + name + "_types();\n"
            unregister_cpp += "\tunregister_" + name + "_types();\n"

    modules_cpp = """// register_module_types.gen.cpp
/* THIS FILE IS GENERATED DO NOT EDIT */
#include "register_module_types.h"

#include "modules/modules_enabled.gen.h"

%s

void preregister_module_types() {
%s
}

void register_module_types() {
%s
}

void unregister_module_types() {
%s
}
""" % (
        includes_cpp,
        preregister_cpp,
        register_cpp,
        unregister_cpp,
    )

    # NOTE: It is safe to generate this file here, since this is still executed serially
    with open("modules/register_module_types.gen.cpp", "w") as f:
        f.write(modules_cpp)

if __name__ == "__main__":
    generate_register_module_types(sys.argv)
