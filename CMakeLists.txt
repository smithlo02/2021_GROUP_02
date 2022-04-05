cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

PROJECT( 2021_GROUP_02 )

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )


# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

include(CTest)

# Find the Qt widgets package. This locates the relevant include and
# lib directories, and the necessary static libraries for linking.
#find_package( Qt5Widgets )

#set( UIS application/mainwindow.ui )
#qt5_wrap_ui( UI_Srcs ${UIS} )

#set( ICONS application/Icons/icons.qrc )
#qt5_add_resources( QRC_Srcs ${ICONS} )


# Also link to VTK
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

if(WIN32)
	set(CPACK_GENERATOR "NSIS")
else()
	set(CPACK_GENERATOR "ZIP")
endif()
include(CPack)


# Define the executable output and its sources
add_library(cell library/cell/cell.cpp)
add_library(material library/material/material.cpp)
add_library(model library/model/model.cpp)
add_library(Vector3D library/Vector3D/Vector3D.cpp)
#add_library(ModelRender application/ModelRender.cpp)
#add_library(mainwindow application/mainwindow.cpp)


add_executable( 2021_GROUP_02 MACOSX_BUNDLE
				main.cpp
				)
# Add ${UI_Srcs} and ${QRC_Srcs} as executable in above line when final building
# Also remove qt ui comments above

target_link_libraries(2021_GROUP_02 cell material model Vector3D)

# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( 2021_GROUP_02 Qt5::Widgets )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( 2021_GROUP_02 ${VTK_LIBRARIES} )

install(TARGETS 2021_GROUP_02 
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

add_executable(libraryTest libraryTest.cpp)
target_link_libraries(libraryTest cell material model Vector3D)

add_test(libraryTest libraryTest)