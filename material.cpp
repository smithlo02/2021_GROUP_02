#include "material.h" //Adds the header file for this class
#include <iostream>
#include <string>

class material 
{
	private:
		int ID;
		string name;
		string colour;
		float density;

		//The private values are not to be accessed other than by the get and set functions that are provided

	public:
		material(int I, string n, string c, float d); //The class constructor
		~material(); //The class destructor

		int getID();
		string getName();
		string getColour();
		float getDensity();
		//The get functions can be called to get and return the private values

		void setID(int I);
		void setName(string n);
		void setColour(string c);
		void setDensity(float d);
		//The set functions are called to set the private values
};

material::material(int I, string n, string c, float d)
{
	this->ID = I;
	this->name = n;
	this->colour = c;
	this->density = d;
}

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