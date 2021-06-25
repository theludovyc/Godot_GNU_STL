generateFile(main/splash)

generateFile(main/splash_editor)

generateFile(main/app_icon)

file(GLOB src_main main/*.cpp)

list(APPEND SRC ${src_main})
