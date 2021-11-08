class material
{
private:
	int ID;
	string name;
	string colour;
	float density;

	//The private values are not to be accessed other than by the get and set functions that are provided

public:
	material(int I, string n, string c, float d); //The class constructor
	~material(); //The class destructor

	int getID();
	string getName();
	string getColour();
	float getDensity();
	//The get functions can be called to get and return the private values

	void setID(int I);
	void setName(string n);
	void setColour(string c);
	void setDensity(float d);
	//The set functions are called to set the private values
};