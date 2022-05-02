//This is the ctest file that is used to test the library made in semester 1

#include <model.h>
#include <cell.h>
#include <material.h>

int main()
{
	Model testModel;
	int pass = 1;

	const string fileName = "ExampleModel1.mod";

	testModel.Read_from_A_file(fileName);
	
	pass = 0;

	return(pass == 1) ? 0 : 1;
}