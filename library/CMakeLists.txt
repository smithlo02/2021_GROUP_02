#====================== Copyright:Shiyu Wang ========================# 
cmake_minimum_required(VERSION 3.17)

project( libraryTest )

project(library)
#=============INCLUSION OF Qt===================#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6Widgets REQUIRED)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )
#======================= INCLUSION OF VTK ======================#
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#======================= INCLUSION OF Our Code ======================#
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(CTest)

file(GLOB_RECURSE SOURCES
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)
#>>>>>>> 05eebbf76293b04cff260c45e20595f504fddef6

#tell CMake where to find the headers
include_directories(./include)

# generate a static lib
add_library(Semester1_LIBS ${SOURCES})

#<<<<<<< HEAD
# Define the executable output and its sources
add_library(cell cell/cell.cpp)
add_library(material material/material.cpp)
add_library(model model/model.cpp)
add_library(Vector3D Vector3D/Vector3D.cpp)
add_library(cell cell/cell.h)
add_library(material material/material.h)
add_library(model model/model.h)
add_library(Vector3D Vector3D/Vector3D.h)
# Tell CMake that the executable depends on the Qt::Widget libraries, VTK libraries and the ML library
target_link_libraries( library Qt6::Widgets )
target_link_libraries( library ${VTK_LIBRARIES})
target_link_libraries( application library)
# Ensure that ML_GUI can only build once ML_lib has built
add_dependencies(Test library)
#=======
add_executable( libraryTest MACOSX_BUNDLE
				libraryTest.cpp)

# Make sure the compiler can find include files when the other programs need to link against this library 
target_include_directories (Semester1_LIBS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (libraryTest Semester1_LIBS)

install(TARGETS libraryTest
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

add_test(libraryTest libraryTest)


#>>>>>>> 05eebbf76293b04cff260c45e20595f504fddef6
