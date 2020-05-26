if(${tools})
    set(exe_name "${PROJECT_NAME}-linux-editor.${CMAKE_BUILD_TYPE}")
else()
    set(exe_name "${PROJECT_NAME}-linux-template.${CMAKE_BUILD_TYPE}")
endif()



file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_executable(${exe_name} ${header} ${cpp})

# TODO : remove
target_include_directories(${exe_name} PRIVATE "../../")
target_include_directories(${exe_name} PRIVATE ".")

if(NOT tools)
    target_link_options(${exe_name} PRIVATE "-T${CMAKE_CURRENT_SOURCE_DIR}/pck_embed.ld")
endif()

# for dl library
target_link_libraries(${exe_name} PRIVATE ${CMAKE_DL_LIBS})

# glx lib 
find_package(OpenGL REQUIRED)
target_link_libraries(${exe_name} PRIVATE OpenGL::GLX)


# x11 lib
find_package(X11 REQUIRED)
target_link_libraries(${exe_name} PRIVATE ${X11_X11_LIB})
target_link_libraries(${exe_name} PRIVATE ${X11_Xrender_LIB})
target_link_libraries(${exe_name} PRIVATE ${X11_Xrandr_LIB})
target_link_libraries(${exe_name} PRIVATE ${X11_Xinput_LIB})
target_link_libraries(${exe_name} PRIVATE ${X11_Xcursor_LIB})
target_link_libraries(${exe_name} PRIVATE ${X11_Xinerama_LIB})

# Udev
if(Udev_FOUND)
    target_link_libraries(${exe_name} PRIVATE ${UDEV_LIBRARIES})
endif()

# godotMain
target_link_libraries(${exe_name} PRIVATE godotMain)

# godotDriver
target_link_libraries(${exe_name} PRIVATE godotDriver)

# godotServers
target_link_libraries(${exe_name} PRIVATE godotServers)

# godotScene
target_link_libraries(${exe_name} PRIVATE godotScene)

# godotModules
target_link_libraries(${exe_name} PRIVATE godotModules)

if(tools)
    # godotEditor
    target_link_libraries(${exe_name} PRIVATE godotEditor)
endif()