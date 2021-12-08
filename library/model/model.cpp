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
#include <string>
#include "vectors.h"
#include "cell.h"
#include "material.h"
#include "model.h"

model::model()
{

}

model::~model()
{

}

int model::getIdFromString(const string& line, const int& currentChar)
{
	string ID = "";
	
	//Get the ID number by starting from where the first digit of the ID is then iterating until a space is seen
	for (int i = currentChar; line[i] != " "; i++)
	{
		ID = ID + line[i];
		//Add one to currentChar each iteration
		currentChar++;
	}
	return stoi(ID);
}

int model::getIntFromString(const string& line,const int& currentChar)
{
	//This function is used to get an integer from a string if the index of the first character is known 

	int integer;
	string tempString;
	int startChar = currentChar;;


	while (line[currentChar] != ' ')
	{
		//Iterates through the density until there are no more digits
		//The digits are placed into a temporary string then will be converted to integer
		//Starting at tempString[0]
		tempString[currentChar - startChar] = line[currentChar];
		currentChar++;
	}
	//The stoi function converts a c++ string into an integer value
	integer = stoi(tempString);

	currentChar++;

	return integer;
}

float model::getFloatFromString(const string& line, int& startChar)
{
	//This function is used to get a float from a string if the index of the first character is known 

	float floatValue;
	string tempString;
	int startChar = currentChar;;


	while (line[currentChar] != ' ')
	{
		//Iterates through the density until there are no more digits
		//The digits are placed into a temporary string then will be converted to integer
		//Starting at tempString[0]
		tempString[currentChar - startChar] = line[currentChar];
		currentChar++;
	}
	//The stoi function converts a c++ string into an integer value
	floatValue = stoi(tempString);

	currentChar++;

	return floatValue;
}

void model::materialInput(const string& line)
{
	//This method is used to take the input of a line that begins with an m in the datafile
	int ID;
	int density;
	int colour;
	string name = "";

	//currentChar is set to 2 as this is the index of the first digit of the ID
	int currentChar = 2;

	ID = getIdFromString(line, currentChar);

	//Add one to currentChar to skip over the space
	currrentChar++;

	//Get the density from the string
	density = getIntFromString(line, currentChar);

	//Get the colour from the string
	colour = getIntFromString(line, currentChar);

	//Get the name of the material from the string
	for (int i = currentChar; line[i] != ' '; i++)
	{
		name = name + line[i];
		//No need to increase currentChar as no more information is available after the name
	}

	//Give the information to the material constructor
	//The material object made is then placed into the vector at the next position
	if (listOfMaterials.size() = 1)
	{
		//If the vector has a size of 1(the default) then input at the first index
		listOfMaterials[listOfMaterials.size() - 1] = material(ID, density, colour, name);
	}
	else
	{
		//Use the dynamic vector to set to the new size
		listOfMaterials[listOfMaterials.size()] = material(ID, density, colour, name);
	}
}

void model::vectorInput(const string& line)
{
	int ID;
	float xCoord = 0.;
	float yCoord = 0.;
	float zCoord = 0.;

	//currentChar is set to 2 as this is the index of the first digit of the ID
	int currentChar = 2;

	//Use the get id function to get the id integer
	ID = getIdFromString(line, currentChar);



}

void model::analyseLine(const string& line)
//This method analyses the first letter of each line then sends it to a corresponding function based upon what the first letter is
{

	for (char const& character : line)
	{
		if (character == '#') break; //if the character is a # then ignore this line as it is a comment
		else if (character == 'm') //If the character is an m then begin to fill in a material object with the data on this line 
		{
			materialInput(line);
		}
		else if (character == 'v')
		{
			vectorInput(line);
		}
	}

}

void model::readModelFile(const string& filename)
//This method is used to read through the text file given and pass each individual line to the analyseLine method
{
	string line;

	ifstream modelFile(filename);
	modelFile.open(filename);

	if (modelFile.is_open())
	{
		while (getline(modelFile, line))
		{
			//Takes an individual line and passes it to the analyseLine function
			analyseLine(line);
		}
		modelFile.close();
	}

	else cout << "unable to open file:\t" << filename << "\n";

}