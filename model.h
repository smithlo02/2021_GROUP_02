#pragma once
//This is the header file used to define the model class
//The model class is responsible for reading the model entities from the datafile
//The model class can load multiple cells to create a model
//The model class can also save models to a different datafile and then re load it
//The model class can perfrom the following operations on a model
	//Display the number of vertices in the model
	//Display the number of cells and each type of cell
	//Compute the models centre

#include <vector>
#include <iostream>
#include <fstream>
#include "vectors.h"
#include "cell.h"
#include "material.h"


using namespace std;

class model
{
private:
	//The private vector attributes will be used to store all of the different material, vector and cell objects that are read then created from the file
	vector<material> listOfMaterials;
	vector<vectors> listOfVectors;
	vector<cell> listOfCells;

	void analyseLine(const string &line);
	int getIntFromString(const string& line, int& startChar);

public:
	model();

	~model();

	void readModelFile(const string &filename);

	void materialInput(const string& line);


};