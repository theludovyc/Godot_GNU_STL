project(tests)

macro(build_test filePath)
    get_filename_component(fileName ${filePath} NAME_WE)

    add_executable(${fileName} ${filePath})
    target_link_libraries(${fileName} godot_stl)

    string(TOUPPER ${fileName} TESTNAME)

    add_test(${TESTNAME} ${fileName})
endmacro()

build_test(tester.cpp)

build_test(test_aabb.cpp)
#build_test(test_array.cpp)
build_test(test_vector.cpp)
