#include "material.h" //Adds the header file for this class
#include <iostream>
#include <string.h>



material::material(int I, string n, string c, float d)
{
	//This is the class constructor which is called to create an object
	this->ID = I;
	this->name = n;
	this->colour = c;
	this->density = d;
}

//Below are the getter functions which are used to return information about the material

int material::getID()
{
	int ID;
	return this->ID;
}

string material::getName()
{
	string name;
	return this->name;
}

string material::getColour()
{
	string colour;
	return this->colour;
}

float material::getDensity()
{
	float density;
	return this->density;
}

//Below are the setter functions which are used to set the values of the attributes of the object

void material::setID(int I)
{
	this->ID = I;
}

void material::setName(string n)
{
	this->name = n;
}

void material::setColour(string c)
{
	this->colour = c;
}

void material::setDensity(int d)
{
	this->density = d;
}