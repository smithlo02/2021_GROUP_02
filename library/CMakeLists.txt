cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

PROJECT( libraryTest )

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )


# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

include(CTest)

include_directories(Vector3D cell material model)

# Define the executable output and its sources
add_library(cell cell/cell.cpp)
add_library(material material/material.cpp)
add_library(model model/model.cpp)
add_library(Vector3D Vector3D/Vector3D.cpp)

add_executable( libraryTest MACOSX_BUNDLE
				libraryTest.cpp)

target_link_libraries(libraryTest PUBLIC cell PUBLIC tetrahedron PUBLIC hexahedron PUBLIC pyramid material model Vector3D)

install(TARGETS libraryTest
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

add_test(libraryTest libraryTest)