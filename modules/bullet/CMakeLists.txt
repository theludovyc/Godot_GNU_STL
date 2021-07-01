project(modules_bullet)

file(GLOB src "*.cpp")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

add_compile_definitions(BT_USE_OLD_DAMPING_METHOD)

add_library(${PROJECT_NAME} ${src})

target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(thirdparty_bullet)
