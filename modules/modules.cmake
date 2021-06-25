add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/core/modules_enabled.gen.h
        COMMAND ${Python3_EXECUTABLE} pygen_script/generate_modules_enabled.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS pygen_script/generate_modules_enabled.py
)

list(APPEND SRC ${CMAKE_CURRENT_SOURCE_DIR}/core/modules_enabled.gen.h)

file(GLOB modules_cmakes modules/*/*.cmake)

foreach(modules_cmake ${modules_cmakes})
    include(${modules_cmake})
endforeach()
