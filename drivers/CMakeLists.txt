project(godotDriver)

if(${target} STREQUAL "x11")
    add_subdirectory(alsa)
    add_subdirectory(alsamidi)
    add_subdirectory(pulseaudio)
endif()

if(${target} STREQUAL "osx")
    add_subdirectory(coreaudio)
    add_subdirectory(coremidi)
endif()

if(${target} STREQUAL "iphone")
    add_subdirectory(coreaudio)
endif()

if(${target} STREQUAL "windows")
    add_subdirectory(wasapi)
    add_subdirectory(windows)
    add_subdirectory(winmidi)
    add_subdirectory(xaudio2)
endif()

if(${target} STREQUAL "server")
    add_subdirectory(dummy)
else()
    add_subdirectory(gles2)
    add_subdirectory(gles3)
endif()

add_subdirectory(png)

# TODO : add after define for platform
# add_subdirectory(unix)