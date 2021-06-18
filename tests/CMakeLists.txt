project(tests)

add_executable(test_vector test_vector.cpp)

target_link_libraries(test_vector core)

add_test(TestVector test_vector)
