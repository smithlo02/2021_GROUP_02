

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <vector>
#include "..\Vector3D\Vector3D2.h"
#include "..\material\material.h"
#include <math.h>

// Header file declares all the things that are required to use the source functions

//-start------------------------------------------------------------------------------------------------------------
// A cell class that stores the blueprint for making a cell
//------------------------------------------------------------------------------------------------------------------
class cell
{
    // Protected => Derived class can access this but outside classes can't
    // access/change these variables (other than by the public get and set functions that are provided)
protected:
    // Fixed values
    char cellID;                            // The unique identifier for the cell
    char cellType;                          // The type of cell it is

    // Variable values
    vector<Vector3D> cellPoints;            // An array of vectors that define the cellPoints of the cell
    material cellMaterial;                  // The type of material the cell is made of
    float cellVolume;                       // The volume value of the cell
    float cellWeight;                       // The weight value of the cell
    Vector3D cellCentreOfGravity;           // The single vector that defines the centre of gravity of the cell

// Public => Things that can be accessed by any other classes and changed. This enables them to be recognised as unique
public:

    // Constructors and Destructor
    cell();
    cell(char cellID, char cellType, vector<Vector3D> cellPoints, material cellMaterial, float cellVolume, float cellWeight,
        Vector3D cellCentreOfGravity);
    ~cell();
    cell(const cell& cellToCopy);// cell copy constructor

    //The get functions are used to call the values of the private/protected members
    char getcellID();
    char getcellType();
    vector<Vector3D> getPoints();
    material getcellMaterial();
    float getcellWeight();
    Vector3D getcellCentreOfGravity();
    float getcellVolume();

    // The set functions are used to return to the private/protected values
    void setcellID(char& thatID);
    void setcellType(char& thatType);
    void setMaterial(material& thatMaterial);           // Function to set the material of the cell
    void setPoints(vector<Vector3D>& thesecellPoints);     // Function to set the vectors of the cellPoints of the cell

    // Functions to manipulate the values of individual points of a cell
    void replace_Point(int thisPosition, Vector3D newPoint);
    void add_Point(Vector3D newPoint);
    void insert_Point(int thisPosition, Vector3D newPoint);

    // Functions that calculate required values based on the values of the cell, and set them
    void calc_cellWeight();
    void calc_cellCentreOfGravity();
    virtual void calc_cellVolume();
};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A tetrahedron class that stores the 'blueprint' for making a tetrahedron
// A tetrahedron is derived from a cell
// Derived class with public inheritance shares all the base class members and functions
//-----------------------------------------------------------------------------------------------------------------
class tetrahedron : public cell
{
protected:
    // Functions with virtual can be overridden by adding there own version into the derived class:
    void calc_cellVolume();

    // Public => Things that can be changed about a tetrahedron that enable them to be recognised as unique
public: // Member variables that can be accessed by any other object

    // Default Constructor and Destructor
    tetrahedron();
    tetrahedron(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3);        // Constructor using individual Vector3D points
    tetrahedron(vector<Vector3D> tetra_points);                                             // Constructor using a vector of Vector3D points
    tetrahedron(const tetrahedron& thisTetrahedron);                                               // Copy constructor.
    ~tetrahedron();                                                                         // Destructor

};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A hexahedron class that stores the 'blueprint' for making a hexahedron
// A hexahedron is derived from a cell
// Derived class with public inheritance shares all the base class members and functions
//-----------------------------------------------------------------------------------------------------------------
class hexahedron : public cell
{
protected:
    // Functions with virtual can be overridden by adding there own version into the derived class:
    void calc_cellVolume();

    // Public => Things that can be changed about a hexahedron that enable them to be recognised as unique
public: // Member variables that can be accessed by any other object

    // Constructor and Destructor
    hexahedron(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3,
        Vector3D point4, Vector3D point5, Vector3D point6, Vector3D point7);
    hexahedron(vector<Vector3D> hexa_points);
    hexahedron(const hexahedron& thisHexahedron);   // tetrahedron copy constructor
    ~hexahedron();
};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A pyramid class that stores the 'blueprint' for making a pyramid
// A pyramid is derived from a cell
// Derived class with public inheritance shares all the base class members and functions
//-----------------------------------------------------------------------------------------------------------------
class pyramid : public cell
{
protected:
    // Functions with virtual can be overridden by adding there own version into the derived class:
    void calc_cellVolume();

    // Public => Things that can be changed about a pyramid that enable them to be recognised as unique
public: // Member variables that can be accessed by any other object

    // Constructor and Destructor
    pyramid(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D point3, Vector3D point4);
    pyramid(vector<Vector3D> pyra_points);
    pyramid(const pyramid& thisPyramid);   // tetrahedron copy constructor.
    ~pyramid();
};
//-end-------------------------------------------------------------------------------------------------------------

#endif // CELL_HEADER_H_INCLUDED
