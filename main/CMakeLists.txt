project(godotMain)

set(generateFile)

add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/splash.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_splash.py" "${CMAKE_CURRENT_SOURCE_DIR}/splash.gen.h" "${CMAKE_CURRENT_SOURCE_DIR}/splash.png"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/splash.png"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/splash.gen.h")

add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/splash_editor.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_splash_editor.py" "${CMAKE_CURRENT_SOURCE_DIR}/splash_editor.gen.h" "${CMAKE_CURRENT_SOURCE_DIR}/splash_editor.png"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/splash_editor.png"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/splash_editor.gen.h")

add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_app_icon.py" "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.gen.h" "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.png"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
  DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.png"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.gen.h")


set(mappings "${CMAKE_CURRENT_SOURCE_DIR}/gamecontrollerdb.txt"
    "${CMAKE_CURRENT_SOURCE_DIR}/godotcontrollerdb.txt")
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/default_controller_mappings.gen.cpp"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_default_controller_mapping.py"
    "${CMAKE_CURRENT_SOURCE_DIR}/default_controller_mappings.gen.cpp"
    "\"${mappings}\""
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/default_controller_mappings.gen.cpp")


file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${header} ${cpp} ${generateFile})

# godotCore
target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

# TODO: suppress
target_include_directories(${PROJECT_NAME} PRIVATE "../")
target_include_directories(${PROJECT_NAME} PRIVATE "../platform/${target}")

if(tools)
    # godotEditor
    target_link_libraries(${PROJECT_NAME} PRIVATE godotEditor)
endif()