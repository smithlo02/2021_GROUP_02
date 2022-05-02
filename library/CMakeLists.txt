cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

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


include(CTest)

include_directories(Vector3D cell material model)

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