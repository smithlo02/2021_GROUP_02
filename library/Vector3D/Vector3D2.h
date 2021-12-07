/*  ----------------------------------------------------
 *  file Vector3D.h File Reference
    author    Copyright ：Shiyu Wang (Student ID: 20158146)

    brief     Required header files: Vector3D2.h
    -----------------------------------------------------
*/


#ifndef VECTOR_H
#define  VECTOR_H

#include <iostream>

//---------------------------------------

/*   class 'pointVector3D'
     brief Creates a virtual vector by storing information.
*/

class pointVector3D {
public:

    //constructor
    pointVector3D();
    //constructor
    pointVector3D(float xi, float yi, float zi);

    //destructor
    ~pointVector3D();

    /*  overloading + - * ^
       +: addition
       -: subtraction
       *: inner product
       ^: outer product
       */
    pointVector3D operator +(pointVector3D& d);
    pointVector3D operator -(pointVector3D& d);
    pointVector3D operator *(pointVector3D& d);
    pointVector3D operator ^(pointVector3D& d);

    // print the pointVector3D
    void display_vector();

    //accessor
    pointVector3D get_vector() const;

    /* Function of class Vector set pointVector3D()
       Function to set the x,y,z value
       Argument: float - new x,y,z value.
       return  none */
    void set_vector(const float& x,const float& y,const float& z);

private:

    float x_coordinate;
    float y_coordinate;
    float z_coordinate;
};

 #endif
