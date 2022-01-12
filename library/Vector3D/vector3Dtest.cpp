//vector3Dtest.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Vector3D.h"

using namespace std;

int main(int argc, char *argv[])
{
// -------------------------------------------------------------------------------------
// Vector3D class test
// -------------------------------------------------------------------------------------
std::cout<<"Vector3D Class Test"<<std::endl;
std::cout<<""<<std::endl;
	
int errors = 0;
// -------------------------------------------------------------------------------------
// define vector coordinates.
// -------------------------------------------------------------------------------------
Vector3D vector1(1.0,2.0,3.0);
Vector3D vector2(3.0,2.0,1.0);
// -------------------------------------------------------------------------------------
// Set vector ID
// -------------------------------------------------------------------------------------
vector1.setID(1);
vector2.setID(2);
// -------------------------------------------------------------------------------------	
//check ID if ID does not match, errors will be counted.
// -------------------------------------------------------------------------------------
std::cout<<"ID"<<std::endl;
	
if(vector1.getID()!=1||vector2.getID()!=2)
{
        errors++;
}
std::cout<<"--expected value: vector1 = 1, vector2 = 2"<<std::endl;
std::cout<<"--test results: vector1 = "<<vector1.getID()<<", vector2 = "<<vector2.getID()<<std::endl;
std::cout<<"--errors count: "<<errors<<std::endl;
std::cout<<""<<std::endl;
// -------------------------------------------------------------------------------------	
//Test Addition functions
// -------------------------------------------------------------------------------------
std::cout<<"Addition"<<std::endl;
// -------------------------------------------------------------------------------------
Vector3D vectorA = vector1 + vector2;
// -------------------------------------------------------------------------------------
// check if value of x, y, z is correct. If not, error will be counted.
// -------------------------------------------------------------------------------------
if(vectorA.getx()!=4.0||vectorA.gety()!=4.0||vectorA.getz()!=4.0)
{
        errors++;
}
std::cout<<"--expected value: (4.0,4.0,4.0)"<<std::endl;
std::cout<<"--test results: ("<<vectorA.getx()<<","<<vectorA.gety()<<","<<vectorA.getz()<<")"<<std::endl;
std::cout<<"--errors count: "<<errors<<std::endl;
std::cout<<""<<std::endl;
// -------------------------------------------------------------------------------------	
// Subtraction
// -------------------------------------------------------------------------------------
std::cout<<"Subtraction"<<std::endl;
Vector3D vectorB = vector1 - vector2;
// -------------------------------------------------------------------------------------
// check if value of x, y, z is correct. If not, error will be counted.
// -------------------------------------------------------------------------------------
if(vectorB.getx()!=(-2.0)||vectorB.gety()!=(0.0)||vectorB.getz()!=2.0)
{
     errors++;
}
std::cout<<"--expected value: (-2.0,0.0,2.0)"<<std::endl;
std::cout<<"--test results: ("<<vectorB.getx()<<","<<vectorB.gety()<<","<<vectorB.getz()<<")"<<std::endl;
std::cout<<"--errors count: "<<errors<<std::endl;
std::cout<<""<<std::endl;
// -------------------------------------------------------------------------------------	
// Dot product
// -------------------------------------------------------------------------------------
std::cout<<"Dot Product"<<std::endl;
double vectorC = vector1*vector2;
if(vectorC != 217)
{
        errors++;
}
std::cout<<"--expected value: 217"<<std::endl;
std::cout<<"--test results: "<<vectorC<<std::endl;
std::cout<<"--errors count: "<<errors<<std::endl;
std::cout<<""<<std::endl;
// -------------------------------------------------------------------------------------	
// Cross product
// -------------------------------------------------------------------------------------
std::cout<<"Cross Product"<<std::endl;
Vector3D vectorD = vector1.cross_product(vector2);
if(vectorD.getx()!=(-166.0)||vectorD.gety()!=128.0||vectorD.getz()!=(-6.0))
{
       errors++;
}
std::cout<<"--expected value: (-166.0,128.0,-6.0)"<<std::endl;
std::cout<<"--test results: ("<<vectorD.getx()<<","<<vectorD.gety()<<","<<vectorD.getz()<<")"<<std::endl;
std::cout<<"--errors count: "<<errors<<std::endl;
std::cout<<""<<std::endl;	
	return (errors==0)? 0:1;
   
}











