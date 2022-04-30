

cmake_minimum_required(VERSION 2.8.0)
# General set up
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Group_Sem2)


if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type set to ${CMAKE_BUILD_TYPE}")

# Compile the Model Loading Library files
add_subdirectory(Library)

# Compile the VTK files
add_subdirectory(VTK)

# include ctest for testfile
include(CPack)

# set default for cpack
set(CPACK_PACKAGE_NAME "Group_Sem2")
set(CPACK_NSIS_DISPLAY_NAME "Group_Sem2")
set(CPACK_PACKAGE_VENDOR "GROUP2")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set license 
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/License.txt" )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
if(WIN32)
  set(CPACK_GENERATOR "NSIS")
else()
  set(CPACK_GENERATOR "ZIP")
endif()
  set(INSTALL_CMAKEDIR ${DEF_INSTALL_CMAKEDIR} CACHE PATH "Installation directory for CMake files")

# include VTK
find_package( VTK REQUIRED NO_MODULE)
include( ${VTK_USE_FILE} )

# add required libraries
set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)

# include runtime libraries (msvc)
set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP TRUE)
include(InstallRequiredSystemLibraries)
install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION bin COMPONENT RUN )

# install an application
install(TARGETS Group_Sem2
        RUNTIME DESTINATION bin
	LIBRARY DESTINATION bin
	ARCHIVE DESTINATION bin)

# install require Qt libraries
install( DIRECTORY "${PROJECT_SOURCE_DIR}/build/Qt_dll/" DESTINATION bin)

# install require VTK libraries
install( DIRECTORY "${VTK_INCLUDE_DIRS}/../../bin/" DESTINATION bin)

# install header file
# install( DIRECTORY "${PROJECT_SOURCE_DIR}/Library/Inc/" DESTINATION Inc COMPONENT IncSrc)

# install source file
# file(GLOB_RECURSE Src "${PROJECT_SOURCE_DIR}/Library/Src/*.cpp")
# install( FILES ${Src} DESTINATION Src COMPONENT IncSrc )

# install example mod file
install( DIRECTORY "${PROJECT_SOURCE_DIR}/Library/Mod Example Files/ )

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

