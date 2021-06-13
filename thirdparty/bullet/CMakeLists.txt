project(bullet)

file(GLOB_RECURSE SRC ./*.c)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

add_compile_definitions(BT_USE_OLD_DAMPING_METHOD)

add_library(${PROJECT_NAME} ${SRC})