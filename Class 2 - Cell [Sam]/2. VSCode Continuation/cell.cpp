#include <iostream>
#include <cmath>

// Include all the required header files for the project to ensure that the code works properly
#include "cell.h"
#include "Vector3D.h"
#include "Material.h"
#include <math.h>

//------------------------------------------------------------------------------------------------------------------
//The constructors are used to initialise the member variables
//------------------------------------------------------------------------------------------------------------------

cell::cell(int c_ID, material c_material, float c_volume, float c_weight, pointVector3D c_centre, pointVector3D p_Vector)
{
    this-> cellID               = c_ID;
    this-> cellMaterial         = c_material;
    this-> cellVolume           = c_volume;
    this-> cellWeight           = c_weight;
    this-> cellCentreOfGravity  = c_centre;
    this-> pointVector3D[]      = p_Vector;
}

//------------------------------------------------------------------------------------------------------------------
//The get functions are used to call the private/protected values
//------------------------------------------------------------------------------------------------------------------

// Function to get ID of a cell

char cell :: getCellID()
{
    return this-> cellID;
}

// Function to get type of a cell

char cell :: getCellType()
{
    return this-> cellType;
}

// Function to get the material of a cell

material cell :: getCellMaterial()
{
    return this-> CellMaterial;
}

// Function to get the vector points of a cell
float cell :: getPoints()
{
    return this-> pointVector3D;
}

// Function to get the volume of a cell

float cell :: getCellVolume()
{
    return this-> cellVolume;
}

// Function to get the weight of a cell
float cell :: getCellWeight()
{
    return this-> cellWeight;
}

// Function to calculate the centre of gravity of a cell

float cell :: getCellCentreOfGravity
{
    return this-> cellCentreOfGravity;
}

//------------------------------------------------------------------------------------------------------------------
// The set functions are used to return to the private/protected values
//------------------------------------------------------------------------------------------------------------------

// function to set the vectors of the vertices of the cell
void cell :: setPoints(pointVector3D &thatPointVector3D)
{
    this-> pointVector3D = thatPointVector3D;
}

void cell :: setMaterial(material &thatMaterial)
{
    this-> cellMaterial = thatMaterial;
}


//------------------------------------------------------------------------------------------------------------------
//The calculate functions are used to compute values using generic cell members
//------------------------------------------------------------------------------------------------------------------

void calculateCellVolume()
{

}

void calculateCellWeight()
{
    this-> cellWeight = Density * this-> cellVolume * 9.8
}

void calculateCellCentreOfGravity()
{

}

//------------------------------------------------------------------------------------------------------------------
//The shape calculate functions are used to compute values using their specific cell members
//------------------------------------------------------------------------------------------------------------------

// Tetrahedron Initialisation
tetrahedron :: tetrahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3);

{
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
}

// Tetrahedron Centre of Gravity
void tetrahedron :: calculateCellCentreOfGravity() override
{

}

// Tetrahedron Volume
void tetrahedron :: calculateCellVolume() override
{
    float volume;

    // Vector calculation to find the volume of a tetrahedron
    this -> cellVolume = 1/6 * 
                        abs (( this -> vector0 - this -> vector3)  *
                            (( this -> vector1 - this -> vector3)  ^
                             ( this -> vector2 - this -> vector3)));

}

// Hexahedron Centre of Gravity
void Hexahedron :: calculateCellCentreOfGravity() override
{

}

// Hexahedron Volume
void Hexahedron :: calculateCellVolume() override
{

}

// Pyramid Centre of Gravity
void pyramid :: calculateCellCentreOfGravity() override
{

}

// pyramid Volume
void pyramid :: calculateCellVolume() override
{

}