#include <iostream>
#include <cmath>

// Include all the required header files for the project to ensure that the code works properly
#include "cell.h"
#include "Vector3D2.h"
#include "material.h"
#include <math.h>

//------------------------------------------------------------------------------------------------------------------
//The constructors are used to initialise the member variables
//------------------------------------------------------------------------------------------------------------------

cell::cell (char c_ID, char c_type, material c_material, float c_volume, float c_weight, 
            pointVector3D c_centre, vector<pointVector3D> verts)
{
    this-> cellID               = c_ID;
    this-> cellType             = c_type;
    this-> cellMaterial         = c_material;
    this-> cellVolume           = c_volume;
    this-> cellWeight           = c_weight;
    this-> cellCentreOfGravity  = c_centre;
    this-> vertices             = verts;
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
    return this-> cellMaterial;
}

// Function to get the vector points of a cell
vector<pointVector3D> cell :: getPoints()
{
    return this-> vertices;
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

pointVector3D cell :: getCellCentreOfGravity()
{
    return this-> cellCentreOfGravity;
}

//------------------------------------------------------------------------------------------------------------------
// The set functions are used to return to the private/protected values
//------------------------------------------------------------------------------------------------------------------

// function to set the vectors of the vertices of the cell
void cell :: setPoints(vector<pointVector3D> theseVertices)
{
    this-> vertices = theseVertices;
}

void cell :: setMaterial(material &thatMaterial)
{
    this-> cellMaterial = thatMaterial;
}


//------------------------------------------------------------------------------------------------------------------
//The calculate functions are used to compute values using generic cell members
//------------------------------------------------------------------------------------------------------------------

void cell :: calculateCellVolume()
{
    printf("Base cell has no volume");
}

void cell :: calculateCellWeight()
{
    this-> cellWeight = this-> cell.material.getDensity() * this-> cellVolume * 9.8
}

void cell :: calculateCellCentreOfGravity()
{

}

//------------------------------------------------------------------------------------------------------------------
//The specific shape constructor initialisatons and volume functions
//------------------------------------------------------------------------------------------------------------------

// Tetrahedron Initialisation
tetrahedron :: tetrahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3);
{
    this -> cellType = t;
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;

}


// Tetrahedron Volume
void tetrahedron :: calculateCellVolume()
{
    float volume;

    // Vector calculation to find the volume of a tetrahedron
    this -> cellVolume = 1/6 * 
                        abs (( this -> vector0 - this -> vector3)  *
                            (( this -> vector1 - this -> vector3)  ^
                             ( this -> vector2 - this -> vector3)));

}

// Hexahedron Initialisation
hexahedron :: hexahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3
                            pointVector3D point4, pointVector3D point5, pointVector3D point6, pointVector3D point7);
{
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
    this -> vector4 = point4;
    this -> vector5 = point5;
    this -> vector6 = point6;
    this -> vector7 = point7;
    this -> cellType = h;

}

// Hexahedron Volume
void hexahedron :: calculateCellVolume()
{

}

// Pyramid Initialisation
pyramid :: pyramid (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3, pointVector3D point4);
{
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
    this -> vector3 = point4;
    this -> cellType = p;

}

// pyramid Volume
void pyramid :: calculateCellVolume()
{

}