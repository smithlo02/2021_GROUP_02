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
    this->cellID = 0;
    this->cellType = 0;
    this->cellPoints = {};
    this->cellMaterial = {};      // How TF do you set a default material? - Include it in the material header and source files
    this->cellVolume = 0;
    this->cellWeight = 0;
    this->cellCentreOfGravity = {};
}

// Initialise with specified values
cell::cell(char c_ID, char c_type, vector<Vector3D> verts, material c_material, float c_volume,
    float c_weight, Vector3D c_centre)
{
    this->cellID = c_ID;
    this->cellType = c_type;
    this->cellPoints = verts;
    this->cellMaterial = c_material;
    this->cellVolume = c_volume;
    this->cellWeight = c_weight;
    this->cellCentreOfGravity = c_centre;
}

// Copy constructor
cell::cell(const cell& cellToCopy)
{
    this->cellID = cellToCopy.cellID;
    this->cellType = cellToCopy.cellType;
    this->cellPoints = cellToCopy.cellPoints;
    this->cellMaterial = cellToCopy.cellMaterial;
    this->cellVolume = cellToCopy.cellVolume;
    this->cellWeight = cellToCopy.cellWeight;
    this->cellCentreOfGravity = cellToCopy.cellCentreOfGravity;
}

// Destructor
cell::~cell() {}

//------------------------------------------------------------------------------------------------------------------
//The get functions are used to call the private/protected values
//------------------------------------------------------------------------------------------------------------------
char cell::getcellID() { return this->cellID; }                 // Function to get ID of a cell
char cell::getcellType() { return this->cellType; }               // Function to get type of a cell
material cell::getcellMaterial() { return this->cellMaterial; }           // Function to get the material of a cell
vector<Vector3D> cell::getPoints() { return this->cellPoints; }             // Function to get the vector points of a cell
float cell::getcellVolume() { return this->cellVolume; }             // Function to get the volume of a cell
float cell::getcellWeight() { return this->cellWeight; }             // Function to get the weight of a cell
Vector3D cell::getcellCentreOfGravity() { return this->cellCentreOfGravity; }    // Function to calculate the centre of gravity of a cell

//------------------------------------------------------------------------------------------------------------------
// The accessor/set functions are used to return values to the private/protected values
//------------------------------------------------------------------------------------------------------------------
void cell::setcellID(char& thatID) { this->cellID = thatID; }               // Function to set the ID of the cell
void cell::setcellType(char& thatType) { this->cellType = thatType; }           // Function to set the type of cell
void cell::setMaterial(material& thatMaterial) { this->cellMaterial = thatMaterial; }   // Function to set the material of the cell
void cell::setPoints(vector<Vector3D>& thesecellPoints) { this->cellPoints = thesecellPoints; }  // Function to set the vertex vectors of the cell

//------------------------------------------------------------------------------------------------------------------
// Functions to manipulate the values of individual points of a cell
//------------------------------------------------------------------------------------------------------------------
void cell::replace_Point(int thisPosition, Vector3D newPoint) // Replace a single point of a cell with a new one
{
    this->cellPoints.at(thisPosition) = newPoint;
}

void cell::add_Point(Vector3D newPoint) // Add a new point to the end of the cell
{
    this->cellPoints.push_back(newPoint);
}

void cell::insert_Point(int thisPosition, Vector3D newPoint) // Insert a new point between existing cells
{
    if (thisPosition < this->cellPoints.size())
    {
        this->cellPoints.insert(this->cellPoints.begin() + thisPosition, newPoint);
    }
    else
    {
        cout << "Invalid position; the cell is too small" << std::endl;
    }
}

//------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//The calculate functions are used to compute values using generic cell members
//------------------------------------------------------------------------------------------------------------------

void cell::calc_cellVolume()
{
    // IDK what to do with this, seeing as it is a virtual function

    // I guess you could ask what cell type it is and then choose the operation from there?:
    /*
    if(this-> cellType = t)
    {
        tetrahedron.calc_cellvolume;
    }
    else if(this-> cellType = p)
    {
        pyramid.calc_cellvolume;
    }
    else if(this-> cellType = h)
    {
        hexahedron.calc_cellvolume;
    }

    But tbh I don't think this would work.
    */

    cout << "I don't really know how to do that tbh." << std::endl;

}

