//This is the c++ file used to define the model class
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

void readModelFile(string filename)
{
	ofstream modelFile;
	modelFile.open(filename);


}