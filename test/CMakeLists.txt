add_subdirectory(./googletest)
set(GTEST_SRC_DIR ./googletest-master/)
include_directories(${GTEST_SRC_DIR}/include ${GTEST_SRC_DIR})

set(TEST RunAllTest.cpp
        TestCollezione.cpp
        TestPaginaHome.cpp)
add_executable(runAllTest ${TEST})
target_link_libraries(runAllTest gtest gtest_main core)