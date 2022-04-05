//This is the ctest file that is used to test the library made in semester 1

#include "model/model.h"

int main()
{
	model testModel;
	int pass = 1;

	const string fileName = "ExampleModel1.mod";

	testModel.readModelFile(fileName);
	material testMaterial = testModel.getMaterial(0);

	if ((testMaterial.getColour() != 0xb87333) || (testMaterial.getDensity() != 8960) || (testMaterial.getID() != 0) || (testMaterial.getName() != "copper"))
		pass = 0;

	return(pass == 1) ? 0 : 1;
}