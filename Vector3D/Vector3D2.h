/*  ----------------------------------------------------
 *  file Vector3D.h File Reference
    author    Copyright ：Shiyu Wang (Student ID: 20158146)

    brief     Required header files: vector.h
    -----------------------------------------------------
*/


#ifndef VECTOR_H
#define  VECTOR_H

#include <iostream>

//---------------------------------------

/*   class 'Vector3D'
     brief Creates a virtual Vector3D by storing information.
*/

class vector {
public:

    //constructor
    vector();
    //constructor
    vector(float xi, float yi, float zi);

    //destructor
    ~vector();

    /*  overloading + - * ^
       +: addition
       -: subtraction
       *: inner product
       ^: outer product
       */
    vector operator +(vector& d);
    vector operator -(vector& d);
    vector operator *(vector& d);
    vector operator ^(vector& d);

    // print the vector
    void display_vector();

    //accessor
    vector get_vector() const;

    /* Function of class Vector set vector()
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
