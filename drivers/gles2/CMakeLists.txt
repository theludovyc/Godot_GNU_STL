project(godotGles2)

set(gen)

compilegles2("shaders/copy" gen)
# compilegles2("shaders/resolve" gen)
compilegles2("shaders/canvas" gen)
compilegles2("shaders/canvas_shadow" gen)
compilegles2("shaders/scene" gen)
compilegles2("shaders/cubemap_filter" gen)
compilegles2("shaders/cube_to_dp" gen)
# compilegles2("shaders/blend_shape" gen)
# compilegles2("shaders/screen_space_reflection" gen)
compilegles2("shaders/effect_blur" gen)
# compilegles2("shaders/subsurf_scattering" gen)
# compilegles2("shaders/ssao" gen)
# compilegles2("shaders/ssao_minify" gen)
# compilegles2("shaders/ssao_blur" gen)
# compilegles2("shaders/exposure" gen)
compilegles2("shaders/tonemap" gen)
# compilegles2("shaders/particles" gen)
compilegles2("shaders/lens_distorted" gen)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp} ${gen})

target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)