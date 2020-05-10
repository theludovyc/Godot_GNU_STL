project(godotUnix)

find_file(file mntent.h)
if( NOT file-NOTFOUND)
    add_definitions(-DHAVE_MNTENT)
endif()

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp})

# TODO : remove
target_include_directories(${PROJECT_NAME} PRIVATE "../../")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")
