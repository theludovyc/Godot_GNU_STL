
project(misc)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

file(GLOB_RECURSE header_cpp "*.hpp")
file(GLOB_RECURSE cpp "*.cpp")

file(GLOB_RECURSE cpp_bis "*.cc")

if(${target} STREQUAL "windows")
    list(REMOVE_ITEM header ${CMAKE_CURRENT_SOURCE_DIR}/ifaddrs-android.h)
    list(REMOVE_ITEM cpp_bis ${CMAKE_CURRENT_SOURCE_DIR}/ifaddrs-android.cc)
endif()

# TODO : need to be remove
set(generateFile "${CMAKE_SOURCE_DIR}/core/method_bind.gen.inc" "${CMAKE_SOURCE_DIR}/core/method_bind_ext.gen.inc" "${CMAKE_SOURCE_DIR}/core/method_bind_free_func.gen.inc")

add_library(${PROJECT_NAME} ${header} ${c} ${header_cpp} ${cpp} ${cpp_bis} ${generateFile})

# TODO: need to be remove
target_include_directories(${PROJECT_NAME} PRIVATE "../..")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")
