project(godotDriver)

file(GLOB header "*.h")
file(GLOB cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../")
target_include_directories(${PROJECT_NAME} PRIVATE "../platform/${target}")

if(${target} STREQUAL "x11")
    find_package(ALSA)
    if(ALSA_FOUND)
        message("Enabling ALSA")
        add_subdirectory(alsa)
        add_subdirectory(alsamidi)
        target_link_libraries(${PROJECT_NAME} INTERFACE godotAlsa godotAlsaMidi)
    else()
        message("ALSA libraries not found, disabling driver")
    endif()

    find_package(PulseAudio)
    if(PulseAudio_FOUND)
        message("Enabling PulseAudio")
        add_subdirectory(pulseaudio)
        target_link_libraries(${PROJECT_NAME} INTERFACE godotPulseAudio)
    else()
        message("PulseAudio development libraries not found, disabling driver")
    endif()
    
endif()

if(${target} STREQUAL "osx")
    add_subdirectory(coreaudio)
    add_subdirectory(coremidi)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotCoreAudio godotCoreMidi)
endif()

if(${target} STREQUAL "iphone")
    add_subdirectory(coreaudio)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotCoreAudio)
endif()

if(${target} STREQUAL "windows")
    add_subdirectory(wasapi)
    add_subdirectory(windows)
    add_subdirectory(winmidi)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotWasapi godotWindows godotWinmidi)
endif()

if(${target} STREQUAL "uwp")
    add_subdirectory(xaudio2)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotXaudio)
endif()


if(${target} STREQUAL "server")
    add_subdirectory(dummy)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotDummy)
else()
    add_subdirectory(gles2)
    add_subdirectory(gles3)
    target_link_libraries(${PROJECT_NAME} INTERFACE godotGles2 godotGles3)    
endif()

add_subdirectory(unix)
target_link_libraries(${PROJECT_NAME} INTERFACE godotUnix)  

add_subdirectory(png)
target_link_libraries(${PROJECT_NAME} PUBLIC godotPng)