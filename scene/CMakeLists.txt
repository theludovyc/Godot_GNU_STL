macro(add_element dir header cpp)

file(GLOB_RECURSE tmp_header "${dir}/*.h")
file(GLOB_RECURSE tmp_cpp "${dir}/*.cpp")
list(APPEND header ${tmp_header})
list(APPEND cpp ${tmp_cpp})

endmacro()

project(godotScene)

option(disable_3d "Disable 3D nodes for a smaller executable" OFF)

set(header)
set(cpp)

add_element(2d header cpp)

if(NOT disable_3d)
    add_element(3d header cpp)
else()
    list(APPEND header "spatial.h" "skeleton.h" "particles.h" "visual_instance.h" "world_environment.h")
    list(APPEND cpp "spatial.cpp" "skeleton.cpp" "particles.cpp" "visual_instance.cpp" "world_environment.cpp")
endif()

add_element(animation header cpp)
add_element(audio header cpp)
add_element(debugger header cpp)
add_element(gui header cpp)
add_element(main header cpp)
add_element(resources header cpp)

file(GLOB tmp_header "*.h")
file(GLOB tmp_cpp "*.cpp")
list(APPEND header ${tmp_header})
list(APPEND cpp ${tmp_cpp})

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE misc)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)

# TODO : need to change
target_link_libraries(${PROJECT_NAME} PUBLIC godotCore)

target_include_directories(${PROJECT_NAME} PUBLIC "..")

# TODO : remove 
# why this existe : if not define cant be compile
target_compile_options(${PROJECT_NAME} PRIVATE -DFREETYPE_ENABLED)


# godotServers
target_link_libraries(${PROJECT_NAME} PRIVATE godotServers)


# TODO : remove depedence for Regex 
# can be change with std regex
# modules_regex
target_link_libraries(${PROJECT_NAME} PRIVATE module_regex)