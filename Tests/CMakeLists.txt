project(Tests)

enable_testing()
find_package(GTest)
if (GTest_FOUND)
    set(TEST_SOURCES BTree.cpp huffman.cpp)

    add_executable(${PROJECT_NAME} ${SOURCES} ${TEST_SOURCES})

    target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

    gtest_discover_tests(${PROJECT_NAME})
endif ()
