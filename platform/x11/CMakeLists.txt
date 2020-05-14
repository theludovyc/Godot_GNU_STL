
set(gen)

file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_executable(${PROJECT_NAME} ${header} ${cpp} ${gen})

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE ".")

if(NOT tools)
    target_link_options(${PROJECT_NAME} PRIVATE "-T${CMAKE_CURRENT_SOURCE_DIR}/pck_embed.ld")
endif()

# for dl library
target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_DL_LIBS})

# glx lib 
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GLX)


# x11 lib
find_package(X11 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_X11_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_Xrender_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_Xrandr_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_Xinput_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_Xcursor_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_Xinerama_LIB})

# Udev
if(Udev_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${UDEV_LIBRARIES})
endif()

# godotMain
target_link_libraries(${PROJECT_NAME} PRIVATE godotMain)

# godotDriver
target_link_libraries(${PROJECT_NAME} PRIVATE godotDriver)

# godotServers
target_link_libraries(${PROJECT_NAME} PRIVATE godotServers)

# godotScene
target_link_libraries(${PROJECT_NAME} PRIVATE godotScene)

# godotModules
target_link_libraries(${PROJECT_NAME} PRIVATE godotModules)

if(NOT tools)
    # godotEditor
    target_link_libraries(${PROJECT_NAME} PRIVATE godotEditor)
endif()