project(module_webrtc)


file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

if(module_gdnative)
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DWEBRTC_GDNATIVE_ENABLED)
endif()


target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)