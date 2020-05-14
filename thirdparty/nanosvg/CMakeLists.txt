project(nanosvg)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cc "*.cc")

add_library(${PROJECT_NAME} ${header} ${cc})

target_include_directories(${PROJECT_NAME} PUBLIC ".")