macro(add_element dir header cpp)

file(GLOB_RECURSE tmp_header "${dir}/*.h")
file(GLOB_RECURSE tmp_cpp "${dir}/*.cpp")
list(APPEND header ${tmp_header})
list(APPEND cpp ${tmp_cpp})

endmacro()


project(module_gdscript)


# TODO : need to be test
if(module_jsonrpc AND module_websocket)
    option(gdscript_lsp "enable lsp language server for gdscript" ON)
endif()



file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_element(editor header cpp)
if(gdscript_lsp)
    add_element(language_server header cpp)
endif()

add_library(${PROJECT_NAME} ${header} ${cpp})


target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

if(NOT gdscript_lsp)
    target_compile_options(${PROJECT_NAME} PRIVATE -DGDSCRIPT_NO_LSP)
endif()
