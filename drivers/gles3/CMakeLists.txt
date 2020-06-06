project(godotGles3)

set(gen)

compilegles3("shaders/copy" gen)
compilegles3("shaders/resolve" gen)
compilegles3("shaders/canvas" gen)
compilegles3("shaders/canvas_shadow" gen)
compilegles3("shaders/scene" gen)
compilegles3("shaders/cubemap_filter" gen)
compilegles3("shaders/cube_to_dp" gen)
compilegles3("shaders/blend_shape" gen)
compilegles3("shaders/screen_space_reflection" gen)
compilegles3("shaders/effect_blur" gen)
compilegles3("shaders/subsurf_scattering" gen)
compilegles3("shaders/ssao" gen)
compilegles3("shaders/ssao_minify" gen)
compilegles3("shaders/ssao_blur" gen)
compilegles3("shaders/exposure" gen)
compilegles3("shaders/tonemap" gen)
compilegles3("shaders/particles" gen)
compilegles3("shaders/lens_distorted" gen)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp} ${gen})

target_link_libraries(${PROJECT_NAME} PRIVATE glad)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)