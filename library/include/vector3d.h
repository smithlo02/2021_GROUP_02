//---------------------------------------------------------
//file Vector3D.h File Reference
//Copyright  Code part:Shiyu Wang(20158146)
//Required header files: vector.h math.h(for some mathematic functions)
//---------------------------------------------------------
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>
using namespace std;

/** @file
* The source file for the vector3D class
*/

class vector3D
{

    friend ostream& operator<<(ostream& os,  vector3D &v); // make the overloading << operator as a friend to print out the vector 
                                                               
    friend istream& operator>>(istream& is,  vector3D &v); // make the overloading >> operator as a firend for use to read VTK style data from a file 

    friend class Matrix; //make matrix class as a friend to let it access the private variables.

public:

    /** Default constructor of a vector
    * 
    */
    vector3D();//default constructor

    /** The constructor for a vector with known coordinates
    * 
    */
    vector3D(const int &index,const double &xi, const double &yi,const double &zi) :Index(index), X(xi), Y(yi), Z(zi){}; //constructor

    /** Vector subraction operator
    *
    */
    vector3D operator-(const vector3D &v); // overloading the - operator to do the vector subtraction

    /** Vector addition operator
    *
    */
    vector3D operator+(const vector3D &v); // overloading the + operator to do the vector addition

    /** Overloaded operator
    * Overloaded operator to do the vector/outer product calculation
    */
    vector3D operator^(const vector3D &v); // overloading the ^ operator to do the vector/outer product calculation

    /**Overloaded vector for vector division
    * Vector division operator with a floating number
    */
    vector3D operator/(const double &v);  //overloading the /operator to do the vector division with a floating number

    /** Overloaded vector muliplier
    * Scalar vector multiplication 
    */
    double operator*(const vector3D &v); // overloading the * operator to do the scalar product calculation

    /** Get vector index/ID number
    *
    */
    int get_ID()const{return this->Index;}; //function to get the vector Index;

    /** Get vector X coordinate
    *
    */
    double get_X()const{return this->X;};   //get x 

    /** Get vector y coordinate
    *
    */
    double get_Y()const{return this->Y;};   //get y 

    /** Get vector Z coordinate
    *
    */
    double get_Z()const{return this->Z;};   //get z

    /** Vector accessor
    * Returns a pointer to this vector
    */
    vector3D& get_Vector(){return *this;}; // accessor

    /** Sets the vector coordinates
    *
    */
    void set_Vector(const double &x, const double &y, const double &z); // mutator

private:
    /** XYZ coordinates
    * The coordinates of the vector stored as doubles
    */
    double X, Y, Z; // define 3 variables to store the X-axis, Y-axis, Z-axis value of a vector
    
    /** The index of the vector
    *
    */
    int Index;  // this the unique index for a vector 
};
#endif // VECTOR3D_H

