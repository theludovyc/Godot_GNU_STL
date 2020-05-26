if(${tools})
    set(exe_name "${PROJECT_NAME}-windows-editor.${CMAKE_BUILD_TYPE}")
else()
    set(exe_name "${PROJECT_NAME}-windows-template.${CMAKE_BUILD_TYPE}")
endif()

file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_executable(${exe_name} ${header} ${cpp})

# TODO : remove
target_include_directories(${exe_name} PUBLIC "../../")
target_include_directories(${exe_name} PUBLIC ".")


# TODO : temporary
target_link_libraries(${exe_name} PUBLIC glad)


# glx lib 
find_package(OpenGL REQUIRED)
target_link_libraries(${exe_name} PUBLIC OpenGL::GL)

# windows specifics
target_link_libraries(${exe_name} PUBLIC dinput8 dxguid imm32 avrt dwmapi)

# godotMain
target_link_libraries(${exe_name} PUBLIC godotMain)

# godotDriver
target_link_libraries(${exe_name} PUBLIC godotDriver)

# godotServers
target_link_libraries(${exe_name} PUBLIC godotServers)

# godotScene
target_link_libraries(${exe_name} PUBLIC godotScene)

# godotModules
target_link_libraries(${exe_name} PUBLIC godotModules)

if(NOT tools)
    # godotEditor
    target_link_libraries(${exe_name} PUBLIC godotEditor)
endif()