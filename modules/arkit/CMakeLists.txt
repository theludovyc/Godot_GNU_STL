# TODO : need to be test

project(module_arkit)

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE mm "*.mm")

add_library(${PROJECT_NAME} ${header} ${mm})