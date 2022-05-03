#include <string>
#include "material.h"
#include "iostream"

//This program is designed to test class 3 the class for materials
//It starts by creating a material, copper, with multiple issues
//The get functions are then tested and then the returned values are outputted
//The set functions are then used to change the values
//The new correct values are then output to test the setter values

using namespace std;

int main() {

	
	//The colour is stored as a hex value indicated by the "0x" before the hex value
	material copper(1, 9000, 0xb87337, "Cooper");
	int ID = copper.getID();
	int density = copper.getDensity();
	int colour = copper.getColour();
	string name = copper.getName();

	//As colour is stored as a hex value the programis told to output hex values for integers before the colour is output It is then told to return to dec afterwards
	cout << "ID " << ID << "\tName " << name << "\tdensity " << density << "\tcolour " << hex << colour << dec << "\n";

	//Setting copper to the correct values
	copper.setID(0);
	copper.setDensity(8960);
	copper.setColour(0xb87373);
	copper.setName("Copper");

	//getting the new values to check them
	ID = copper.getID();
	density = copper.getDensity();
	colour = copper.getColour();
	name = copper.getName();
	
	cout << "ID " << ID << "\tName " << name << "\tdensity " << density << "\tcolour " << hex << colour << dec <<"\n";
}
