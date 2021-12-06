

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include "Vector3D2.h"
#include "material.h"

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
        material cellMaterial;                  // The type of material the cell is made of
        float cellVolume;                       // The volume value of the cell
        float cellWeight;                       // The weight value of the cell
        pointVector3D cellCentreOfGravity;      // The single vector that defines the centre of gravity of the cell
        virtual pointVector3D pointVector3D[];  // An array of vectors that define the vertices of the cell

        //Functions that calculate required values based on the values of the cell
        void calculateCellWeight();
        virtual void calculateCellCentreOfGravity();
        virtual void calculateCellVolume();

    // Public => Things that can be accessed by any other classes and changed. This enables them to be recognised as unique
    public:

        // Constructor and Destructor
        cell(int c_ID, material c_material, float c_volume, float c_weight, pointVector3D c_centre, pointVector3D p_Vector);
        ~cell();

        //The get functions are used to call the private/protected values
        char getCellID();
        char getCellType();
        material getCellMaterial();
        float getPoints();                      // function to get the vectors of the vertices of the cell
        float getCellWeight();                  // function to get the value of the weight of the cell
        pointVector3D getCellCentreOfGravity(); // function to get the vector of the centre of gravity of the cell
        float getCellVolume();                  // function to get the value of the volume of the cell
        
        // The set functions are used to return to the private/protected values
        void setMaterial();                     // function to set the material of the cell
        void setPoints();                       // function to set the vectors of the vertices of the cell
                                                // Do we need a set function for the ID?
        

};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A tetrahedron class that stores the 'blueprint' for making a tetrahedron
// A tetrahedron is derived from a cell
// Derived class with public inheritance shares all the base class members and functions
//-----------------------------------------------------------------------------------------------------------------
class tetrahedron : public cell
{
    // Private => Things that define a tetrahedron (every tetrahedron has these this exact way no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        pointVector3D[4] = {vector0, vector1, vector2, vector3}; // Vectors/Point IDs = { , , , } Ordered
        cellType = t;

        // However functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellCentreOfGravity();
        void calculateCellVolume();

    // Public => Things that can be changed about a tetrahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        tetrahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3);
        ~tetrahedron();

};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A hexahedron class that stores the 'blueprint' for making a hexahedron
// A hexahedron is derived from a cell
// Derived class with public inheritance shares all the base class members and functions
//-----------------------------------------------------------------------------------------------------------------
class hexahedron : public cell
{
    // Private => Things that define a hexahedron (every hexahedron has these this exact way no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        pointVector3D[4] = {vector0, vector1, vector2, vector3, vector4, vector5, vector6, vector7}; // Vectors/Point IDs = { , , , } Ordered
        cellType = h;

        // However functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellCentreOfGravity();
        void calculateCellVolume();

    // Public => Things that can be changed about a hexahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        hexahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3
                    pointVector3D point4, pointVector3D point5, pointVector3D point6, pointVector3D point7);
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
    // Private => Things that define a pyramid (every pyramid has these this exact way no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        pointVector3D[4] = {vector0, vector1, vector2, vector3, vector4}; // Vectors/Point IDs = { , , , } Ordered
        cellType = p;

        // However functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellCentreOfGravity();
        void calculateCellVolume();

    // Public => Things that can be changed about a pyramid that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        pyramid (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3, pointVector3D point4);
        ~pyramid();

};
//-end-------------------------------------------------------------------------------------------------------------

#endif // CELL_HEADER_H_INCLUDED
