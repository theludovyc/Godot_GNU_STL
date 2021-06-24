generateFile(editor/builtin_fonts)

generateFile(editor/doc_data_compressed)

generateFile(editor/editor_icons)

file(GLOB_RECURSE src_editor editor/*.cpp)

list(APPEND SRC ${src_editor})
