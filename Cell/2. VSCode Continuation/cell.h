

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <vector>
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
        vector<pointVector3D> vertices;         // An array of vectors that define the vertices of the cell
        material cellMaterial;                  // The type of material the cell is made of
        float cellVolume;                       // The volume value of the cell
        float cellWeight;                       // The weight value of the cell
        pointVector3D cellCentreOfGravity;      // The single vector that defines the centre of gravity of the cell

        //Functions that calculate required values based on the values of the cell
        void calculateCellWeight();
        void calculateCellCentreOfGravity();
        virtual void calculateCellVolume();

    // Public => Things that can be accessed by any other classes and changed. This enables them to be recognised as unique
    public:

        // Constructor and Destructor
        cell(char cellID, char ID, material cellMaterial, float cellVolume, float cellWeight,
             pointVector3D cellCentreOfGravity, vector<pointVector3D> vertices);
        ~cell();

        //The get functions are used to call the values of the private/protected members
        char getCellID();
        char getCellType();
        vector<pointVector3D> getPoints();      
        material getCellMaterial();
        float getCellWeight();                  
        pointVector3D getCellCentreOfGravity(); 
        float getCellVolume();                  
        
        // The set functions are used to return to the private/protected values
        void setMaterial(material &thatMaterial);                     // function to set the material of the cell
        void setPoints(vector<pointVector3D> theseVertices);                       // function to set the vectors of the vertices of the cell
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
        // Functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellVolume();

    // Public => Things that can be changed about a tetrahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        tetrahedron (pointVector3D vector0, pointVector3D vector1, pointVector3D vector2, pointVector3D vector3);
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
        // Functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellVolume();

    // Public => Things that can be changed about a hexahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        hexahedron (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3,
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
         // Functions with virtual can be overridden by adding there own version into the derived class:
        void calculateCellVolume();

    // Public => Things that can be changed about a pyramid that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        pyramid (pointVector3D point0, pointVector3D point1, pointVector3D point2, pointVector3D point3, pointVector3D point4);
        ~pyramid();

};
//-end-------------------------------------------------------------------------------------------------------------

#endif // CELL_HEADER_H_INCLUDED
