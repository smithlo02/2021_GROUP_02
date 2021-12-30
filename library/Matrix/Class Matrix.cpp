
#include "Matrix class.h by Tan.h"
#include "Vector3D.h from Shiyu.h"


#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846



Matrix::Matrix() {

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            if (row == col) {

                this->MatrixArray[row][col] = 1;
            }
            else {

                this->MatrixArray[row][col] = 0;
            }
        }
    }
    return;
}

// -------------------------------------------------------------------------------------------------
// Constructor to input each value in a 3x3 matrix

Matrix::Matrix(double a, double b, double c,double d, double e, double f,double g, double h, double i) {

    double elements[] = { a, b, c, d, e, f, g, h, i };

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            // Each value is set to the appropriate input
            this->MatrixArray[row][col] = elements[(row * 3) + col];

        }
    }

    return;
}
// -------------------------------------------------------------------------------------------------
// Constructor for reflection matrices about each plane

Matrix::Matrix(char Plane) {

    int IndexToReflect;

    // Detect what plane to reflect in
    switch (Plane) {

    case 'x':

        IndexToReflect = 0;
        break;

    case 'y': 

        IndexToReflect = 1;
        break;

    case 'z': 

        IndexToReflect = 2;
        break;
    }

    unsigned row, col;

    // Set up Identity matrix
    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            if (row == col) {

                this->MatrixArray[row][col] = 1;

            }
            else {

                this->MatrixArray[row][col] = 0;

            }

        }
    }


    if (IndexToReflect != -1) {

        this->MatrixArray[IndexToReflect][IndexToReflect] = -1;

    }

    return;

}

// -------------------------------------------------------------------------------------------------
// Matrix copy constructor

Matrix::Matrix(const Matrix& Mat) {

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            this->MatrixArray[row][col] = Mat.MatrixArray[row][col];

        }

    }

    return;

}



// -------------------------------------------------------------------------------------------------
// Matrix assignment operator

Matrix& Matrix::operator=(const Matrix& Mat) {

    if (&Mat == this) return(*this);

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            this->MatrixArray[row][col] = Mat.MatrixArray[row][col];

        }

    }

    return(*this);

}



// -------------------------------------------------------------------------------------------------
// Matrix addition operator to add 2 matrices

Matrix Matrix::operator+(const Matrix& Mat)
{
    Matrix AddMat;

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            // Declare Value and pass a pointer so GetElement can update its value
            double Value;
            Mat.GetElement(row, col, &Value);

            // Each value is set to the appropriate input
            AddMat.SetElement(row, col, this->MatrixArray[row][col] + Value);

        }
    }

    return AddMat;
}



// -------------------------------------------------------------------------------------------------
// Matrix subtraction operator to subtract 2 matrices

Matrix Matrix::operator-(const Matrix& Mat)
{
    Matrix SubMat;

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            // Declare Value and pass a pointer so GetElement can update its value
            double Value;
            Mat.GetElement(row, col, &Value);

            // Each value is set to the appropriate input
            SubMat.SetElement(row, col, this->MatrixArray[row][col] - Value);

        }
    }

    return SubMat;
}



// -------------------------------------------------------------------------------------------------
// Matrix multiplication operator (with another 3x3 matix)

Matrix Matrix::operator*(const Matrix& Mat)
{
    Matrix MultMat;

    unsigned i, j, k;

    double temp = 0.0;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            temp = 0.0;

            for (k = 0; k < 3; k++) {

                // Declare Value and pass a pointer so GetElement can update its value
                double Value;
                Mat.GetElement(k, j, &Value);

                temp += this->MatrixArray[i][k] * Value;

            }

            MultMat.SetElement(i, j, temp);

        }

    }

    return MultMat;

}



// -------------------------------------------------------------------------------------------------
// Matrix multiplication operator (with vector)

Vector3D Matrix::operator*(const Vector3D& Vec)
{
    Vector3D MultVec;

    double TempVecArray[3];

    unsigned row;

    for (row = 0; row < 3; row++) {

        // Multiple each vector point by each column of matrix and add values
        double TempValue = (Vec.X_coordinate* this->MatrixArray[row][0]
            + Vec.Y_coordinate * this->MatrixArray[row][1]
            + Vec.Z_coordinate * this->MatrixArray[row][2]);

        TempVecArray[row] = TempValue;

    }

    // Assign each value of the array to the correct vector variable
    MultVec.X_coordinate = TempVecArray[0];
    MultVec.Y_coordinate= TempVecArray[1];
    MultVec.Z_coordinate = TempVecArray[2];

    return MultVec;
}


// -------------------------------------------------------------------------------------------------
// Matrix multiplication operator (with a scalar value)

Matrix Matrix::operator*(double Scalar)
{
    Matrix MultMat;

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            MultMat.SetElement(row, col, this->MatrixArray[row][col] * Scalar);

        }

    }

    return MultMat;
}



// -------------------------------------------------------------------------------------------------
// Matrix inverse function

Matrix Matrix::Inverse()
{

    // Error check to make sure the matrix is not singular i.e. Determinant = 0
    double Det = this->Determinant();


    // If the matrix is singular the identity matrix is returned
    if (Det == 0)
    {
        // Identity matrix
        Matrix Mat;

        return Mat;
    }


    
    Matrix InverseMat((this->MatrixArray[1][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][1])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][1]));




    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            if ((((row * 3) + col) % 2) == 1) {

                // Declare Value and pass a pointer so GetElement can update its value
                double Value;
                InverseMat.GetElement(row, col, &Value);

                InverseMat.SetElement(row, col, (Value * -1));

            }

        }
    }

    // Transpose the matrix
    InverseMat = InverseMat.Transpose();

    // Divide by the determinant
    InverseMat = InverseMat * ((double)1 / Det);

    return InverseMat;

}



// -------------------------------------------------------------------------------------------------
// Matrix transpose function

Matrix Matrix::Transpose()
{
    Matrix TransposeMat;

    unsigned row, col;

    for (row = 0; row < 3; row++) {

        for (col = 0; col < 3; col++) {

            TransposeMat.SetElement(row, col, this->MatrixArray[col][row]);

        }

    }

    return TransposeMat;

}
// -------------------------------------------------------------------------------------------------
// Converts matrix to rotation matrix about the x-axis







