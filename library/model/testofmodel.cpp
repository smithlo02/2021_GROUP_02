//This file contains the code required to create a model object and read information from a model file into this object

#include <iostream>
#include <string>
#include "model.h"

int main()
{
    std::cout << "Hello World!\n";

    string filename = "testinput.txt";
    model model1;
    model1.readModelFile(filename);

    //cout << "material info\t" << model1.getMaterial(0).getName();
}