cmake_minimum_required(VERSION 3.17)

project( libraryTest )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(CTest)


# Define the executable output and its sources
add_library(cell src/cell.cpp)
add_library(material srcmaterial.cpp)
add_library(model srcmodel.cpp)
add_library(vector3D src/vector3D.cpp)
add_library(cell include/cell.h)
add_library(material include/material.h)
add_library(model include/model.h)
add_library(vector3D include/vector3D.h)
# Tell CMake that the executable depends on the Qt::Widget libraries, VTK libraries and the ML library

add_executable( libraryTest MACOSX_BUNDLE
				libraryTest.cpp)

# Make sure the compiler can find include files when the other programs need to link against this library 
target_include_directories (Semester1_LIBS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (libraryTest cell material model vector3D)

install(TARGETS libraryTest
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

add_test(libraryTest libraryTest)



