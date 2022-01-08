#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

// -------------------------------------------------------------------------------------------------
// Matrix.h
// -------------------------------------------------------------------------------------------------
//
// Creator: Steven Elliott
// Date: Last Updated 13/01/20
//
// Description: Matrix class header file for model loading library.
//
// -------------------------------------------------------------------------------------------------

// Include Vector3D class 
#include "Vector3D2.h"

// Declares the use of the class
class Vector3D;

class Matrix {

private:


	double MatrixArray[3][3];





public:



	Matrix();


	Matrix(double a, double b, double c,double d, double e, double f,double g, double h, double i);



	

	Matrix(const Matrix& Mat);
	Matrix& operator=(const Matrix& Mat);
	~Matrix();

	Matrix operator+(const Matrix& Mat);

	Matrix operator-(const Matrix& Mat);

	Matrix operator*(const Matrix& Mat);

	Vector3D operator*(const Vector3D& Vec);
	Matrix operator*(double Scalar);

	Matrix Inverse();

	Matrix Transpose();
	void RotateX(double Theta);

	void RotateY(double Theta);

	void RotateZ(double Theta);
	void SetMatrix();

	void OutputMatrix();



};


#endif // MATRIX_H_INCLUDED
