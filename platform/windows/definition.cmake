if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo" OR ${tools})
    add_definitions(-DDEBUG_ENABLED)
    add_definitions(-DDEBUG_MEMORY_ENABLED)
    add_definitions(-DD3D_DEBUG_INFO)
endif()


add_definitions(-DWINDOWS_ENABLED -DOPENGL_ENABLED -DWASAPI_ENABLED -DWINMIDI_ENABLED)

add_definitions(-DWINVER=0x0601 -D_WIN32_WINNT=0x0601)

add_definitions(-DMINGW_ENABLED)
add_definitions(-DMINGW_HAS_SECURE_API=1)