
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(test)
include(CTest)
add_executable(VectorTest vector3Dtest.cpp)
target_link_libraries(VectorTest library)

add_executable(MaterialTest Class_tester.cpp)
target_link_libraries(MaterialTest library)

add_executable(CellTester celltester.cpp)
target_link_libraries(CellTester library)

add_test(test VectorTest MaterialTest CellTester)
