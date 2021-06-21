file(GLOB src_core *.cpp)

file(GLOB_RECURSE
        src_core1
        core/config/*.cpp
        core/debugger/*.cpp
        core/error/*.cpp
        core/io/*.cpp
        core/math/*.cpp
        core/object/*.cpp
        core/os/*.cpp
        core/string/*.cpp
        core/templates/*cpp
        core/variant/*.cpp
        )

list(APPEND SRC ${src_core} ${src_core1})
