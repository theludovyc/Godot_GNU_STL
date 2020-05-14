project(godotEditor)

set(generateFile)

set(export_header)
set(export_register)
set(export_unregister)
file(GLOB directories "./platform/*")
foreach(directorie ${directories})
    IF(IS_DIRECTORY ${directorie})
        get_filename_component(os ${directorie} NAME)
        generateIcon(${os} ${directorie} generateFile)

        file(RELATIVE_PATH relative_path ${CMAKE_CURRENT_SOURCE_DIR} "${directorie}/export.h")

        string(APPEND export_header "#include \"${relative_path}\"\n")
        string(APPEND export_register "    register_${os}_exporter();\n")
    endif()
endforeach()

file(GENERATE OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/register_exporters.gen.cpp"
    CONTENT "// modules.cpp - THIS FILE IS GENERATED, DO NOT EDIT!!!!!!!
#include \"register_exporters.h\"

${export_header}

void register_exporters() {
${export_register}
}"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/register_exporters.gen.cpp")


set(languages)
file(GLOB_RECURSE languages "./translations/*.po")
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/translations.gen.h"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_translation_header.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/translations.gen.h"
    "\"${languages}\""
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/translations.gen.h")

set(documentation)
file(GLOB_RECURSE documentation "${CMAKE_SOURCE_DIR}/doc/classes/*.xml")
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/doc_data_compressed.gen.h"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_doc_header.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/doc_data_compressed.gen.h"
    "\"${documentation}\""
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/doc_data_compressed.gen.h")

set(icons)
file(GLOB_RECURSE icons "./icons/*.svg")
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/editor_icons.gen.h"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_editor_icone.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/editor_icons.gen.h"
    "\"${icons}\""
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/editor_icons.gen.h")

set(font)
file(GLOB_RECURSE font_ttf "${CMAKE_SOURCE_DIR}/thirdparty/fonts/*.ttf")
file(GLOB_RECURSE font_odf "${CMAKE_SOURCE_DIR}/thirdparty/fonts/*.odf")
list(APPEND font ${font_ttf} ${font_odf})
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/builtin_fonts.gen.h"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_font_header.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/builtin_fonts.gen.h"
    "\"${font}\""
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/builtin_fonts.gen.h")


file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")


add_library(${PROJECT_NAME} ${header} ${cpp} ${generateFile})

# TODO: suppress
target_include_directories(${PROJECT_NAME} PRIVATE "../")
target_include_directories(${PROJECT_NAME} PRIVATE "../platform/${target}")
target_compile_options(${PROJECT_NAME} PRIVATE -DFREETYPE_ENABLED)

target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
target_link_libraries(${PROJECT_NAME} PRIVATE nanosvg)

# godotCore
target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

# godotModules
target_link_libraries(${PROJECT_NAME} PRIVATE godotModules)

# godotScene
target_link_libraries(${PROJECT_NAME} PRIVATE godotScene)

# TODO : need to be change
target_link_libraries(${PROJECT_NAME} PRIVATE module_svg module_gdscript)
