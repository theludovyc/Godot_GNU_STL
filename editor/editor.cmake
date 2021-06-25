generateFile(editor/builtin_fonts)

generateFile(editor/doc_data_compressed)

generateFile(editor/editor_icons)

generateFile(editor/doc_translations)

generateFile(editor/editor_translations)

file(GLOB_RECURSE src_editor editor/*.cpp)

list(APPEND SRC ${src_editor})
