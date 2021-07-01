# Register exporters

def generate_registers_exporters():
    reg_exporters_inc = '#include "register_exporters.h"\n'
    reg_exporters = "void register_exporters() {\n"

    #TODO
    #for e in env.platform_exporters:
    #    env.add_source_files(env.editor_sources, "#platform/" + e + "/export/export.cpp")
    #    reg_exporters += "\tregister_" + e + "_exporter();\n"
    #    reg_exporters_inc += '#include "platform/' + e + '/export/export.h"\n'

    reg_exporters += "}\n"

    # NOTE: It is safe to generate this file here, since this is still executed serially
    with open("editor/register_exporters.gen.cpp", "w", encoding="utf-8") as f:
        f.write(reg_exporters_inc)
        f.write(reg_exporters)


if __name__ == "__main__":
    generate_registers_exporters()
