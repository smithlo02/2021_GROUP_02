#ifndef CELL_H
#define CELL_H
#include <vector3d.h>
#include <material.h>

class Cell
{
	friend class Model; //let Model class to access the protected data
	friend class ModelRender;

public:
	Cell(); //default constructor

	int get_cell_ID(); // get the ID of a cell 

	char get_cell_type(); // get the type of a cell
    
	virtual~ Cell(){}; //destructor， make it virtual in case the derived classes object was creating on the heap,if tring to deallocate the memory,then the derived class destructor can be called first.

	virtual double getVolume(); //allow other shape classes to access to the correct getVolume() function

	virtual vector3D getCenterOfGravity(); //allow other shape classes to access to the correct getCenterOfGravity() function

	virtual double getWeight(const double &volume); //allow other shape classes to access to the correct getWeight() function

protected:
	Material *M;
	vector3D *cell_vertices;
	int *ID;
	char *Shape;
};

#endif // CELL_H
