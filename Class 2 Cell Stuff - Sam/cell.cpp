#include <iostream>
#include <cmath>
#include "cell.h"

// Function to get the vector points of a shape
float cell :: getPoints()
{
    // Get that from the vector class

}

//------------------------------------------------------------------------------------------------------------------
//The get functions are used to call the private/protected values
//------------------------------------------------------------------------------------------------------------------


// Function to calculate the weight of the shape
float cell :: getCellWeight()
{
    // Weight = Mass Times Gravity
    //
}

// Function to calculate the weight of the shape
float cell :: getCellVolume()
{

}

// Function to calculate the centre of gravity of the shape
float cell :: getCellCentreOfGravity
{

}

//------------------------------------------------------------------------------------------------------------------
// The set functions are used to return to the private/protected values
//------------------------------------------------------------------------------------------------------------------

// function to set the material of the cell
void cell :: setMaterial (material chosenMaterial)
{
    chosenMaterial = cellMaterial;
}

// function to set the vectors of the vertices of the cell
void setPoints(vector &pointVector3D;
void setMaterial();
void setCellWeight();                   // function to set the value of the weight of the cell
void setCellVolume();                   // function to set the value of the volume of the cell
void setCellCentreOfGravity();          // function to set the vector of the centre of gravity of the cell





// Tetrahedron Initialisation
tetrahedron :: tetrahedron (vector point0, vector point1, vector point2, vector point3);

{
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
}

// Tetrahedron Volume
tetrahedron :: getVolume()
{
    volume;

    // Vector calculation to find the volume of a tetrahedron
    volume = abs((this -> vector0 - this -> vector3)  *
                 ((this -> vector1 - this -> vector3)  ^
                  (this -> vector2 - this -> vector3)))/6;

    return volume;
}
