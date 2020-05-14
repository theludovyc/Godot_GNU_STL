project(godotModules)

file(GLOB directories "*")

set(module_header)
set(module_register)
set(module_unregister)
set(module_name)
foreach(directorie ${directories})
    IF(IS_DIRECTORY ${directorie})
        get_filename_component(moduleName ${directorie} NAME)
        find_file(module_${moduleName}_CONFIG NAME "config.cmake" PATHS "${directorie}" NO_DEFAULT_PATH)
        find_file(module_${moduleName}_CMAKE NAME "CMakeLists.txt" PATHS "${directorie}" NO_DEFAULT_PATH)
        set(module_ENABLED OFF)
        if(module_${moduleName}_CONFIG AND module_${moduleName}_CMAKE)
            include(${module_${moduleName}_CONFIG})
        endif()
        if(module_ENABLED)
            option("module_${moduleName}" "enable ${moduleName}" ON)
            if(module_${moduleName})
                add_subdirectory(${directorie})
                find_file(module_${moduleName}_register_types NAME "register_types.h" PATHS "${directorie}" NO_DEFAULT_PATH)
                if(NOT module_${moduleName}_register_types)
                    message(FATAL_ERROR "${moduleName} have no register_types.h")
                endif()
                file(RELATIVE_PATH relative_path ${CMAKE_CURRENT_SOURCE_DIR} ${module_${moduleName}_register_types})
                string(APPEND module_header "#include \"${relative_path}\"\n")
                string(APPEND module_register "    register_${moduleName}_types();\n")
                string(APPEND module_unregister "    unregister_${moduleName}_types();\n")

                list(APPEND module_name "module_${moduleName}")

                unset(module_${moduleName}_register_types CACHE)
            endif()
        endif()
        unset(module_${moduleName}_CONFIG CACHE)
        unset(module_${moduleName}_CMAKE CACHE)
        unset(module_ENABLED CACHE)
    endif()
endforeach()


file(GENERATE OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/register_module_types.gen.cpp"
    CONTENT "// modules.cpp - THIS FILE IS GENERATED, DO NOT EDIT!!!!!!!
#include \"register_module_types.h\"

${module_header}

void register_module_types() {
${module_register}
}

void unregister_module_types() {
${module_unregister}
}"
)

add_library(${PROJECT_NAME} "register_module_types.h" "register_module_types.gen.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE ${module_name})

