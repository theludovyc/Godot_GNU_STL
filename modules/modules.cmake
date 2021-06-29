file(GLOB modules_cmakes modules/*/*.cmake)

#populate by include
set(MODULES_NAMES)

foreach(modules_cmake ${modules_cmakes})
    include(${modules_cmake})
endforeach()

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/modules/modules_enabled.gen.h
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_modules_enabled.py ${MODULES_NAMES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_modules_enabled.py
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/modules/modules_enabled.gen.h)

add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/modules/register_module_types.gen.cpp
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_register_module_types.py ${MODULES_NAMES}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_register_module_types.py
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/modules/register_module_types.gen.cpp)
