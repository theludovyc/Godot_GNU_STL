generateHeader(main/splash)

generateHeader(main/splash_editor)

generateHeader(main/app_icon)

file(GLOB src_main main/*.cpp)

list(APPEND SRC ${src_main})
