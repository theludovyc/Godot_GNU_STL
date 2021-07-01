generateHeader(editor/builtin_fonts)

generateHeader(editor/doc_data_compressed)

generateHeader(editor/editor_icons)

generateHeader(editor/doc_translations)

generateHeader(editor/editor_translations)

generateSource(editor/register_exporters)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/editor/doc_data_class_path.gen.h
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_doc_data_class_path.py ${MODULES_DOC_CLASSES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_doc_data_class_path.py
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/editor/doc_data_class_path.gen.h)

file(GLOB_RECURSE src_editor editor/*.cpp)

list(APPEND SRC ${src_editor})
