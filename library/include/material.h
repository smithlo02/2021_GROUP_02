#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;

/** @file
* The source file containing the material class definitions
*/

/* ~ Material Class ~ */
// Values to store (data type):
// ID ~ is a number value (int)
// Name ~ is a word (string)
// Colour ~ is a number value stored in hexidecimal (string)
// Denisty ~ is a number value (int)
/* ~~~~~~~~~~~~~~~~~~ */
// Define a Material class

class Material
{

// Define the friend functions of the class
// this allows functions access to the private varibles of the class

     friend ostream& operator<<(ostream& os, Material &m);

     friend istream& operator>>(istream& is, Material &m);

// Define the public variables

public:

    // Define a material
    /** Default constructor
    *
    */
    Material();

    // Pass the variables to the defined Material
    /** Constructor with specified data
    * A constructor for a material with data that is already known for the attributes
    */
    Material(int id, string name, string colour, int density) : ID(id), Name(name), Colour(colour), Density(density){};

    /* ~ Functions to get values for a Material ~ */

    // Define function to get the ID of a Material
    // integer as the ID is a numerical value
    // constant as the value shouldnt be changed throught the code/program
    /** Id getter function
    * Gets the ID number of the material as an integer
    */
    int get_ID() const;

    // Define function to get the Name of a Material
    // string as the Name is a alphabetical value
    // constant as the value shouldnt be changed throught the code/program
    /** Material name getter
    * Gets the material name and returns it as a string
    */
    string get_Name() const;

    // Define function to get the Colour of a Material
    // string as the Colour is a alphabetical value as stored in hexidecimal
    // constant as the value shouldnt be changed throught the code/program
    /** Colour getter function
    * Gets the colour of the material which is stored as a string as the actual value is hexidecimal
    */
    string get_Colour() const;

    // Define function to get the Density of a Material
    // integer as the Density is a numerical value
    // constant as the value shouldnt be changed throught the code/program
    /** Density getter function
    * Gets the density of the material as an integer
    */
    int get_Density() const;

    /* ~ Functions to set a new Material ~ */

    // Define function to get a new Material
    // constant as the value shouldnt be changed throught the code/program
    /** Gets a new material
    * A function to get a new material
    */
    Material get_Material()const;

    // Define function to set the ID of a Material
    // integer as the ID is a numerical value
    /** Sets the material ID number
    *
    */
    void set_ID(int &ID);

    // Define function to set the Name of a Material
    // string as the Name is a alphabetical value
    /** Sets the name of the material
    *
    */
    void set_Name(string &Name);

    // Define function to set the Colour of a Material
    // string as the Colour is a alphabetical value as stored in hexidecimal
    /** Sets the colour of the materia
    * The colour of the material is a hexidecimal value written as a string
    */
    void set_Colour(string &Colour);

    // Define function to set the Density of a Material
    // integer as the Density is a numerical value
    /** Sets the density of the maerial
    *
    */
    void set_Density(int &Density);

// Define the private variables

private:

    // Integer to store the ID number
    /** ID number
    * ID number is stroed as an integer
    */
    int ID;

    // String to store the Name
    /** Material name
    * Stored as a string
    */
    string Name;

    //String to store the Colour
    /** Material colour
    * Colour is a hexidecimal value written as a string
    */
    string Colour;

    //Integer to store the Density
    /** Material densitys
    * The density of the material is stored as a string
    */
    int Density;
};

#endif // MATERIAL_H