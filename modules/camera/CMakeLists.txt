project(module_camera)

if(${target} STREQUAL "iphone")
    set(header "camera_ios.h")
    set(source "camera_ios.mm")    
endif()

if(${target} STREQUAL "windows")
    set(header "camera_win.h")
    set(source "camera_win.cpp")    
endif()

if(${target} STREQUAL "osx")
    set(header "camera_osx.h")
    set(source "camera_osx.mm")    
endif()

add_library(${PROJECT_NAME} "register_types.cpp" "register_types.h" ${source} ${header})

target_link_libraries(${PROJECT_NAME} PRIVATE godotServers)