void cell::calc_cellWeight()
{
    this->cellWeight = cellMaterial.getDensity() * getcellVolume() * 9.8;
}

void cell::calc_cellCentreOfGravity()
{
    Vector3D sumOfPoints;   // To hold the sum of all the x, y and z values of each point
    int i = 0;              // Loop Counter

    for (i = 0; i < this->cellPoints.size(); i++)
    {
        sumOfPoints = sumOfPoints + this->cellPoints.at(i);    // The current sum of the points is the total sum + the points at this position (i)
    }

    sumOfPoints.setx((sumOfPoints.getx() / cellPoints.size())); // Divide the x value by the total number of points in the shape
    sumOfPoints.sety((sumOfPoints.gety() / cellPoints.size())); // Divide the y value by the total number of points in the shape
    sumOfPoints.setz((sumOfPoints.getz() / cellPoints.size())); // Divide the z value by the total number of points in the shape


    this->cellCentreOfGravity = sumOfPoints;
}


//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//The specific derived cell constructor initialisatons and volume functions
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
// For Tetrahedrons
//------------------------------------------------------------------------------------------------------------------

// Tetrahedron Initialisation - Constructor using individual Vector3D points
tetrahedron::tetrahedron(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3) : cell()
{
    //char t;
    //this->cellType = t;

    this->cellPoints.at(0) = point0;
    this->cellPoints.at(1) = point1;
    this->cellPoints.at(2) = point2;
    this->cellPoints.at(3) = point3;
}

// Tetrahedron Initialisation - Vector of Vector3D Points   // (Is this necessary if cell can already do it?)
tetrahedron::tetrahedron(vector<Vector3D> tetra_points) : cell()
{
    for (int i = 0; i < tetra_points.size(); i++)
    {
        this->cellPoints.at(i) = tetra_points.at(i);
    }
}

// Tetrahedron Initialisation - Tetrahedron Copy Constructor    // (Is this necessary if cell can already do it?)
tetrahedron::tetrahedron(const tetrahedron& thisTetrahedron) : cell()
{
    for (int i = 0; i < thisTetrahedron.cellPoints.size(); i++)
    {
        this->cellPoints.at(i) = thisTetrahedron.cellPoints.at(i);
    }
}

// Tetrahedron Volume Calculation
void tetrahedron::calc_cellVolume()
{
    // Vector calculation to find the volume of a tetrahedron
    this->cellVolume = 1 / 6 *
        abs((this->cellPoints.at(0) - this->cellPoints.at(3)) *
            ((this->cellPoints.at(1) - this->cellPoints.at(3)) ^
                (this->cellPoints.at(2) - this->cellPoints.at(3))));


}

tetrahedron::~tetrahedron() {}

//------------------------------------------------------------------------------------------------------------------
// For Hexahedrons
//------------------------------------------------------------------------------------------------------------------

// Hexahedron Initialisation - Constructor using individual Vector3D points
hexahedron::hexahedron(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3,
    Vector3D point4, Vector3D point5, Vector3D point6, Vector3D point7) : cell()
{
    //char h;
    //this->cellType = h;

    this->cellPoints.at(0) = point0;
    this->cellPoints.at(1) = point1;
    this->cellPoints.at(2) = point2;
    this->cellPoints.at(3) = point3;
    this->cellPoints.at(4) = point4;
    this->cellPoints.at(5) = point5;
    this->cellPoints.at(6) = point6;
    this->cellPoints.at(7) = point7;
}

// Hexahedron Initialisation - Vector of Vector3D Points    // (Is this necessary if cell can already do it?)
hexahedron::hexahedron(vector<Vector3D> hexa_points) : cell()
{
    cellPoints = hexa_points;
}

// Hexahedron Initialisation - Hexahedron Copy Constructor  // (Is this necessary if cell can already do it?)
hexahedron::hexahedron(const hexahedron& thisHexahedron) : cell()
{
    for (int i = 0; i < thisHexahedron.cellPoints.size(); i++)
    {
        this->cellPoints.at(i) = thisHexahedron.cellPoints.at(i);
    }
}

