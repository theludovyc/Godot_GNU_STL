project(godotUnix)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

if(${target} STREQUAL "windows")
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32 iphlpapi)
endif()

# for thread
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
