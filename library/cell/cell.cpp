#include <iostream>
#include <cmath>

// Include all the required header files for the project to ensure that the code works properly
#include "cell.h"

//------------------------------------------------------------------------------------------------------------------
//The constructors are used to initialise the member variables
//------------------------------------------------------------------------------------------------------------------

// Initialise with 0's (default)
cell::cell()
{
    this-> cellID               = 0;
    this-> cellType             = 0;
    this-> cellPoints           = {};
    this-> cellMaterial         = {};
    this-> cellVolume           = 0;
    this-> cellWeight           = 0;
    this-> cellCentreOfGravity  = {};
}

// Initialise with specified values
cell::cell (char c_ID, char c_type, vector<vector3D> verts, material c_material, float c_volume, float c_weight,
            vector3D c_centre)
{
    this-> cellID               = c_ID;
    this-> cellType             = c_type;
    this-> cellPoints           = verts;
    this-> cellMaterial         = c_material;
    this-> cellVolume           = c_volume;
    this-> cellWeight           = c_weight;
    this-> cellCentreOfGravity  = c_centre;
}

//------------------------------------------------------------------------------------------------------------------
// Copy constructor
//------------------------------------------------------------------------------------------------------------------
cell::cell(const cell &cellToCopy)
{
    this-> cellID               = cellToCopy.cellID;
    this-> cellType             = cellToCopy.cellType;
    this-> cellPoints           = cellToCopy.cellPoints;
    this-> cellMaterial         = cellToCopy.cellMaterial;
    this-> cellVolume           = cellToCopy.cellVolume;
    this-> cellWeight           = cellToCopy.cellWeight;
    this-> cellCentreOfGravity  = cellToCopy.cellCentreOfGravity;
}

//------------------------------------------------------------------------------------------------------------------
// Destructor
//------------------------------------------------------------------------------------------------------------------
cell::~cell(){}

//------------------------------------------------------------------------------------------------------------------
//The get functions are used to call the private/protected values
//------------------------------------------------------------------------------------------------------------------

char cell :: getcellID()                    {return this-> cellID;}                 // Function to get ID of a cell
char cell :: getcellType()                  {return this-> cellType;}               // Function to get type of a cell
material cell :: getcellMaterial()          {return this-> cellMaterial;}           // Function to get the material of a cell
vector<vector3D> cell :: getPoints()        {return this-> cellPoints;}             // Function to get the vector points of a cell
float cell :: getcellVolume()               {return this-> cellVolume;}             // Function to get the volume of a cell
float cell :: getcellWeight()               {return this-> cellWeight;}             // Function to get the weight of a cell
vector3D cell :: getcellCentreOfGravity()   {return this-> cellCentreOfGravity;}    // Function to calculate the centre of gravity of a cell


//------------------------------------------------------------------------------------------------------------------
// The accessor/set functions are used to return values to the private/protected values
//------------------------------------------------------------------------------------------------------------------

// Function to set the vertex vectors of the cell
void cell :: setPoints(vector<vector3D> thesecellPoints)  
{
    if (thesecellPoints.size == 4 || thesecellPoints.size == 5 || thesecellPoints.size == 8)
        {
            this-> cellPoints = thesecellPoints;
        }
    else
        {
            cout<<"Invalid index range"<<std::endl;
        }
    
}

void cell :: setMaterial(material &thatMaterial)        {this-> cellMaterial = thatMaterial;}   // Function to set the material of the cell


//------------------------------------------------------------------------------------------------------------------
// Functions to manipulate the values of individual points of a cell
//------------------------------------------------------------------------------------------------------------------
void cell::replace_Point(int thisPosition, vector3D newPoint)
{
  this-> cellPoints.at(thisPosition) = newPoint;
}

void cell::add_Point(vector3D newPoint)
{
  this-> cellPoints.push_back(newPoint);
}

void cell::insert_Point(int thisPosition, vector3D newPoint)
{
  if(thisPosition < this-> cellPoints.size())
    {
        this-> cellPoints.insert(this-> cellPoints.begin() + thisPosition, newPoint);
	}
    else    
    {
        cout<<"Invalid position; the cell is too small"<<std::endl;
	}
}

//------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//The calculate functions are used to compute values using generic cell members
//------------------------------------------------------------------------------------------------------------------

void cell :: calc_cellVolume()
{

}

void cell :: calc_cellWeight()
{
    this-> cellWeight = cellMaterial.getDensity() * this-> cellVolume * 9.8;
}

void cell :: calc_cellCentreOfGravity()
{
    vector3D sumOfPoints; // To hold values of sum of all points' x, y and z values

    for(int i = 0; i < this-> cellPoints.size(); i++)
    {
        sumOfPoints += this-> cellPoints.at(i);
    }
    this-> cellCentreOfGravity = sumOfPoints / cellPoints.size;
}

//------------------------------------------------------------------------------------------------------------------
//The specific shape constructor initialisatons and volume functions
//------------------------------------------------------------------------------------------------------------------

