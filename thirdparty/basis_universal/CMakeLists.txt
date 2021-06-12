project(basis_universal)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/encoder/*.c ${CMAKE_CURRENT_SOURCE_DIR}/encoder/*.cpp)

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} SRC zstd)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/encoder ${CMAKE_CURRENT_SOURCE_DIR}/transcoder)