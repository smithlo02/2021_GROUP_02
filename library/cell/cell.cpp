#include <iostream>
#include <cmath>

// Include all the required header files for the project to ensure that the code works properly
#include "cell.h"
#include "vector3D.h"
#include "material.h"
#include <math.h>

//------------------------------------------------------------------------------------------------------------------
//The constructors are used to initialise the member variables
//------------------------------------------------------------------------------------------------------------------

cell::cell (char c_ID, char c_type, vector<vector3D> verts, material c_material, float c_volume, float c_weight,
            vector3D c_centre)
{
    this-> cellID               = c_ID;
    this-> cellType             = c_type;
    this-> vertices             = verts;
    this-> cellMaterial         = c_material;
    this-> cellVolume           = c_volume;
    this-> cellWeight           = c_weight;
    this-> cellCentreOfGravity  = c_centre;
}

//------------------------------------------------------------------------------------------------------------------
//The get functions are used to call the private/protected values
//------------------------------------------------------------------------------------------------------------------

char cell :: getCellID()                    {return this-> cellID;}                 // Function to get ID of a cell
char cell :: getCellType()                  {return this-> cellType;}               // Function to get type of a cell
material cell :: getCellMaterial()          {return this-> cellMaterial;}           // Function to get the material of a cell
vector<vector3D> cell :: getPoints()        {return this-> vertices;}               // Function to get the vector points of a cell
float cell :: getCellVolume()               {return this-> cellVolume;}             // Function to get the volume of a cell
float cell :: getCellWeight()               {return this-> cellWeight;}             // Function to get the weight of a cell
vector3D cell :: getCellCentreOfGravity()   {return this-> cellCentreOfGravity;}    // Function to calculate the centre of gravity of a cell


//------------------------------------------------------------------------------------------------------------------
// The accessor/set functions are used to return to the private/protected values
//------------------------------------------------------------------------------------------------------------------

// Function to set the vertex vectors of the cell
void cell :: setPoints(vector<vector3D> theseVertices)  
{
    if (theseVertices.size = 4 || theseVertices.size = 5 || theseVertices.size = 8)
        {
            this-> vertices = theseVertices;
        }
    else
        {
            cout << "Please provide a vector with 4, 5, or 8 elements";
        }
    
}

void cell :: setMaterial(material &thatMaterial)        {this-> cellMaterial = thatMaterial;}   // Function to set the material of the cell


//------------------------------------------------------------------------------------------------------------------
//The calculate functions are used to compute values using generic cell members
//------------------------------------------------------------------------------------------------------------------

void cell :: calculateCellVolume()
{
    cout <<"Base cell currently has no volume, please calculate the volume";

}

void cell :: calculateCellWeight()
{
    this-> cellWeight = this-> getCellMaterial().getDensity() * this-> cellVolume * 9.8;
}

void cell :: calculateCellCentreOfGravity()
{

}

//------------------------------------------------------------------------------------------------------------------
//The specific shape constructor initialisatons and volume functions
//------------------------------------------------------------------------------------------------------------------

// Tetrahedron Initialisation
tetrahedron :: tetrahedron (char t, vector3D point0, vector3D point1, vector3D point2, vector3D point3);
{
    this -> cellType    = t;
    this -> vector0     = point0;
    this -> vector1     = point1;
    this -> vector2     = point2;
    this -> vector3     = point3;

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
hexahedron :: hexahedron (char t, vector3D point0, vector3D point1, vector3D point2, vector3D point3
                            vector3D point4, vector3D point5, vector3D point6, vector3D point7);
{
    this -> cellType = h;
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
    this -> vector4 = point4;
    this -> vector5 = point5;
    this -> vector6 = point6;
    this -> vector7 = point7;


}

// Hexahedron Volume
void hexahedron :: calculateCellVolume()
{

}

// Pyramid Initialisation
pyramid :: pyramid (vector3D point0, vector3D point1, vector3D point2, vector3D point3, vector3D point4);
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