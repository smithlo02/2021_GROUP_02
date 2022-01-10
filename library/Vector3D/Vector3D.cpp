//-------------------------------------------------------------
// File to store all implementations of functions of Vector3D class.
// Copyright Shiyu Wang(20158146)
// Include header file for Vector3D
//-------------------------------------------------------------
#include "Vector3D.h"

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
Vector3D::Vector3D(double xc, double yc, double zc)
{
    ID = 0;
    x = xc;
    y = yc;
    z = zc;
}
//-------------------------------------------------------------
Vector3D::~Vector3D(){}// Destructor
//-------------------------------------------------------------
void Vector3D::setID(int newID){this->ID = newID;};
//-------------------------------------------------------------
void Vector3D::setx(double xc){x = xc;};
//-------------------------------------------------------------
void Vector3D::sety(double yc){y = yc;};
//-------------------------------------------------------------
void Vector3D::setz(double zc){z = zc;};
//-------------------------------------------------------------
int Vector3D::getID(){return this->ID;};
//-------------------------------------------------------------
double Vector3D::getx(){return x;}
//-------------------------------------------------------------
double Vector3D::gety(){return y;}
//-------------------------------------------------------------
double Vector3D::getz(){return z;}
//-------------------------------------------------------------
//copy vector constructor
//-------------------------------------------------------------
Vector3D::Vector3D(const Vector3D &vec)
{
    ID = vec.ID;
    x=vec.x;
    y=vec.y;
    z=vec.z;
}
//-------------------------------------------------------------
//Addition function
//Add 2 vectors together
//-------------------------------------------------------------
Vector3D Vector3D::operator+(const Vector3D &vec)
{
   return Vector3D( this->x + vec.x,
                    this->y + vec.y,
                    this->z + vec.z);
}

//-------------------------------------------------------------
//Subtraction function
//Subtract current vector from another vector
//-------------------------------------------------------------
Vector3D Vector3D::operator-(const Vector3D &vec)
{
    return Vector3D(this->x - vec.x,
                    this->y - vec.y,
                    this->z - vec.z);
}
//-------------------------------------------------------------
//Dot Product Function
//Multiply two coordinates
//-------------------------------------------------------------
double Vector3D::operator*(const Vector3D &vec)
{
    return (this->x*vec.x + this->y*vec.y + this->z*vec.z);
}
//-------------------------------------------------------------
//Cross Product Function
//Cross product
//-------------------------------------------------------------
Vector3D Vector3D::operator^(const Vector3D &vec)
{
    Vector3D ans;
    ans.x = this->y*vec.z - this->z*vec.y;
    ans.y = this->z*vec.x - this->x*vec.z;
    ans.z = this->x*vec.y - this->y*vec.x;

    return ans;
}
//-----------------------------------------------------------------------------------
