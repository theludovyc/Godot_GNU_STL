file(GLOB_RECURSE src_servers servers/*.cpp)

list(APPEND SRC ${src_servers})

file(GLOB shaders servers/rendering/renderer_rd/shaders/*.glsl)

list(FILTER shaders EXCLUDE REGEX [a-zA-Z]+_inc\\.glsl)

set(shaders_gen)

foreach(shader in shaders)
    list(APPEND shaders_gen ${shader}.gen.h)
endforeach()

add_custom_command(
        OUTPUT ${shaders_gen}
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_rd_headers.py ${shaders}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_rd_headers.py
)

list(APPEND SRC ${shaders_gen})
