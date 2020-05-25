project(wslay)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

add_library(${PROJECT_NAME} ${header} ${c})

if(${target} STREQUAL "windows" OR ${target} STREQUAL "uwp")
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DHAVE_WINSOCK2_H)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DHAVE_NETINET_IN_H)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)

target_include_directories(${PROJECT_NAME} PUBLIC "includes")