generateFile(editor/builtin_fonts)

file(GLOB_RECURSE src_editor editor/*.cpp)

list(APPEND SRC ${src_editor})
