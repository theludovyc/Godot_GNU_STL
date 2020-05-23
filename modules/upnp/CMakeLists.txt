project(module_upnp)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE miniupnpc)

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

target_compile_definitions(${PROJECT_NAME} PRIVATE -DMINIUPNP_STATICLIB
-DMINIUPNPC_SET_SOCKET_TIMEOUT)