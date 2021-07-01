add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/scene/resources/default_theme/default_font.gen.h
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_default_font.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_default_font.py thirdparty/fonts/OpenSans_SemiBold.ttf
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/scene/resources/default_theme/default_font.gen.h
        thirdparty/misc/mikktspace.c)

file(GLOB_RECURSE src_scene scene/*.cpp)
list(APPEND SRC ${src_scene} "thirdparty/misc/easing_equations.cpp")