// Tetrahedron Initialisation - Individual Points
tetrahedron :: tetrahedron (vector3D point0, vector3D point1, vector3D point2, vector3D point3);
{
    this-> cellType    = t;

    this-> cellPoints.at(0) = point0;
    this-> cellPoints.at(1) = point1;
    this-> cellPoints.at(2) = point2;
    this-> cellPoints.at(3) = point3;
}

// Tetrahedron Initialisation - Vector of Points
tetrahedron :: tetrahedron (vector<vector3D> tetra_points)
{
    for (int i = 0; i < tetra_points.size; i++)
    {
        this-> cellPoints.at(i) = tetra_points.at(i);
    }
}

// Tetrahedron Volume Calculation
void tetrahedron :: calc_cellVolume()
{
    // Vector calculation to find the volume of a tetrahedron
    this-> cellVolume = 1/6 *
                        abs (( this-> vector0 - this-> vector3)  *
                            (( this-> vector1 - this-> vector3)  ^
                             ( this-> vector2 - this-> vector3)));
    

}

// Hexahedron Initialisation - individual points
hexahedron :: hexahedron (vector3D point0, vector3D point1, vector3D point2, vector3D point3
                          vector3D point4, vector3D point5, vector3D point6, vector3D point7);
{
    this-> cellType = h;
    this-> vector0 = point0;
    this-> vector1 = point1;
    this-> vector2 = point2;
    this-> vector3 = point3;
    this-> vector4 = point4;
    this-> vector5 = point5;
    this-> vector6 = point6;
    this-> vector7 = point7;
}

// Hexahedron Initialisation 2 - vector of points
hexahedron :: hexahedron (vector<vector3D> hex_points);
{
    for (int i = 0; i < hex_points.size; i++)
    {
        this-> cellPoints.at(i) = hex_points.at(i);
    }
}

// Hexahedron Volume
// A Hexahedron is essentially made up of six Tetrahedrons, so we do six volume calculations and add them together
void hexahedron :: calc_cellVolume()
{
    // Initialise the different Tetrahedrons
    double tetra_volA = 0, tetra_volB = 0, tetra_volC = 0, tetra_volD = 0, tetra_volE = 0, tetra_volF = 0;

    // Vector calculations to find the volumes of the tetrahedrons
    tetra_volA = 1/6 * abs (( this-> vector0 - this-> vector5)  *
                           (( this-> vector1 - this-> vector5)  ^
                            ( this-> vector2 - this-> vector5)));   // Tetrahedron A Volume

    tetra_volB = 1/6 * abs (( this-> vector2 - this-> vector5)  *
                           (( this-> vector3 - this-> vector5)  ^
                            ( this-> vector6 - this-> vector5)));   // Tetrahedron B Volume

    tetra_volC = 1/6 * abs (( this-> vector3 - this-> vector5)  *
                           (( this-> vector6 - this-> vector5)  ^
                            ( this-> vector7 - this-> vector5)));   // Tetrahedron C Volume

    tetra_volD = 1/6 * abs (( this-> vector0 - this-> vector5)  *
                           (( this-> vector2 - this-> vector5)  ^
                            ( this-> vector3 - this-> vector5)));   // Tetrahedron D Volume

    tetra_volE = 1/6 * abs (( this-> vector3 - this-> vector5)  *
                           (( this-> vector4 - this-> vector5)  ^
                            ( this-> vector7 - this-> vector5)));   // Tetrahedron E Volume

    tetra_volF = 1/6 * abs (( this-> vector0 - this-> vector5)  *
                           (( this-> vector3 - this-> vector5)  ^
                            ( this-> vector4 - this-> vector5)));   // Tetrahedron F Volume


    // Total Hexahedron Volume = Sum of Tetrahedrons
    this-> cellVolume = tetra_volA + tetra_volB + tetra_volC + tetra_volD + tetra_volE + tetra_volF;
}

// Pyramid Initialisation
pyramid :: pyramid (vector3D point0, vector3D point1, vector3D point2, vector3D point3, vector3D point4);
{
    this -> cellType = p;
    this -> vector0 = point0;
    this -> vector1 = point1;
    this -> vector2 = point2;
    this -> vector3 = point3;
    this -> vector3 = point4;
}

// Pyramid Volume
// A Hexahedron is essentially made up of two Tetrahedrons, so we do six volume calculations and add them together
void pyramid :: calc_cellVolume(vector<vector3D> vectors)
{
    // Initialise the different Tetrahedrons
    double tetra_volA = 0, tetra_volB = 0;

     // Vector calculations to find the volumes of the tetrahedrons
    tetra_volA = 1/6 * abs (( this-> vector0 - this-> vector4)  *
                           (( this-> vector1 - this-> vector4)  ^
                            ( this-> vector2 - this-> vector4)));   // Tetrahedron A Volume

    tetra_volB = 1/6 * abs (( this-> vector0 - this-> vector4)  *
                           (( this-> vector2 - this-> vector4)  ^
                            ( this-> vector3 - this-> vector4)));   // Tetrahedron B Volume

    // Total Pyramid Volume = Sum of Tetrahedrons
    this-> cellVolume = tetra_volA + tetra_volB;
}