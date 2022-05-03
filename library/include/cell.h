#ifndef CELL_H
#define CELL_H
#include <vector3d.h>
#include <material.h>

/** @file
* The default cell constructor that is the parent class of the tetrahedron, pyramid and hexahedron classes
*
*/

class Cell
{
	friend class Model; //let Model class to access the protected data
	friend class ModelRender;

public:
	/** Cell default constructor
	*
	*/
	Cell(); //default constructor

	/** Gets cell ID
	* Returns the ID number of the cell as an integer
	*/
	int get_cell_ID(); // get the ID of a cell 

	/** Gets the type of the cell
	* Gets the type of the cell as a char that is "t", "p", "h" for tetrahedron, pyramid and hexahedron respectively
	*/
	char get_cell_type(); // get the type of a cell
    
	/** Cell destructor
	* Cell destructor is virtual in case the derived classes object was creating on the heap,if tring to deallocate the memory,then the derived class destructor can be called first.
	*/
	virtual~ Cell(){}; //destructor， make it virtual in case the derived classes object was creating on the heap,if tring to deallocate the memory,then the derived class destructor can be called first.

	/** Gets the cell volume
	* Calculates and returns the volume of the cell as a double
	*/
	virtual double getVolume(); //allow other shape classes to access to the correct getVolume() function

	/** Gets the center of gravity of the cell
	* Calculates the center of gravity of the cell and returns the coordinates of the center as a vector3D point
	*/
	virtual vector3D getCenterOfGravity(); //allow other shape classes to access to the correct getCenterOfGravity() function

	/** Gets the weight of the cell
	* Calculates the weight of the cell using the volume which can be found using the getVolume() function. The weight is returned as a double
	*/
	virtual double getWeight(const double &volume); //allow other shape classes to access to the correct getWeight() function

protected:
	/** The material of the cell
	*
	*/
	Material *M;

	/** The vectors of the cell
	*
	*/
	vector3D *cell_vertices;

	/** The ID number of the cell
	*
	*/
	int *ID;

	/** The type of the cell
	* The type of the cell as a char that is "t", "p", "h" for tetrahedron, pyramid and hexahedron respectively
	*/
	char *Shape;
};

#endif // CELL_H