hexahedron::~hexahedron() {}

// Hexahedron Volume - A Hexahedron is essentially made up of six Tetrahedrons,
// so we do six volume calculations and add them together
void hexahedron::calc_cellVolume()
{
    // Initialise the different Tetrahedrons
    double tetra_volA = 0, tetra_volB = 0, tetra_volC = 0, tetra_volD = 0, tetra_volE = 0, tetra_volF = 0;

    // Vector calculations to find the volumes of the tetrahedrons
    tetra_volA = 1 / 6 * abs((this->cellPoints.at(0) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(1) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(2) - this->cellPoints.at(5))));  // Tetrahedron A Volume

    tetra_volB = 1 / 6 * abs((this->cellPoints.at(2) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(3) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(6) - this->cellPoints.at(5))));   // Tetrahedron B Volume

    tetra_volC = 1 / 6 * abs((this->cellPoints.at(3) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(6) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(7) - this->cellPoints.at(5))));   // Tetrahedron C Volume

    tetra_volD = 1 / 6 * abs((this->cellPoints.at(0) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(2) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(3) - this->cellPoints.at(5))));   // Tetrahedron D Volume

    tetra_volE = 1 / 6 * abs((this->cellPoints.at(3) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(4) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(7) - this->cellPoints.at(5))));   // Tetrahedron E Volume

    tetra_volF = 1 / 6 * abs((this->cellPoints.at(0) - this->cellPoints.at(5)) *
        ((this->cellPoints.at(3) - this->cellPoints.at(5)) ^
            (this->cellPoints.at(4) - this->cellPoints.at(5))));   // Tetrahedron F Volume


// Total Hexahedron Volume = Sum of Tetrahedrons
    this->cellVolume = tetra_volA + tetra_volB + tetra_volC + tetra_volD + tetra_volE + tetra_volF;
}

//------------------------------------------------------------------------------------------------------------------
// For Pyramids
//------------------------------------------------------------------------------------------------------------------

// Pyramid Initialisation - Constructor using individual Vector3D points
pyramid::pyramid(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3, Vector3D point4) : cell()
{
    //char p;
    //this->cellType = p;

    this->cellPoints.at(0) = point0;
    this->cellPoints.at(1) = point1;
    this->cellPoints.at(2) = point2;
    this->cellPoints.at(3) = point3;
    this->cellPoints.at(4) = point4;
}

// Pyramid Initialisation - Vector of Vector3D Points    // (Is this necessary if cell can already do it?)
pyramid::pyramid(vector<Vector3D> pyra_points) : cell()
{
    for (int i = 0; i < pyra_points.size(); i++)
    {
        this->cellPoints.at(i) = pyra_points.at(i);
    }
}

pyramid::~pyramid() {}

// Pyramid Initialisation - Pyramid Copy Constructor  // (Is this necessary if cell can already do it?)
pyramid::pyramid(const pyramid& thisPyramid) : cell()
{
    for (int i = 0; i < thisPyramid.cellPoints.size(); i++)
    {
        this->cellPoints.at(i) = thisPyramid.cellPoints.at(i);
    }
}

// Pyramid Volume
// A Hexahedron is essentially made up of two Tetrahedrons, so we do six volume calculations and add them together
void pyramid::calc_cellVolume()
{
    // Initialise the different Tetrahedrons
    double tetra_volA = 0, tetra_volB = 0;

    // Vector calculations to find the volumes of the tetrahedrons
    tetra_volA = 1 / 6 * abs((this->cellPoints.at(0) - this->cellPoints.at(4)) *
        ((this->cellPoints.at(1) - this->cellPoints.at(4)) ^
            (this->cellPoints.at(2) - this->cellPoints.at(4))));  // Tetrahedron A Volume

    tetra_volB = 1 / 6 * abs((this->cellPoints.at(0) - this->cellPoints.at(4)) *
        ((this->cellPoints.at(2) - this->cellPoints.at(4)) ^
            (this->cellPoints.at(3) - this->cellPoints.at(4))));   // Tetrahedron B Volume


// Total Pyramid Volume = Sum of Tetrahedrons
    this->cellVolume = tetra_volA + tetra_volB;
}
