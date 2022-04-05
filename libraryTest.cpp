//This is the ctest file that is used to test the library made in semester 1

#include "/library/model.h"

int main()
{
	model testModel();
	int pass = 1;

	const string fileName = "ExampleModel1.mod";

	testModel.readModelFile(filename);

	if (testModel.getMaterial(0) =! material(0, 8960, 0xb87333, "aluminium");
		pass = 0;

	return(pass == 1) ? 0 : 1;
}