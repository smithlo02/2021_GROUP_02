//-------------------------------------------------------------
// File to store all implementations of functions of Vector3D class.
//-------------------------------------------------------------

// Copyright Shiyu Wang (Student ID: 20158146)

//-------------------------------------------------------------

//INCLUDE header file for Vector3D,<iostream>
#include <iostream>
#include"Vector3D2.h"


//constructor initialization
vector::vector() { x_coordinate = 0; y_coordinate = 0; z_coordinate = 0; }


//destructor
vector::~vector(){}


//Giving the value of x,y,z
vector::vector(float xi, float yi, float zi) {
    x_coordinate = xi;
    y_coordinate = yi;
    z_coordinate = zi;
}


// allow user to get the vector
vector vector::get_vector() const {
    return *this;
}


//Setters
//Function of class Vector,setx(), sety(), setz()
//Function to set the values of vector coordinates
//Arguments for setx(), sety(), setz(): none.
//return: value of x, y and z
void vector::set_vector(const float& x, const float& y, const float& z) {

     this->x_coordinate =x;
     this->y_coordinate =y;
     this->z_coordinate =z;
}


//Addition
//action: add 3 vectors together
//return: added results of the addition operation
vector vector::operator+(vector& d)
{
    vector c;
    c.x_coordinate = x_coordinate + d.x_coordinate;
    c.y_coordinate = y_coordinate + d.y_coordinate;
    c.z_coordinate = z_coordinate + d.z_coordinate;
    return c;
}



//Subtraction
//action: subtract current vector from another vector
//return: results of the subtraction operation
vector vector::operator-(vector& d)
{
    vector c;
    c.x_coordinate = x_coordinate - d.x_coordinate;
    c.y_coordinate = y_coordinate - d.y_coordinate;
    c.z_coordinate = z_coordinate - d.z_coordinate;
    return c;
}


//Dot Product
//action: multiply the value in the coordinate of current vector to the equivelent coordinate of another vector
//return: scalar product obtained from dot operation
vector vector::operator*(vector& d)
{
    vector c;
    c.x_coordinate = x_coordinate * d.x_coordinate;
    c.y_coordinate = y_coordinate * d.y_coordinate;
    c.z_coordinate = z_coordinate * d.z_coordinate;
    return c;
}


// ^ overloading
vector vector::operator^(vector& d)
{
    vector c;
    c.x_coordinate = y_coordinate * d.z_coordinate - d.y_coordinate * z_coordinate;
    c.y_coordinate = z_coordinate * d.x_coordinate - d.z_coordinate * x_coordinate;
    c.z_coordinate = x_coordinate * d.y_coordinate - d.x_coordinate * y_coordinate;
    return c;
}


// print the vector
void vector::display_vector() {
    std::cout << "(" << x_coordinate << "," << y_coordinate << "," << z_coordinate << ")" << std::endl;
}

//end
