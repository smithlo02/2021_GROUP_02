#include "material.h" //Adds the header file for this class
#include <iostream>
#include <string>

using namespace std;

//This cpp file contains the c++ code for all of the methods within the materials class including the constructor and destructor
//The arguments passed to the constructor are the ID number(int), density(int), colour(as a hex rgb value of int) and the name of the material(string)
//The only methods within this class are the getters,setters,constructor and destructor
//The getter and setter methods are needed as the attributes of the material are all private and can only be accessed from within the class

//The deconstructor method
material::~material()
{

}

material::material(int& IDGive, int& densityGive, int& colourGive, string& nameGive)
{
	//This is the class constructor which is called to create an object
	this->ID = IDGive;
	this->name = nameGive;
	this->colour = colourGive;
	this->density = densityGive;
}

// Default constructor used when no arguments provided - added by SAM -------------------------------------------------------------------------
material::material() { ID = 0; name = "not chosen"; colour = 0; density = 0; }

//Below are the getter functions which are used to return information about the material

int material::getID()
{
	return this->ID;
}

string material::getName()
{
	return this->name;
}

int material::getColour()
{
	return this->colour;
}

int material::getDensity()
{
	return this->density;
}

//Below are the setter functions which are used to set the values of the attributes of the object

void material::setID(int& IDGive)
{
	this->ID = IDGive;
}

void material::setName(string& nameGive)
{
	this->name = nameGive;
}

void material::setColour(int& colourGive)
{
	this->colour = colourGive;
}

void material::setDensity(int& densityGive)
{
	this->density = densityGive;
}
