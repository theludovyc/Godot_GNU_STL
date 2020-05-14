if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    add_definitions(-DDEBUG_ENABLED)
    add_definitions(-DDEBUG_MEMORY_ENABLED)
endif()

# TODO : test with gcc
add_definitions(-DTYPED_METHOD_BIND)

option(touch "Enable touch" OFF)
if(touch)
    add_definitions(-DTOUCH_ENABLED)
endif()

add_definitions(-DJOYDEV_ENABLED)

find_file(filemntent mntent.h)
if(filemntent)
    add_definitions(-DHAVE_MNTENT)
endif()

find_package(Udev)
if(Udev_FOUND)
    message("Enabling udev support")
    add_definitions(-DUDEV_ENABLED)
else()
    message("libudev development libraries not found, disabling udev support")
endif()

add_definitions(-DX11_ENABLED -DUNIX_ENABLED -DOPENGL_ENABLED -DGLES_ENABLED)
