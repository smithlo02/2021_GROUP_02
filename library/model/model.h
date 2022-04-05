#pragma once
/** @file
*
*
*This is the header file used to define the model class
*The model class is responsible for reading the model entities from the datafile
*The model class can load multiple cells to create a model
*The model class can also save models to a different datafile and then re load it
*The model class can perfrom the following operations on a model
*	Display the number of vertices in the model
*	Display the number of cells and each type of cell
*	Compute the models centre
*/	

#include <vector>
#include <iostream>
#include <fstream>
#include "..\Vector3D\Vector3D.h"
#include "..\cell\cell.h"
#include "..\material\material.h"

using namespace std;

class model
{
private:
	//The private vector attributes will be used to store all of the different material, vector and cell objects that are read then created from the file

	/** The list of material objects
	* A vector list of materials made using the materials class
	*/
	vector<material> listOfMaterials;

	/** The list of vector objects
	* A vector list of vectors that are made using the Vector3D class
	*/
	vector<vector3D> listOfVectors;

	/** The list of cells
	* A vector list of cells that are made using the cell class
	*/
	vector<cell> listOfCells;

	void analyseLine(const string& line);
	int getIntFromString(const string& line, int& currentChar);
	int getIdFromString(const string& line, int& currentChar);
	float getFloatFromString(const string& line, int& currentChar);
	void cellInput(const string& line);


public:
	model();

	~model();

	void readModelFile(const string& filename);

	void materialInput(const string& line);

	void vectorInput(const string& line);

	material getMaterial(const int& index);

	cell getCell(const int& index);

	vector3D getVector(const int& index);


};