

#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

//Header includes all the things that are required to use the source functions

// The primary purpose of a header file is to provide
// forward declarations known throughout the code files.





//-start------------------------------------------------------------------------------------------------------------
// A cell class that stores the blueprint for making a cell
//------------------------------------------------------------------------------------------------------------------
class Cell
{
    // Private => features that define a cell (every cell has to have these no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        int cellID;                     // The unique identifier for the cell
        material cellMaterial;                   // The type of material the cell is made of
        float cellVolume;               // The volume of the cell
        float cellWeight;               // The weight of the cell
        vector cellCentreOfGravity;     // The centre of gravity of the cell

    // Protected => Things that every cell has but varies depending on what type of cell they are
    protected:
        virtual vector pointVector3D[]; // The vectors that define the vertices of the cell

    // Public => Things that can be changed about a cell that enable them to be recognised as unique
    public:
        //The get functions are used to call the private/protected values
        virtual float getPoints();              // function to get the vectors of the vertices of the cell
        virtual float getCellWeight();          // function to get the value of the weight of the cell
        virtual float getCellVolume();          // function to get the value of the volume of the cell
        virtual float getCellCentreOfGravity(); // function to get the vector of the centre of gravity of the cell

        // The set functions are used to return to the private/protected values
        void setPoints(vector &pointVector3D;   // function to set the vectors of the vertices of the cell
        void setMaterial();                     // function to set the material of the cell
        void setCellWeight();                   // function to set the value of the weight of the cell
        void setCellVolume();                   // function to set the value of the volume of the cell
        void setCellCentreOfGravity();          // function to set the vector of the centre of gravity of the cell

};
//-end-------------------------------------------------------------------------------------------------------------

//-start-----------------------------------------------------------------------------------------------------------
// A tetrahedron class that stores the blueprint for making a tetrahedron
// A tetrahedron is derived from a cell
//-----------------------------------------------------------------------------------------------------------------
class tetrahedron : public cell
{
    // Private => Things that define a tetrahedron (every tetrahedron has these this exact way no matter what)
    // The private values are not to be accessed/changed other than by the get and set functions that are provided
    private:
        vector vector0, vector1, vector2, vector3; // Vectors/Point IDs = { , , , } Ordered


    // Public => Things that can be changed about a tetrahedron that enable them to be recognised as unique
    public: // Member variables that can be accessed by other classes
        // Constructor
        tetrahedron (vector3dPoints point0, vector3dPoints point1, vector3dPoints point2, vector3dPoints point3);

        // Destructor
        ~tetrahedron();

        // Set function
        void setPoints (point0, point1, point2, point3);



        // Calculations
            // Call Volume Function
            float getVolume();

            // Call Centre of Gravity Function
            float getCentreOfGravity();
    };


#endif // CELL_HEADER_H_INCLUDED
