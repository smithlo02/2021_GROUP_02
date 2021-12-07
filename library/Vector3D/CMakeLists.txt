#create a list of all header files for the library

cmake_minimum_required( VERSION 2.8 )
project( vector )
add_executable( Vector3D2
    main.cpp
    Vector3D2.h
    Vector3D2.cpp)

target_link_libraries(Vector3D2 )
