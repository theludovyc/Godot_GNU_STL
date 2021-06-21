add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/core/input/default_controller_mappings.gen.cpp
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_default_controller_mappings.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_default_controller_mappings.py
)

file(GLOB src_core *.cpp)

file(GLOB_RECURSE
        src_core1
        core/config/*.cpp
        core/debugger/*.cpp
        core/error/*.cpp
        core/input/*.cpp
        core/io/*.cpp
        core/math/*.cpp
        core/object/*.cpp
        core/os/*.cpp
        core/string/*.cpp
        core/templates/*cpp
        core/variant/*.cpp
        )

list(APPEND SRC ${src_core} ${src_core1} core/input/default_controller_mappings.gen.cpp)
