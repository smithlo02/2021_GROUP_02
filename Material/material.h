#include <string>

using namespace std;

//This header file declares the class material
//The material class has 4 attributes, ID(int), density(int), colour(int as hex value) and name(string)
//All of the attributes are private so cannot be accessed by any functions outside of the class
//The getters and setters are used to read and write to these values respectively

class material
{
private:
	int ID;
	string name;
	int colour;
	int density;

	//The private values are not to be accessed other than by the get and set functions that are provided

public:
	//Everything under public: is able to be used by other parts of code outside of the class.

	material(int I, int d, int c, string n); //The class constructor
	~material(); //The class destructor

	int getID();
	string getName();
	int getColour();
	int getDensity();
	//The get functions can be called to get and return the private values

	void setID(int I);
	void setName(string n);
	void setColour(int c);
	void setDensity(int d);
	//The set functions are called to set the private values
};