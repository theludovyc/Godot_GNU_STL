project(godotCore)




set(generateFile)

add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/script_encryption_key.gen.cpp"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_key.py"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/core"
  DEPENDS "${CMAKE_SOURCE_DIR}/script/generate_key.py"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/script_encryption_key.gen.cpp")


option(builtin_certs "Use the built-in SSL certificates bundles" ON)
set(system_certs_path "" CACHE STRING "Use this path as SSL certificates default for editor (for package maintainers)")
add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/io/certs_compressed.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_certs_header.py"
  "${CMAKE_CURRENT_SOURCE_DIR}/io/certs_compressed.gen.h"
  "../thirdparty/certs/ca-certificates.crt"
  " ${system_certs_path}"
  "${builtin_certs}"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/core"
  DEPENDS "../thirdparty/certs/ca-certificates.crt"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/io/certs_compressed.gen.h")


# TODO : need to be change
generateBindings(generateFile)

# add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/method_bind.gen.inc" "${CMAKE_CURRENT_SOURCE_DIR}/method_bind_ext.gen.inc" "${CMAKE_CURRENT_SOURCE_DIR}/method_bind_free_func.gen.inc"
#   COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_binders.py"
#   WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/script"
# 	)
# list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/method_bind.gen.inc" "${CMAKE_CURRENT_SOURCE_DIR}/method_bind_ext.gen.inc" "${CMAKE_CURRENT_SOURCE_DIR}/method_bind_free_func.gen.inc")




add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/authors.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_authors_header.py"
  "${CMAKE_CURRENT_SOURCE_DIR}/authors.gen.h"
  "${CMAKE_SOURCE_DIR}/AUTHORS.md"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/core"
  DEPENDS "${CMAKE_SOURCE_DIR}/AUTHORS.md"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/authors.gen.h")


add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/donors.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_donors_header.py"
  "${CMAKE_CURRENT_SOURCE_DIR}/donors.gen.h"
  "${CMAKE_SOURCE_DIR}/DONORS.md"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/core"
  DEPENDS "${CMAKE_SOURCE_DIR}/DONORS.md"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/donors.gen.h")


add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/license.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_license_header.py"
  "${CMAKE_CURRENT_SOURCE_DIR}/license.gen.h"
  "${CMAKE_SOURCE_DIR}/COPYRIGHT.txt"
  "${CMAKE_SOURCE_DIR}/LICENSE.txt"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/core"
  DEPENDS "${CMAKE_SOURCE_DIR}/COPYRIGHT.txt"
  "${CMAKE_SOURCE_DIR}/LICENSE.txt"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/license.gen.h")

add_custom_command(OUTPUT "${CMAKE_CURRENT_SOURCE_DIR}/version_hash.gen.h" "${CMAKE_CURRENT_SOURCE_DIR}/version_generated.gen.h"
  COMMAND ${Python_EXECUTABLE} "${CMAKE_SOURCE_DIR}/script/generate_version.py"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  DEPENDS "${CMAKE_SOURCE_DIR}/script/generate_version.py"
	)
list(APPEND generateFile "${CMAKE_CURRENT_SOURCE_DIR}/version_hash.gen.h" "${CMAKE_CURRENT_SOURCE_DIR}/version_generated.gen.h")

file(GLOB_RECURSE header "*.h")
file(GLOB_RECURSE cpp "*.cpp")

add_library(${PROJECT_NAME} ${generateFile} ${header} ${cpp})

# TODO: suppress
target_include_directories(${PROJECT_NAME} PRIVATE "../")
target_include_directories(${PROJECT_NAME} PRIVATE "../platform/${target}")

target_link_libraries(${PROJECT_NAME} PRIVATE misc)

# TODO : need to set private
target_link_libraries(${PROJECT_NAME} PUBLIC minizip)

target_link_libraries(${PROJECT_NAME} PRIVATE zstd)
target_link_libraries(${PROJECT_NAME} PRIVATE mbedtls)
