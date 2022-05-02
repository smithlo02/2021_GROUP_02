#====================== Copyright:Shiyu Wang ========================# 
cmake_minimum_required(VERSION 3.17)

project( libraryTest )

#======================= INCLUSION OF Our Code ======================#
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(CTest)

file(GLOB_RECURSE SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#tell CMake where to find the headers
include_directories(./include)

# generate a static lib
add_library(libraryTest ${SOURCES})

add_executable( libraryTest MACOSX_BUNDLE
				libraryTest.cpp)

# Make sure the compiler can find include files when the other programs need to link against this library 
target_link_libraries (libraryTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS libraryTest
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

add_test(libraryTest libraryTest)


