//---------------------------------------------------------
//file Vector3D.h File Reference
//Copyright  Code part:Shiyu Wang(20158146)
//Required header files: vector.h math.h(for some mathematic functions)
//---------------------------------------------------------

/** @file
* The header file for the Vector3D class
*/

#include <vector>
#include <math.h>

#ifndef VECTOR3D_H
#define VECTOR3D_H

//---------------------------------------------------------
class Vector3D;// There exist these things called cell
//---------------------------------------------------------

// Vector3D:

//---------------------------------------------------------
class Vector3D
{
    friend class Matrix;
public:
    /** Public Attributes
    * The public attributes for the class
    */
    Vector3D();// Constructor
    Vector3D(double, double, double);// giving object value
    virtual ~Vector3D();// Destructor
    Vector3D(const Vector3D& vec);// copy constructor

    void setID(int);
    void setx(double);
    void sety(double);
    void setz(double);

    int getID();
    double getx();
    double gety();
    double getz();
    //---------------------------------------------------------
    // Defines an operator that do
    // addition,Subtraction,Dot Product and Cross Product
    //---------------------------------------------------------
    Vector3D operator+(const Vector3D& vec);
    Vector3D operator-(const Vector3D& vec);
    double operator*(const Vector3D& vec);
    Vector3D operator^(const Vector3D& vec);


protected:

private:
    /** Private attributes
    * The private attributes for ther class
    */
    int ID;
    double x, y, z;

};

#endif // VECTOR3D_H
