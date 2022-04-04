//-------------------------------------------------------------
// File to store all implementations of functions of Vector3D class.
// Copyright Shiyu Wang(20158146)
// Include header file for Vector3D
//-------------------------------------------------------------

/** @file
* The Vector3D class that is used to provide vector coordinates
*/

#include "Vector3D.h"

/** Constructor
* The default vector constructor
*/
Vector3D::Vector3D()
{
    ID = 0;
    x = 0;
    y = 0;
    z = 0;   //ctor
}
//-------------------------------------------------------------
//giving object values
//-------------------------------------------------------------

/** Constructor
* The vector constructor used when values are provided for the coordinates
*/
Vector3D::Vector3D(double xc, double yc, double zc)
{
    ID = 0;
    x = xc;
    y = yc;
    z = zc;
}
//-------------------------------------------------------------
/** Destructor
* The vector3D destructor
*/
Vector3D::~Vector3D() {}// Destructor
//-------------------------------------------------------------

/** Setter
* The vector ID setter
*/
void Vector3D::setID(int newID) { this->ID = newID; };
//-------------------------------------------------------------

/** Setter
* The function to set the x coordinate
*/
void Vector3D::setx(double xc) { x = xc; };
//-------------------------------------------------------------

/** Setter
* The function to set the y coordinate
*/
void Vector3D::sety(double yc) { y = yc; };
//-------------------------------------------------------------

/** Setter
* The function to set the z coordinate
*/
void Vector3D::setz(double zc) { z = zc; };
//-------------------------------------------------------------

/** Getter
* The function to get the vector ID
*/
int Vector3D::getID() { return this->ID; };
//-------------------------------------------------------------

/** Getter
* The function to get the x coordinate
*/
double Vector3D::getx() { return x; }
//-------------------------------------------------------------

/** Getter
* The function to get the y coordinate
*/
double Vector3D::gety() { return y; }
//-------------------------------------------------------------

/** Getter
* The function to get the z coordinate
*/
double Vector3D::getz() { return z; }
//-------------------------------------------------------------
//copy vector constructor
//-------------------------------------------------------------

/** Constructor
* The Vector copy constructor
*/
Vector3D::Vector3D(const Vector3D& vec)
{
    ID = vec.ID;
    x = vec.x;
    y = vec.y;
    z = vec.z;
}
//-------------------------------------------------------------
//Addition function
//Add 2 vectors together
//-------------------------------------------------------------

/** Overloaded operator
* The function to add 2 vectors together
*/
Vector3D Vector3D::operator+(const Vector3D& vec)
{
    return Vector3D(this->x + vec.x,
        this->y + vec.y,
        this->z + vec.z);
}

//-------------------------------------------------------------
//Subtraction function
//Subtract current vector from another vector
//-------------------------------------------------------------
/** Overloaded operator
* The function to subract the current vector from another
*/
Vector3D Vector3D::operator-(const Vector3D& vec)
{
    return Vector3D(this->x - vec.x,
        this->y - vec.y,
        this->z - vec.z);
}
//-------------------------------------------------------------
//Dot Product Function
//Multiply two coordinates
//-------------------------------------------------------------
/** Overloaded operator
* The function to multiply two vector coordinates
*/
double Vector3D::operator*(const Vector3D& vec)
{
    return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
}
//-------------------------------------------------------------
//Cross Product Function
//Cross product
//-------------------------------------------------------------
/** Overloaded operator
* The function to compute the cross product of 2 vectors
*/
Vector3D Vector3D::operator^(const Vector3D& vec)
{
    Vector3D ans;
    ans.x = this->y * vec.z - this->z * vec.y;
    ans.y = this->z * vec.x - this->x * vec.z;
    ans.z = this->x * vec.y - this->y * vec.x;

    return ans;
}
//-----------------------------------------------------------------------------------
