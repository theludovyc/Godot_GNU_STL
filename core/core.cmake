add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/core/input/default_controller_mappings.gen.cpp
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_default_controller_mappings.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_default_controller_mappings.py
)

file(GLOB_RECURSE src_core core/*.cpp)

list(APPEND SRC ${src_core} core/input/default_controller_mappings.gen.cpp)
