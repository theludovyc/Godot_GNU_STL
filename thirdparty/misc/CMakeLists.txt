
project(misc)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE c "*.c")

file(GLOB_RECURSE header_cpp "*.hpp")
file(GLOB_RECURSE cpp "*.cpp")

file(GLOB_RECURSE cpp_bis "*.cc")

# TODO : need to be remove
set(generateFile)
generateBindings(generateFile)

add_library(${PROJECT_NAME} ${header} ${c} ${header_cpp} ${cpp} ${cpp_bis} ${generateFile})

# TODO: need to be remove
target_include_directories(${PROJECT_NAME} PRIVATE "../..")
target_include_directories(${PROJECT_NAME} PRIVATE "../../platform/${target}")
