
<<<<<<< HEAD
# Minimum Version Required
cmake_minimum_required(VERSION 3.3)
=======
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

# Find the Qt widgets package. This locates the relevant include and
# lib directories, and the necessary static libraries for linking.
find_package( Qt6Widgets )

set( UIS application/mainwindow.ui )
qt6_wrap_ui( UI_Srcs ${UIS} )

set( ICONS application/Icons/icons.qrc )
qt6_add_resources( QRC_Srcs ${ICONS} )


# Also link to VTK
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )
>>>>>>> 05eebbf76293b04cff260c45e20595f504fddef6

# Installer Scripts
#  - Chooses whether to use NSIS or not
if(WIN32)
  set(CPACK_GENERATOR "NSIS")
else()
  set(CPACK_GENERATOR "ZIP")
endif()
include(CPack)

########  PROJECT NAME  ########
project(2021_GROUP_02)

# Includes
include_directories(library)
include(InstallRequiredSystemLibraries)


# Subdirectories
#  - These are the CMake projects that will also be built
add_subdirectory(library)
add_subdirectory(application)


<<<<<<< HEAD
# Install Directories
#  - These targets and directories will be installed in the final install location
install(TARGETS application library
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib/static)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/VTK/
        DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/Qt/
        DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/resources/MSVC/
        DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/examples/
        DESTINATION Examples_and_Models)
=======
# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( 2021_GROUP_02 Qt6::Widgets )
>>>>>>> 05eebbf76293b04cff260c45e20595f504fddef6

# Start Menu
set (CPACK_PACKAGE_EXECUTABLES "application" "2021_GROUP_02" )

# ----------------------------------------------------------------------