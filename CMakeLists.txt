
# Minimum Version Required
cmake_minimum_required(VERSION 3.3)

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

# Start Menu
set (CPACK_PACKAGE_EXECUTABLES "application" "2021_GROUP_02" )

# ----------------------------------------------------------------------