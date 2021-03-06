cmake_minimum_required(VERSION 3.17)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

project(computingProject)

#Include sub-projects
add_subdirectory(QVTKApplication)
add_subdirectory(Semester1-Libs)

#include ctest for testfile
include(CTest)
#=============INCLUSION OF Qt===================##set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

set( ICONS Icons/icons.qrc )
qt5_add_resources( QRC_Srcs ${ICONS} )

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )

#=============Include VTK=======================#
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )


# set default for cpack
set(CPACK_PACKAGE_NAME "ComputingProject")
set(CPACK_NSIS_DISPLAY_NAME "3DMODELVIEWER")
set(CPACK_PACKAGE_VENDOR "GROUP2")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Group_2 - 3D modelling viewer")


if(WIN32)
 set(CPACK_GENERATOR "NSIS")
else()
 set(CPACK_GENERATOR "ZIP")
endif()

# add the required UCRT libraries
set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)

include(InstallRequiredSystemLibraries)
set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)

add_executable( projectOutput MACOSX_BUNDLE
    QVTKApplication/src/main.cpp
    ${QRC_Srcs}
    ${UI_Srcs}
    )

include_directories(Semester1-Libs/include Semester1-Libs/src)

add_library( cell Semester1-Libs/src/cell.cpp)
add_library( material Semester1-Libs/src/material.cpp)
add_library( vector3d Semester1-Libs/src/vector3d.cpp)
add_library( model Semester1-Libs/src/model.cpp)

target_link_libraries( projectOutput cell material vector3d model)

# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( projectOutput Qt5::Widgets Qt5::Gui Qt5::Core Qt5:Sql)

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( projectOutput ${VTK_LIBRARIES} )


# Install Directories
#  - These targets and directories will be installed in the final install location
install(TARGETS projectOutput 
	RUNTIME DESTINATION bin
 	LIBRARY DESTINATION lib
 	ARCHIVE DESTINATION lib/static)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/QVTKApplication/ICONS/
       DESTINATION QVTKApplication COMPONENT RUN)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/build/Qt_dll/
        DESTINATION bin COMPONENT RUN)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/../../bin/
        DESTINATION bin COMPONENT RUN)
install(DIRECTORY ${CMAKE_SOURCE_SDIR}/RESOURCE/STL/
        DESTINATION Mod)

#----------installer option---------------------#
SET( CPACK_COMPONENTS_ALL APP RUN MOD )

# create a package Applicaion
SET( CPACK_COMPONENT_APP_DISPLAY_NAME "application" )
SET( CPACK_COMPONENT_APP_DESCRIPTION "An application use for 3D modelling" )

# create a package Runtime Libraries
SET (CPACK_COMPONENT_RUN_DISPLAY_NAME "Runtime Libraries" )
SET (CPACK_COMPONENT_RUN_DESCRIPTION "Require libraries from VTK, Qt and Micresoft Visual Studio" )

# create a package Example MOD files
SET (CPACK_COMPONENT_MOD_DISPLAY_NAME "Resource" )
SET (CPACK_COMPONENT_MOD_DESCRIPTION " Example of Model files" )
