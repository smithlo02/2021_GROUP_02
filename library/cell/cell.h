

#ifndef cELL_H_INCLUDED
#define cELL_H_INCLUDED

#include <vector>
#include "vector3D.h"
#include "material.h"
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
        vector<vector3D> cellPoints;            // An array of vectors that define the cellPoints of the cell
        material cellMaterial;                  // The type of material the cell is made of
        float cellVolume;                       // The volume value of the cell
        float cellWeight;                       // The weight value of the cell
        vector3D cellCentreOfGravity;           // The single vector that defines the centre of gravity of the cell
        
    // Public => Things that can be accessed by any other classes and changed. This enables them to be recognised as unique
    public:

        // Constructors and Destructor
        cell();
        cell(char cellID, char cellType, vector<vector3D> cellPoints, material cellMaterial, float cellVolume, float cellWeight,
             vector3D cellCentreOfGravity);
        ~cell();
        cell(const cell&);// cell copy constructor

        //The get functions are used to call the values of the private/protected members
        char getcellID();
        char getcellType();
        vector<vector3D> getPoints();      
        material getcellMaterial();
        float getcellWeight();                  
        vector3D getcellCentreOfGravity(); 
        float getcellVolume();                  
        
        // The set functions are used to return to the private/protected values
        void setcellID(char);
        void setcellType(char);
        void setPoints(vector<vector3D> thesecellPoints);     // Function to set the vectors of the cellPoints of the cell
        void setMaterial(material &thatMaterial);           // Function to set the material of the cell

        // Functions to manipulate the values of individual points of a cell
        void replace_Point(int thisPosition, vector3D newPoint);
        void add_Point(vector3D newPoint);
        void insert_Point(int thisPosition, vector3D newPoint);

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
    // Private => Things that define a tetrahedron (every tetrahedron has these this exact way no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        // Functions with virtual can be overridden by adding there own version into the derived class:
        void calc_cellVolume();

    // Public => Things that can be changed about a tetrahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Default Constructor and Destructor
        tetrahedron(vector3D vector0, vector3D vector1, vector3D vector2, vector3D vector3);
        tetrahedron(vector<vector3D> tetra_points);
        ~tetrahedron();
        tetrahedron(const cell&);   // tetrahedron copy constructor.

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
        void calc_cellVolume();

    // Public => Things that can be changed about a hexahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        hexahedron (vector3D point0, vector3D point1, vector3D point2, vector3D point3,
                    vector3D point4, vector3D point5, vector3D point6, vector3D point7);
        ~hexahedron();
        hexahedron(const cell&);   // tetrahedron copy constructor
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
        void calc_cellVolume();

    // Public => Things that can be changed about a pyramid that enable them to be recognised as unique
    public: // Member variables that can be accessed by any other object

        // Constructor and Destructor
        pyramid (vector3D point0, vector3D point1, vector3D point2, vector3D point3, vector3D point4);
        ~pyramid();
        pyramid(const cell&);   // tetrahedron copy constructor.
};
//-end-------------------------------------------------------------------------------------------------------------

#endif // cELL_HEADER_H_INCLUDED
