project(tests)

macro(build_test testName)
    add_executable(${testName} ${testName}.cpp)
    target_link_libraries(${testName} godot_stl)

    string(TOUPPER ${testName} TESTNAME)

    add_test(${TESTNAME} ${testName})
endmacro()

build_test(test_aabb)
build_test(test_vector)
